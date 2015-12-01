//------------------------------------------------------------------
// Simple Testbench for dual toggle flipflop 
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>
#include "tff.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> din, dout1, dout2;

    sc_clock clk("clk",10,SC_NS,0.5,10,SC_NS,false);    // Create a clock signal
    
    tff DUT("tff");                     // Instantiate Device Under Test

    DUT.dout1(dout1);
    DUT.dout2(dout2);
    DUT.clk(clk);

    sc_trace_file *fp;                  // Create VCD file
    fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file

    fp->set_time_unit(100, SC_PS);      // set tracing resolution to ns
    sc_trace(fp,clk,"clk");             // Add signals to trace file
    sc_trace(fp,dout1,"dout1");
    sc_trace(fp,dout2,"dout2");
    sc_trace(fp,DUT.sig1,"sig1");
    sc_trace(fp,DUT.var2,"var2");

    sc_start(100, SC_NS);               // Run simulation

    sc_close_vcd_trace_file(fp);        // close(fp)

    return 0;
}
