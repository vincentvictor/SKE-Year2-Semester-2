
#ifndef STIM_H
#define STIM_H

#include "systemc.h"

SC_MODULE(stim) {
	sc_in_clk clk;
	sc_out<bool> reset, go_i;
	sc_out<sc_uint<16> > x, y;

	void ps1() {
		wait();
		wait();

		//test 1
		reset.write(true);
		x.write(5);
		y.write(8);
		go_i.write(true);
		wait(5, SC_NS); //half wave
		go_i.write(false);
		wait();

		//test 2
		reset.write(true);
		x.write(15);
		y.write(3);
		go_i.write(true);
		wait(5, SC_NS); //half wave
		go_i.write(false);
		wait();

		//test 3
		reset.write(true);
		x.write(30);
		y.write(20);
		go_i.write(true);
		wait(5, SC_NS); //half wave
		go_i.write(false);
		wait();

		wait();
		wait();
	}

	SC_CTOR(stim) {
		SC_THREAD(ps1);
		sensitive << clk.pos();
	}


};
#endif