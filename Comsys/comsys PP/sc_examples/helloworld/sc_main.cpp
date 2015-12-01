//------------------------------------------------------------------
// Simple Testbench for dff flipflop file
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>
#include "dff.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<sc_logic> din, dout;      // Local signals

    sc_clock clk("clk",10,SC_NS,0.5);   // Create a clock signal

    dff DUT("dff");                     // Instantiate Device Under Test

    DUT.din(din);                       // Connect ports
    DUT.dout(dout);
    DUT.clk(clk);

    sc_trace_file *fp;                  // Create VCD file
    fp=sc_create_vcd_trace_file("wave");
    fp->set_time_unit(100, SC_PS);      // set tracing resolution to ns
    sc_trace(fp,clk,"clk");             // Add signals to trace file
    sc_trace(fp,din,"din");
    sc_trace(fp,dout,"dout");
    
    din=SC_LOGIC_0;
    sc_start(31, SC_NS);                // Run simulation
    din=SC_LOGIC_1;                         
    sc_start(31, SC_NS);                // Run simulation
    din=SC_LOGIC_0;                         
    sc_start(31, SC_NS);                // Run simulation

    sc_close_vcd_trace_file(fp);        // close(fp)

    return 0;                           // Return no errors
}
