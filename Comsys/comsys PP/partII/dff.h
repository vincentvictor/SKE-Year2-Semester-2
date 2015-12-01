// SystemC FlipFlop using SC_CTHREAD
#ifndef DFF_H
#define DFF_H

#include <systemc.h>

SC_MODULE(dff) {
	sc_in<bool > clk;
	sc_in<bool > din;
	sc_out<bool > dout;
	sc_in<bool> enable; // enable =1, to use it
	sc_in<bool> rw; // rw=0 (read), rw=1 (write)
	sc_in<bool> clr; // clr=0; reg is clear to 0; 
	bool a; //temp value

	void p1() {
		while(true)
		{
			if (enable.read() == true) {
				if (rw.read() == false) {
					dout.write(a); // this is for reading only
				}
				// for writing, din is the input for saving value to the register.
				else {
					a = din.read();
				}
				if (clr.read() == false)
					a = false; //reset a
			}
			// cout << a; 
			wait();
		}
	}

	SC_CTOR(dff) {
		SC_CTHREAD(p1,clk.pos());
		sensitive << clk.pos();
	}

};
#endif