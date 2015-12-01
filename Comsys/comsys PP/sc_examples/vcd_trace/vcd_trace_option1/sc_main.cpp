//------------------------------------------------------------------
// Simple Testbench for dff flipflop 
//
// Tracing performed locally in dff.h, pass on filepointer to dff module.
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>
#include "dff.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> din, dout;

    sc_clock clk("clk",10,SC_NS,0.5);   // Create a clock signal

    sc_trace_file *fp;                  // Declare VCD filepointer
    fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
    fp->set_time_unit(100, SC_PS);      // set tracing resolution to ns


    dff DUT("dff",fp);                  // Instantiate Device Under Test
                                        // Pass on filepointer

    DUT.din(din);                       // Connect ports
    DUT.dout(dout);
    DUT.clk(clk);

    sc_start(31, SC_NS);                // Run simulation
    din=true;                           
    sc_start(31, SC_NS);                // Run simulation
    din=false;                          
    sc_start(31, SC_NS);                // Run simulation

    sc_close_vcd_trace_file(fp);        // close(fp)

    return 0;
}
