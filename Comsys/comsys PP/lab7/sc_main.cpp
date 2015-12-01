#include "reg.h"
#include "stim.h"
#include "datapath.h"
#include "adder.h"
#include <systemc.h>

sc_trace_file *fp = sc_create_vcd_trace_file("wave");// Create wave.vcd file

int sc_main(int argc, char* argv[]) {

    sc_clock clk("clk",10,SC_NS);
    sc_signal<bool> enable, rw, clr, ci, co, zflag, oflag;
    sc_signal<sc_uint<16> > din0, din1, dout2;
    sc_signal<sc_uint<4> > op;

    sc_trace(fp,clk,"clk");             // Add signals to trace file
    sc_trace(fp,enable,"enable");
    sc_trace(fp,rw,"rw");
    sc_trace(fp,clr,"clr");
    sc_trace(fp,ci,"ci");
    sc_trace(fp,co,"co");
    sc_trace(fp,zflag,"zflag");
    sc_trace(fp,oflag,"oflag");
    sc_trace(fp,din0,"din0");
    sc_trace(fp,din1,"din1");
    sc_trace(fp,dout2,"dout2");
    sc_trace(fp,op,"op");

    //datapath
    datapath DATAPATH("datapath");
    DATAPATH.enable(enable);
    DATAPATH.rw(rw);
    DATAPATH.clk(clk);
    DATAPATH.clr(clr);
    DATAPATH.din0(din0);
    DATAPATH.din1(din1);
    DATAPATH.dout2(dout2);
    DATAPATH.ci(ci);
    DATAPATH.co(co);
    DATAPATH.zflag(zflag);
    DATAPATH.oflag(oflag);
    DATAPATH.op(op);

    //stim
    stim STIM("stim");
    STIM.clk(clk);
    STIM.enable(enable);
    STIM.rw(rw);
    STIM.clr(clr);
    STIM.din0(din0);
    STIM.din1(din1);
    STIM.ci(ci);
    STIM.op(op);
     
    sc_start(1000, SC_NS);   //start simulation
               
    sc_close_vcd_trace_file(fp);        // close wave.vcd
    return 0;                           // Return OK, no errors.
}  