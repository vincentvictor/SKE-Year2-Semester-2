//------------------------------------------------------------------
// Simple sc_clock Test
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>

int sc_main(int argc, char* argv[])
{

    sc_clock clk1("clk1", 10,SC_NS);       // Create a 100MHz clock signal
    sc_clock clk2("clk2", 10,SC_NS, 0.5, 0,SC_NS, true);       // Same as clk1, default values
    sc_clock clk3("clk3", 5,SC_NS, 0.25);   // Create a 200MHz clock signal with a 25% duty cycle
    sc_clock clk4("clk4", 5,SC_NS, 0.25, 3,SC_NS, false); // Same as clk2 but the first falling edge starts at 3 ns
    sc_clock clk5("clk5", 5,SC_NS, 0.25, 3,SC_NS, true);  // Same as clk2 but the first rising edge starts at 3 ns


    sc_trace_file *fp;                  // Create VCD file
    fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
    fp->set_time_unit(100, SC_PS);      // set tracing resolution to ns

    sc_trace(fp,clk1,"clk1");               
    sc_trace(fp,clk2,"clk2");               
    sc_trace(fp,clk3,"clk3");               
    sc_trace(fp,clk4,"clk4");
    sc_trace(fp,clk5,"clk5");               
                    

    sc_start(25, SC_NS);                // Run simulation
    sc_close_vcd_trace_file(fp);        // close(fp)

    return 0;                           // Return OK, no errors.
}
