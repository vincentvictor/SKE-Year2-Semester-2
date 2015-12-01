//------------------------------------------------------------------
// Simple Testbench for dff flipflop file
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>
#include "delta.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> din, dout;

    sc_clock clk("clk",10,SC_NS,0.5,0, SC_NS,false);    // Create a clock signal
    
    delta DUT("delta");             // Instantiate Device Under Test

    DUT.din(din);                       // Connect ports
    DUT.dout(dout);
    DUT.clk(clk);

    sc_trace_file *fp;                  // Create VCD file
    fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
    fp->set_time_unit(100, SC_PS);      // set tracing resolution to ns
    sc_trace(fp,clk,"clk");             // Add signals to trace file
    sc_trace(fp,DUT.q_s,"q_s");
    sc_trace(fp,din,"din");

    sc_trace(fp,dout,"dout");

    sc_start(31, SC_NS);                // Run simulation
    din=true;                           
    sc_start(31, SC_NS);                // Run simulation
    din=false;                          
    sc_start(31, SC_NS);                // Run simulation

    sc_close_vcd_trace_file(fp);        // close(fp)

    return 0;
}
