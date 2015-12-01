#ifndef LCM_H
#define LCM_H

#include <systemc.h>

SC_MODULE(lcm) {
	sc_in_clk clk;
	sc_in<bool> reset, go_i;
	sc_in<sc_uint<16> > x_i, y_i;
	sc_out<bool> done_o;
	sc_out<sc_uint<16> > r_o;

	void p1() {
		if (reset.read() == true) {
			//reset values
			done_o.write(false);
			r_o.write(0);
		}
		if (go_i.read() == true) { //ready to do
			int x = x_i.read(), y = y_i.read();
			int mulx = 1; //x multiplier
			int muly = 1; //y multiplier
			// doing LCM
			while(x*mulx != y*muly) {
				if (x*mulx < y*muly) {
					mulx++;
				} else if (x*mulx > y*muly) {
					muly++;
				}
			}
			int r = x*mulx; //record result
			done_o.write(true);
			r_o.write(r); //write result
			cout << "lcm: (" << x << "," << y << ") = " << r << endl;
		} 
	}

	SC_CTOR(lcm) {
		SC_METHOD(p1);
		sensitive << clk << x_i << y_i;
	}
};
#endif