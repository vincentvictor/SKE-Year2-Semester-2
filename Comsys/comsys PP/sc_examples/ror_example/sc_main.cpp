//------------------------------------------------------------------
// Simple Testbench for Rotate Right + swap nibble  
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>
#include "ror.h"

int sc_main(int argc, char* argv[])
{
   //   sc_signal<sc_lv<8> > din, dout1, dout2;
    sc_signal<sc_uint<8> > din, dout1, dout2;

    sc_clock clk("clk",10,SC_NS,0.5,10,SC_NS,false);    // Create a clock signal
    
    ror DUT("ror");                     // Instantiate Device Under Test

    DUT.din(din);
    DUT.dout1(dout1);
    DUT.dout2(dout2);
    DUT.clk(clk);

    sc_trace_file *fp;                  // Create VCD file
    fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
    fp->set_time_unit(100, SC_PS);      // set tracing resolution to ns

    sc_trace(fp,clk,"clk");             // Add signals to trace file
    sc_trace(fp,din,"din");             
    sc_trace(fp,dout1,"dout1");
    sc_trace(fp,dout2,"dout2");

    din=0;
    sc_start(20, SC_NS);                // Run simulation
    din=0x01;                           
    sc_start(20, SC_NS);                // Run simulation
    din=0xC3;                           
    sc_start(20, SC_NS);                // Run simulation
    din=0x0F;                           
    sc_start(20, SC_NS);                // Run simulation

    sc_close_vcd_trace_file(fp);        // close(fp)

    return 0;
}
