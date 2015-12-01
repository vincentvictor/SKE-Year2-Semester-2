#ifndef CONV_H
#define CONV_H

#include <systemc.h>
#include <math.h>
#include <bitset>

SC_MODULE(conv) {
	sc_in<float> a;
	sc_out<sc_uint<32> > o; //0 00000000 00000000000000000000000 1 8 23

	void convert() {
		//exponent
		int e = exceed(a) + 127;
		//mantissa
		float m = a.read()/pow(2, exceed(a));
		//sign
		int s;
		if (a > 0) s = 0;
		else s =1;

		//convert to binary
		toBinary(s, e, m);
	}

	int exceed(float a) {
		//max(2^x) < a
		int i = 0;
		while(pow(2,i) < a) {
			i++;
		}
		return --i;
	}

	void toBinary(int s, int e, float m) {
		sc_uint<1> sB = s;
		sc_uint<8> eB = e;
		cout << "float: " << a.read() << endl;

		//converting mantissa
		m = m-1;
		sc_uint<23> mB = 0;
		int i = 22;
	    do {
	    	m*=2;
	    	if (m-1 >= 0 && m-1 < 1) {
				mB[i--] = 1;
				m -= 1;
	    	}
			else
				mB[i--] = 0;
	    } while(m != 0 && i > 0);

	    //concat all
	    sc_uint<9> seB = (s, e);
	    sc_uint<32> out = (seB, mB);

	    //write port
	    o.write(out);
	}

	SC_CTOR(conv) {
		SC_METHOD(convert);
		sensitive << a;
	}
};
#endif