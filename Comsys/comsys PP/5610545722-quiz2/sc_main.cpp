#include "modulo.h"
#include "stim.h"
#include <systemc.h>

sc_trace_file *fp = sc_create_vcd_trace_file("wave");

int sc_main(int argc, char* argv[]) {
	sc_clock clk("clk",10,SC_NS);
	sc_signal<bool> reset, go_i;
	sc_signal<sc_uint<16> > x, y, z;

	sc_trace(fp,clk,"clk");
	sc_trace(fp,reset,"reset");
	sc_trace(fp,go_i,"go_i");
	sc_trace(fp,x,"x");
	sc_trace(fp,y,"y");
	sc_trace(fp,z,"z");

	modulo MODULO("modulo");
	MODULO.clk(clk);
	MODULO.reset(reset);
	MODULO.go_i(go_i);
	MODULO.x(x);
	MODULO.y(y);
	MODULO.z(z);

	stim STIM("stim");
	STIM.clk(clk);
	STIM.reset(reset);
	STIM.go_i(go_i);
	STIM.x(x);
	STIM.y(y);

	sc_start(1000, SC_NS);   //start simulation
               
    sc_close_vcd_trace_file(fp);        // close wave.vcd
    return 0;                           // Return OK, no errors.
}