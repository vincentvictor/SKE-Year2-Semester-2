#ifndef DATAPATH_H
#define DATAPATH_H

#include "adder.h"
#include <systemc.h>

extern sc_trace_file *fp;// Create wave.vcd file

SC_MODULE(datapath) {

	//reg
	sc_in<bool> enable;
	sc_in<bool> rw;
	sc_in<bool >  clk;
    sc_in<bool >  clr;
    sc_in<sc_uint<16> >  din0;
    sc_in<sc_uint<16> >  din1;
    sc_signal<sc_uint<16> > dout0;
    sc_signal<sc_uint<16> > dout1;
    sc_signal<sc_uint<16> > din2;
    sc_out<sc_uint<16> > dout2;
    //adder
    sc_in<bool> ci;
    sc_out<bool> co;
    sc_out<bool> zflag, oflag;
    sc_in<sc_uint<4> > op;

	//input
	reg reg0;	
	reg reg1;
	//output	
	reg reg2;
	//adder
	adder adder;

	void p1() {
		cout << "answer : " << dout2 << endl;
		cout << endl;
	}


	SC_CTOR(datapath) : reg0("reg0"), reg1("reg1"), reg2("reg2"), adder("adder") {
		sc_trace(fp,dout0,"dout0");
	    sc_trace(fp,dout1,"dout1");
	    sc_trace(fp,din2,"din2");

		//port binding
		reg0.enable(enable);	reg0.rw(rw);
		reg0.clk(clk);			reg0.clr(clr);
		reg0.din(din0);			reg0.dout(dout0);

		reg1.enable(enable);	reg1.rw(rw);
		reg1.clk(clk);			reg1.clr(clr);
		reg1.din(din1);			reg1.dout(dout1);

		reg2.enable(enable);	reg2.rw(rw);
		reg2.clk(clk);			reg2.clr(clr);
		reg2.din(din2);			reg2.dout(dout2);

		adder.result(din2);		adder.ain(dout0);
		adder.bin(dout1);		adder.ci(ci);
		adder.co(co);			adder.zflag(zflag);
		adder.oflag(oflag);		adder.op(op);

		SC_METHOD(p1);
		sensitive << dout2;


	}

};
#endif