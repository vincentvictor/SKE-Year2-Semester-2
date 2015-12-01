#include <systemc.h>
#include "mul.h"
#include "stim.h"

int sc_main(int argc, char* argv[]) {
	sc_signal<sc_uint<16> > a, b;
	sc_signal<sc_uint<32> > c;
	sc_signal<bool> rst;

	sc_clock clk("clk",10,SC_NS,0.5);   // Create a clock signal
	
	mul DUT("mul");
	DUT.clk(clk);
	DUT.rst(rst);
	DUT.a(a);
	DUT.b(b);
	DUT.c(c);

	stim STIM("STIM");
	STIM.clk(clk);
	STIM.rst(rst);
	STIM.a(a);
	STIM.b(b);

	sc_start(100, SC_NS);
	return 0;
}
