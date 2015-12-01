//------------------------------------------------------------------
// Simple Testbench for 4-bits adder file
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>
#include <stim.h>
#include <datapath.h>

int sc_main(int argc, char* argv[])
{
    sc_signal<sc_uint<32> > fout_s;
    sc_signal<float> fin1 , fin2;
    sc_clock clk("clk", 10, SC_NS, 0.5);   		// Create a clock signal
    
    Dtp Datapath("Datapath");
    Datapath.fin1(fin1);
    Datapath.fin2(fin2);
    Datapath.fout_s(fout_s);
    
    sc_trace_file *fp;                          // Declare FilePointer fp
    fp=sc_create_vcd_trace_file("wave");        
   
    sc_trace(fp, clk, "clk");                     // Add signals to trace file
    sc_trace(fp, fin1, "fin1");
    sc_trace(fp, fin2, "fin2");
    sc_trace(fp, fout_s, "fout_s");
    
    Stim STIM("stimulus");              		// Instantiate stimulus generator
    STIM.clk(clk);  
    STIM.fin1(fin1);
    STIM.fin2(fin2);
    STIM.fout_s(fout_s);
 

    sc_start(100, SC_NS);              			// Run simulation
    sc_close_vcd_trace_file(fp); 
    return 0;                           		// Return OK, no errors.
}
