//------------------------------------------------------------------
// Simple flipflop with local VCD file creation and sc_trace 
//
// Note sc_trace called in SC_THREAD process
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>       
                                
SC_MODULE(dff) {
    sc_in<bool > clk;
    sc_in<bool > din;
    sc_out<bool > dout;
    
    sc_trace_file *fp;                      // Declare Local VCD filepointer

    void p1() { 
    
        fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
        //fp->set_time_unit(100, SC_PS);    // set tracing resolution to ns
        fp->delta_cycles(true);             // Trace delta cycles

        sc_trace(fp,clk,"clk");             // Add signals during construction
        sc_trace(fp,din,"din"); 
        sc_trace(fp,dout,"dout");
        
        fp->write_comment("Trace Option 3");// Add some comments to VCD the file

        wait();
        dout.write(din.read());
        wait();
        dout.write(din.read());
        wait();
        dout.write(din.read());
        wait();
        
    }
    

    SC_CTOR(dff) {
        SC_THREAD(p1);                      // Run p1 only ones
        sensitive << clk.pos();
    }

    ~dff() {
        sc_close_vcd_trace_file(fp);        // close(fp)
    }

};

