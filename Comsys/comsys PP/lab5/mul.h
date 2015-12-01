#include <systemc.h>
using namespace std;

SC_MODULE(mul) {
	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_in< sc_uint<16> > a;		//M
	sc_in< sc_uint<16> > b;		//Q
	sc_uint<16> tempB;
	sc_out< sc_uint<32> > c;	//A
	sc_uint<16> answer; //temp answer
	bool co = 0; //carry

    bool fulladder(bool a, bool b, bool cif, bool& cof) {
        bool sumr;
        sumr =(a ^ b) ^ cif;
        cof=(a & b) | ((a ^ b) & cif);      
        return sumr;    
    }

	void multiply() {

		while (true) {
			//Reset
			c.write(0);
			wait();

			//Algorithm
			tempB = b.read();
			cout << "A : " << a.read() << endl;
			cout << "B : " << tempB << endl;
			int i;
			for (i = 0 ; i < 16 ; i++) {
				//add if first bit of Q is 1
				if (tempB[0] == 1) {
					int j;
			        for (j = 0 ; j < 16 ; j++) {
			            answer[j] = fulladder(answer[j], a.read()[j], co, co);
			        }
				}

				//right shift
				tempB = tempB >> 1;
				tempB[15] = answer[0]; //last bit of Q = first bit of A
				answer = answer >> 1;
				answer[15] = co;

				//reset carry (shift)
				if (co == 1) {
					co = 0;
				}

				//print out each turn
				bitset<16> x(answer);
				bitset<16> y(tempB);
				bitset<16> z(a.read()); 
				cout << co << " " << x << " " << y << " " << z << endl;
			}

			//concat
			sc_uint<32> ra;
			for (i = 0 ; i < 32 ; i++) {
				if (i < 16)
					ra[i] = tempB[i];
				else
					ra[i] = answer[i-16];
			}
			//print out
			cout << a.read() << " * " << b.read() << " = " << ra << endl;
			wait();
		}
	}

	SC_CTOR(mul) {
		// SC_CTHREAD(multiply, clk.pos());
		SC_THREAD(multiply);
		reset_signal_is(rst, true);
		sensitive << a << b << clk.pos();
	}

};

