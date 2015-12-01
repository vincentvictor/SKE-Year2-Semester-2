#include "reg.h"
#include "stim.h"
#include <systemc.h>

int sc_main(int argc, char* argv[]) {

    sc_signal<bool> enable, rw, clr;
    sc_clock clk("clk",10,SC_NS);
    sc_signal<sc_uint<32> > din, dout;

    sc_trace_file *fp;                  // VCD filepointer
    fp=sc_create_vcd_trace_file("wave");// Create wave.vcd file
    sc_trace(fp,clk,"clk");             // Add signals to trace file
    sc_trace(fp,enable,"enable");
    sc_trace(fp,rw,"rw");
    sc_trace(fp,clr,"clr");
    sc_trace(fp,din,"din");
    sc_trace(fp,dout,"dout");

    //register
    reg REG("reg");
    REG.clk(clk);
    REG.enable(enable);
    REG.rw(rw);    
    REG.clr(clr);
    REG.din(din); 
    REG.dout(dout);

    //stim
    stim STIM("stim");
    STIM.clk(clk);
    STIM.enable(enable);
    STIM.rw(rw);
    STIM.clr(clr);
    STIM.din(din);
     
    sc_start(1000, SC_NS);   //start simulation
               
    sc_close_vcd_trace_file(fp);        // close wave.vcd
    return 0;                           // Return OK, no errors.
}  