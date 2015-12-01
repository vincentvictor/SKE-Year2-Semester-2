#include <systemc.h>
#include "stim.h"
#include "conv.h"
#include "fpadder.h"

sc_trace_file *fp = sc_create_vcd_trace_file("wave");// Create wave.vcd file

int sc_main(int argc, char* argv[]) {
	sc_clock clk("clk",10,SC_NS);

	sc_signal<float> a;
	sc_signal<float> b;
	sc_signal<sc_uint<32> > sum;

	sc_trace(fp,clk,"clk"); 
	sc_trace(fp,a,"a"); 
	sc_trace(fp,b,"b");
	sc_trace(fp,sum,"sum");

	fpadder FPADDER("fpadder");
	FPADDER.clk(clk);
	FPADDER.a(a);
	FPADDER.b(b);
	FPADDER.sum(sum);

	stim STIM("stim");
	STIM.clk(clk);
	STIM.a(a);
	STIM.b(b);

	sc_start(1000, SC_NS);   //start simulation

	sc_close_vcd_trace_file(fp);        // close wave.vcd
    return 0;                           // Return OK, no errors.
}