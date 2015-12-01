#ifndef FPADDER_H
#define FPADDER_H

#include <systemc.h>
#include "conv.h"
#include "add.h"

SC_MODULE(fpadder) {
	sc_in<bool> clk;
	sc_in<float> a;
	sc_in<float> b;

	sc_out<sc_uint<32> > sum;

	sc_signal<sc_uint<32> > o1;
	sc_signal<sc_uint<32> > o2;

	conv conv1;
	conv conv2;

	add adder;

	SC_CTOR(fpadder) : conv1("conv1"), conv2("conv2"), adder("adder") {
		conv1.a(a);
		conv1.o(o1);

		conv2.a(b);
		conv2.o(o2);

		adder.clk(clk);
		adder.a(o1);
		adder.b(o2);
		adder.sum(sum);
	}
};
#endif