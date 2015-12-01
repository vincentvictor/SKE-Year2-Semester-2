//------------------------------------------------------------------
// Simple flipflop with local sc_trace 
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>       
                                
SC_MODULE(dff) {
    sc_in<bool > clk;
    sc_in<bool > din;
    sc_out<bool > dout;

    sc_trace_file *fp;          // Declare Local VCD filepointer

    void p1() {                                                           
        dout.write(din.read()); 
    }

    dff(sc_module_name _n, sc_trace_file* _fp) : sc_module(_n), fp(_fp) {
        SC_METHOD(p1);
        sensitive << clk.pos();

        sc_trace(fp,clk,"clk"); // Add signals during construction
        sc_trace(fp,din,"din"); 
        sc_trace(fp,dout,"dout");
    }

    SC_HAS_PROCESS(dff);        // Required
};

