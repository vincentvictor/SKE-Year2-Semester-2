#ifndef STIM_H
#define STIM_H

#include "systemc.h"
                                
SC_MODULE(stim) {
    //reg
    sc_out<bool> enable;
    sc_out<bool> rw;
    sc_in<bool >  clk;
    sc_out<bool >  clr;
    sc_out<sc_uint<16> >  din0;
    sc_out<sc_uint<16> >  din1;
    //adder
    sc_out<bool> ci;
    sc_out<sc_uint<4> > op;

    void ps1() {    
        //2 waits for passing the value
        wait();
        wait();

        //first clear
        clr.write(0);
        wait();

        // wait(9, SC_NS);
        //3+7
        clr.write(1);
        enable.write(1);
        rw.write(0);
        din0.write(3);
        din1.write(7);
        ci.write(0);
        op.write(0);
        wait();
        wait();
        wait();
        wait();
        // wait(9, SC_NS);

        //7 && 12
        enable.write(1);
        rw.write(0);
        din0.write(7);
        din1.write(12);
        ci.write(0);
        op.write(3);
        wait();
        wait();
        wait();
        wait();

        enable.write(1);
        rw.write(0);
        din0.write(8);
        din1.write(9);
        ci.write(0);
        op.write(0);
        wait();
        wait();
        wait();
        // sc_stop();  // End simulation
    }

    SC_CTOR(stim) {  
        SC_THREAD(ps1);                     // Run ps1 only ones
        sensitive << clk.pos();
    }
};
#endif