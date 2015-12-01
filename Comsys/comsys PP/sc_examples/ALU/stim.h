#ifndef STIM_H
#define STIM_H

#include <systemc.h>
                                
SC_MODULE(stim) {
    sc_in<bool> clk;
    sc_out<sc_uint<16> > ain, bin;
    sc_out<bool> ci;
    sc_out<sc_uint<4> > op;

    void ps1() {    
        //+
        ain.write("0b0000000000000100");
        bin.write("0b0000000000000011");
        ci.write(false);
        op.write("0b0000");
        wait();

        //-
        ain.write("0b0000000000000100");
        bin.write("0b0000000000000011");
        ci.write(false);
        op.write("0b0001");
        wait();

        //xor
        ain.write("0b0000000000000100");
        bin.write("0b0000000000000011");
        ci.write(false);
        op.write("0b0010");
        wait();

        //and
        ain.write("0b0000000000000100");
        bin.write("0b0000000000000011");
        ci.write(false);
        op.write("0b0011");
        wait();

        //or
        ain.write("0b0000000000000100");
        bin.write("0b0000000000000011");        
        ci.write(false);
        op.write("0b0100");
        wait();

        //not
        ain.write("0b0000000000000100");
        ci.write(false);
        op.write("0b0101");
        wait();

        //slt
        ain.write("0b0000000000000001");
        bin.write("0b0000000000001111");
        ci.write(false);
        op.write("0b0110");
        wait();
 
        sc_stop();                          // End simulation
    }

    SC_CTOR(stim) {  
        SC_THREAD(ps1);                     // Run ps1 only ones
        sensitive << clk.pos();
    }
};
#endif

