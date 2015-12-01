#ifndef MODULO_H
#define MODULO_H

#include <systemc.h>

//LCM using modulo
SC_MODULE(modulo) {
	sc_in_clk clk;
	sc_in<bool> reset, go_i;
	sc_in<sc_uint<16> > x, y;
	sc_out<sc_uint<16> > z;

	void p1() {
		if (reset == true) {
			//reset values
			z.write(0);
		}
		if (go_i.read() == true) {
			int l = moduloLCM(x.read(), y.read());
			z.write(l);
			cout << "LCM (" << x.read() << ", " << y.read() << ") = " << l << endl;
		}
	}

	int moduloLCM(int a, int b) {
		int max, r;
		max = (a>b) ? a : b;
		while(1) {
			if (max%a == 0 && max%b == 0) {
				r = max;
				break;
			}
			max++;
		}
		return r;
	}

	SC_CTOR(modulo) {
		SC_METHOD(p1);
		sensitive << clk << x << y;
	}
};
#endif
