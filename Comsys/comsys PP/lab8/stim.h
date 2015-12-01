#ifndef STIM_H
#define STIM_H

#include "systemc.h"

SC_MODULE(stim) {
	sc_in<bool> clk;
	sc_out<float> a;
	sc_out<float> b;

	void ps1() {
		wait();
		// wait();

		cout << "*** start from here ***" << endl;
		a.write(6.125);
		b.write(10.0);

		wait();
		wait();
		sc_stop();
	}

	SC_CTOR(stim) {
		SC_THREAD(ps1);
		sensitive << clk.pos();
	}
};
#endif