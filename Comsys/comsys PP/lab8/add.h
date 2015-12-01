#ifndef ADD_H
#define ADD_H

#include <systemc.h>
#include <math.h>
#include <bitset>

SC_MODULE(add) {
	sc_in<bool> clk;
	sc_in<sc_uint<32> > a;
	sc_in<sc_uint<32> > b;
	sc_out<sc_uint<32> > sum;

	//2 inputs components
	sc_uint<1> aS;
	sc_uint<1> bS;
	sc_uint<8> aExp;
	sc_uint<8> bExp;
	sc_uint<23> aMan;
	sc_uint<23> bMan;

	//answer
	sc_uint<1> s;
	sc_uint<8> exp;
	sc_uint<23> man;
	sc_uint<32> temp;

	void getSBit(sc_uint<1> &t, sc_uint<32> x) {
		t[0] = x[31];
		t = 0;
	}

	void getExpBit(sc_uint<8> &t, sc_uint<32> x) {
		int i, j = 30;
		t = 0;
		for (i = 7 ; i >= 0 ; i--, j--) {
			// cout << "x[j] "<< endl;
			t[i] = x[j];
		}
	}

	void getManBit(sc_uint<23> &t, sc_uint<32> x) {
		int i, j = 22;
		t = 0;
		for (i = 22 ; i >= 0 ; i--, j--) {
			t[i] = x[j];
		}
	}

	void normalize(sc_uint<8> &exp, sc_uint<23> &man, int df, bool haveOne) {
		int newExp = exp + df;
		exp = newExp;


		//no shift if = 0
		if (df > 0) {
			if (haveOne) {
				man = man >> 1;
				//reveal hidden bit
				man[22] = 1;
				df--;
				man = man >> df;
			}
			else {
				man = man >> df;
			}
		}
	}

	void p1() {
		//get all components
		//A
		getSBit(aS, a.read());
		getExpBit(aExp, a.read());
		getManBit(aMan, a.read());

		//B
		getSBit(bS, b.read());
		getExpBit(bExp, b.read());
		getManBit(bMan, b.read());

		//exp x - y
		int df = aExp - bExp;
		if (df >= 0) {
			//normalization
			normalize(bExp, bMan, df, true);
		} else {
			//normalization
			df = -1*df;
			normalize(aExp, aMan, df, true);
		}

		//temp init
		exp = aExp;

		//addition
		sc_uint<24> newMan = 0;
		newMan = aMan + bMan;
		man = aMan + bMan;
		if (newMan[23] == 1) { //exceed
			normalize(exp, man, 1, false); //shift 1
		}
		if (df == 0) { //no shift at first
			normalize(exp, man, 1, false); //shift 1
		}


		//concat
		sc_uint<9> t1 = (s, exp);
		sc_uint<32> temp = (t1, man);
		sum.write(temp);

		std::bitset<32> ain(a.read());
		std::bitset<32> bin(b.read());
		std::bitset<32> bss(temp);
		cout << "a:   " << ain << endl;
		cout << "b:   " << bin << endl;
		cout << "ans: " << bss << "\n" << endl;
		

	}

	SC_CTOR(add) {
		SC_METHOD(p1);
		sensitive << a << b ;
	}
};
#endif