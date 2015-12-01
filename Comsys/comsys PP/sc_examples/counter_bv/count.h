//------------------------------------------------------------------
// Simple counter using SystemC sc_bv types 
// 
// SystemC for VHDL engineers
// (c)www.ht-lab.com
//------------------------------------------------------------------


#ifndef COUNT_H
#define COUNT_H

#include <systemc.h>

SC_MODULE(count) {

    sc_in<bool >  clk;
    sc_in<sc_logic >  reset;
    sc_in<sc_logic >  load;
    sc_in<sc_bv<4> >  din;
    sc_out<sc_bv<4> > cout;

    sc_signal<sc_bv<4> > counter_i;

    void process_line23() {
       if ((reset.read() == 1)) {
            counter_i.write(0);
        } else if (clk.posedge()) {
            if ((load.read() == 1)) {
                counter_i.write(din.read().to_uint());
            } else {
                counter_i.write((counter_i.read().to_uint() + 1));
            }   
        }
        cout.write(counter_i.read());
    }


    SC_CTOR(count) {
        SC_METHOD(process_line23);
        sensitive << clk  << reset;
    }

};
#endif
