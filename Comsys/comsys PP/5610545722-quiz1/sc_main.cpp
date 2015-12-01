#include "lcm.h"
#include "stim.h"
#include <systemc.h>

sc_trace_file *fp = sc_create_vcd_trace_file("wave");

int sc_main(int argc, char* argv[]) {
	sc_clock clk("clk",10,SC_NS);
	sc_signal<bool> reset, go_i, done_o;
	sc_signal<sc_uint<16> > x_i, y_i, r_o;

	sc_trace(fp,clk,"clk");
	sc_trace(fp,reset,"reset");
	sc_trace(fp,go_i,"go_i");
	sc_trace(fp,done_o,"done_o");
	sc_trace(fp,x_i,"x_i");
	sc_trace(fp,y_i,"y_i");
	sc_trace(fp,r_o,"r_o");

	lcm LCM("lcm");
	LCM.clk(clk);
	LCM.reset(reset);
	LCM.go_i(go_i);
	LCM.x_i(x_i);
	LCM.y_i(y_i);
	LCM.done_o(done_o);
	LCM.r_o(r_o);

	stim STIM("stim");
	STIM.clk(clk);
	STIM.reset(reset);
	STIM.go_i(go_i);
	STIM.x_i(x_i);
	STIM.y_i(y_i);

	sc_start(1000, SC_NS);   //start simulation
               
    sc_close_vcd_trace_file(fp);        // close wave.vcd
    return 0;                           // Return OK, no errors.
}