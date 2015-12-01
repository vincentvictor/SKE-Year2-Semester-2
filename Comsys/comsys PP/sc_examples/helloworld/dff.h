//------------------------------------------------------------------
// Simple flipflop (Not recommended coding style!)
//   
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------

#include <systemc.h>       
                                
SC_MODULE(dff) {
    sc_in<bool > clk;
    sc_in<sc_logic > din;
    sc_out<sc_logic > dout;
 
    void p1() {
        if (clk.posedge()) {
            dout=din;
         } 
    }
 
    SC_CTOR(dff) {
        SC_METHOD(p1);
        sensitive(clk);
    }

};
