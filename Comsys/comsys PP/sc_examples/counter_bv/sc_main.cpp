//------------------------------------------------------------------
// Simple Testbench for counter.h 
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>
#include "count.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<sc_logic > reset,load;
    sc_signal<sc_bv<4> > din,cout;

    sc_clock clk("clk",10,SC_NS,0.5,10,SC_NS,false);    // Create a clock signal
    
    count DUT("count");             // Instantiate Device Under Test, start at 32

    DUT.clk(clk);
    DUT.reset(reset);
    DUT.load(load);
    DUT.din(din);
    DUT.cout(cout);

    sc_trace_file *fp;                  // Create VCD file
    fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
    fp->set_time_unit(100, SC_PS);      // set tracing resolution to ns
    sc_trace(fp,clk,"clk");             // Add signals to trace file
    sc_trace(fp,reset,"reset");
    sc_trace(fp,load,"load");
    sc_trace(fp,din,"din");
    sc_trace(fp,cout,"cout");

    

    load = SC_LOGIC_0;
    reset = SC_LOGIC_0;
    sc_start(30, SC_NS);                // Run simulation
    reset = SC_LOGIC_1;
    sc_start(20, SC_NS);                // Run simulation
    reset = SC_LOGIC_0;
    sc_start(50, SC_NS);                // Run simulation
    load = SC_LOGIC_1;
    din  = "0010";
    sc_start(20, SC_NS);                // Run simulation wait until rising_edge(clk_s);
    load = SC_LOGIC_0;
    sc_start(60, SC_NS);


    sc_close_vcd_trace_file(fp);        // close(fp)

    return 0;
}
