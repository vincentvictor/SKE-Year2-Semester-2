//------------------------------------------------------------------
// Simple flipflop with local VCD file creation and sc_trace 
// 
// Note sc_trace called in module constructor.
//
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>       
                                
SC_MODULE(dff) {
    sc_in<bool > clk;
    sc_in<bool > din;
    sc_out<bool > dout;

    sc_trace_file *fp;              // Declare Local VCD filepointer

    void p1() {                                                           
        dout.write(din.read()); 
    }

    SC_CTOR(dff) {
        SC_METHOD(p1);
        sensitive << clk.pos();

        fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
        fp->set_time_unit(100, SC_PS);  // set tracing resolution to ns


        sc_trace(fp,clk,"dff.clk");     // Add signals during construction
        sc_trace(fp,din,"dff.din"); 
        sc_trace(fp,dout,"dff.dout");
    }

    ~dff() {
        sc_close_vcd_trace_file(fp);    // close(fp)
    }

};

