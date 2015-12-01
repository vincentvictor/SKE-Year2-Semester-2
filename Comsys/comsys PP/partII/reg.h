#ifndef REG_H
#define REG_H

#include <systemc.h>
#include "dff.h"

SC_MODULE(reg) {
	sc_in<bool> enable;
	sc_in<bool> rw;
	sc_in<bool >  clk;
    sc_in<bool >  clr;
    sc_in<sc_uint<32> >  din;
    sc_out<sc_uint<32> > dout;


    //temp signal ; pretend to be  
    sc_signal<bool > dinBool[32];
    sc_signal<bool > doutBool[32];

    //32 dff boxes
    dff dff0;	dff dff1;
    dff dff2;	dff dff3;
    dff dff4;	dff dff5;
    dff dff6;	dff dff7;
    dff dff8;	dff dff9;
    dff dff10;	dff dff11;
    dff dff12;	dff dff13;
    dff dff14;	dff dff15;
    dff dff16;	dff dff17;
    dff dff18;	dff dff19;
    dff dff20;	dff dff21;
    dff dff22;	dff dff23;
    dff dff24;	dff dff25;
    dff dff26;	dff dff27;
    dff dff28;	dff dff29;
    dff dff30;	dff dff31;
    void changeInput() //change from int -> bool
    {
	    	sc_uint<32> temp = din.read();
	    	for(int i=0;i<32;++i)
	    	{
	    		dinBool[i] = (bool)temp[i];
	    	}
    }

	void changeOutput() //change from bool -> int
    {
	    	sc_uint<32> doutTemp;
	    	for(int i=31 ; i>=0 ; i--)
	    	{
	    		doutTemp[i] = (int)doutBool[i];
	    		cout << doutTemp[i];
	    	}
	    	dout.write(doutTemp);
	    	cout << endl;
	    	cout << "ans : " << doutTemp << endl;
    }

	SC_CTOR(reg) : 
	dff0("dff0"), dff1("dff1"), dff2("dff2"), dff3("dff3"), 
	dff4("dff4"), dff5("dff5"), dff6("dff6"), dff7("dff7"), 
	dff8("dff8"), dff9("dff9"), dff10("dff10"), dff11("dff11"), 
	dff12("dff12"), dff13("dff13"), dff14("dff14"), dff15("dff15"),
	dff16("dff16"), dff17("dff17"), dff18("dff18"), dff19("dff19"),
	dff20("dff20"), dff21("dff21"), dff22("dff22"), dff23("dff23"),
	dff24("dff24"), dff25("dff25"), dff26("dff26"), dff27("dff27"),
	dff28("dff28"), dff29("dff29"), dff30("dff30"), dff31("dff31")	  
	{
		//change the input from int -> bool
		SC_METHOD(changeInput);
		sensitive << din << rw << clr << enable;

		dff0.clk(clk);				dff0.din(dinBool[0]);
		dff0.dout(doutBool[0]);		dff0.enable(enable);
		dff0.rw(rw);				dff0.clr(clr);
	
		dff1.clk(clk);				dff1.din(dinBool[1]);
		dff1.dout(doutBool[1]);		dff1.enable(enable);
		dff1.rw(rw);				dff1.clr(clr);

		dff2.clk(clk);				dff2.din(dinBool[2]);
		dff2.dout(doutBool[2]);		dff2.enable(enable);
		dff2.rw(rw);				dff2.clr(clr);

		dff3.clk(clk);				dff3.din(dinBool[3]);
		dff3.dout(doutBool[3]);		dff3.enable(enable);
		dff3.rw(rw);				dff3.clr(clr);

		dff4.clk(clk);				dff4.din(dinBool[4]);
		dff4.dout(doutBool[4]);		dff4.enable(enable);
		dff4.rw(rw);				dff4.clr(clr);

		dff5.clk(clk);				dff5.din(dinBool[5]);
		dff5.dout(doutBool[5]);		dff5.enable(enable);
		dff5.rw(rw);				dff5.clr(clr);

		dff6.clk(clk);				dff6.din(dinBool[6]);
		dff6.dout(doutBool[6]);		dff6.enable(enable);
		dff6.rw(rw);				dff6.clr(clr);

		dff7.clk(clk);				dff7.din(dinBool[7]);
		dff7.dout(doutBool[7]);		dff7.enable(enable);
		dff7.rw(rw);				dff7.clr(clr);

		dff8.clk(clk);				dff8.din(dinBool[8]);
		dff8.dout(doutBool[8]);		dff8.enable(enable);
		dff8.rw(rw);				dff8.clr(clr);

		dff9.clk(clk);				dff9.din(dinBool[9]);
		dff9.dout(doutBool[9]);		dff9.enable(enable);
		dff9.rw(rw);				dff9.clr(clr);

		dff10.clk(clk);				dff10.din(dinBool[10]);
		dff10.dout(doutBool[10]);	dff10.enable(enable);
		dff10.rw(rw);				dff10.clr(clr);

		dff11.clk(clk);				dff11.din(dinBool[11]);
		dff11.dout(doutBool[11]);	dff11.enable(enable);
		dff11.rw(rw);				dff11.clr(clr);		

		dff12.clk(clk);				dff12.din(dinBool[12]);
		dff12.dout(doutBool[12]);	dff12.enable(enable);
		dff12.rw(rw);				dff12.clr(clr);

		dff13.clk(clk);				dff13.din(dinBool[13]);
		dff13.dout(doutBool[13]);	dff13.enable(enable);
		dff13.rw(rw);				dff13.clr(clr);

		dff14.clk(clk);				dff14.din(dinBool[14]);
		dff14.dout(doutBool[14]);	dff14.enable(enable);
		dff14.rw(rw);				dff14.clr(clr);

		dff15.clk(clk);				dff15.din(dinBool[15]);
		dff15.dout(doutBool[15]);	dff15.enable(enable);
		dff15.rw(rw);				dff15.clr(clr);

		dff16.clk(clk);				dff16.din(dinBool[16]);
		dff16.dout(doutBool[16]);	dff16.enable(enable);
		dff16.rw(rw);				dff16.clr(clr);
	
		dff17.clk(clk);				dff17.din(dinBool[17]);
		dff17.dout(doutBool[17]);	dff17.enable(enable);
		dff17.rw(rw);				dff17.clr(clr);

		dff18.clk(clk);				dff18.din(dinBool[18]);
		dff18.dout(doutBool[18]);	dff18.enable(enable);
		dff18.rw(rw);				dff18.clr(clr);

		dff19.clk(clk);				dff19.din(dinBool[19]);
		dff19.dout(doutBool[19]);	dff19.enable(enable);
		dff19.rw(rw);				dff19.clr(clr);

		dff20.clk(clk);				dff20.din(dinBool[20]);
		dff20.dout(doutBool[20]);	dff20.enable(enable);
		dff20.rw(rw);				dff20.clr(clr);

		dff21.clk(clk);				dff21.din(dinBool[21]);
		dff21.dout(doutBool[21]);	dff21.enable(enable);
		dff21.rw(rw);				dff21.clr(clr);

		dff22.clk(clk);				dff22.din(dinBool[22]);
		dff22.dout(doutBool[22]);	dff22.enable(enable);
		dff22.rw(rw);				dff22.clr(clr);

		dff23.clk(clk);				dff23.din(dinBool[23]);
		dff23.dout(doutBool[23]);	dff23.enable(enable);
		dff23.rw(rw);				dff23.clr(clr);

		dff24.clk(clk);				dff24.din(dinBool[24]);
		dff24.dout(doutBool[24]);	dff24.enable(enable);
		dff24.rw(rw);				dff24.clr(clr);

		dff25.clk(clk);				dff25.din(dinBool[25]);
		dff25.dout(doutBool[25]);	dff25.enable(enable);
		dff25.rw(rw);				dff25.clr(clr);

		dff26.clk(clk);				dff26.din(dinBool[26]);
		dff26.dout(doutBool[26]);	dff26.enable(enable);
		dff26.rw(rw);				dff26.clr(clr);

		dff27.clk(clk);				dff27.din(dinBool[27]);
		dff27.dout(doutBool[27]);	dff27.enable(enable);
		dff27.rw(rw);				dff27.clr(clr);		

		dff28.clk(clk);				dff28.din(dinBool[28]);
		dff28.dout(doutBool[28]);	dff28.enable(enable);
		dff28.rw(rw);				dff28.clr(clr);

		dff29.clk(clk);				dff29.din(dinBool[29]);
		dff29.dout(doutBool[29]);	dff29.enable(enable);
		dff29.rw(rw);				dff29.clr(clr);

		dff30.clk(clk);				dff30.din(dinBool[30]);
		dff30.dout(doutBool[30]);	dff30.enable(enable);
		dff30.rw(rw);				dff30.clr(clr);

		dff31.clk(clk);				dff31.din(dinBool[31]);
		dff31.dout(doutBool[31]);	dff31.enable(enable);
		dff31.rw(rw);				dff31.clr(clr);

		//change back the output from int ->bool
		SC_METHOD(changeOutput);
		sensitive << doutBool[0] << doutBool[1] << doutBool[2] << doutBool[3] 
		<< doutBool[4] << doutBool[5] << doutBool[6] << doutBool[7] 
		<< doutBool[8] << doutBool[9] << doutBool[10] << doutBool[11] 
		<< doutBool[12] << doutBool[13] << doutBool[14] << doutBool[15] 
		<< doutBool[16] << doutBool[17] << doutBool[18] << doutBool[19] 
		<< doutBool[20] << doutBool[21] << doutBool[22] << doutBool[23] 
		<< doutBool[24] << doutBool[25] << doutBool[26] << doutBool[27] 
		<< doutBool[28] << doutBool[29] << doutBool[30] << doutBool[31];  
	}
};
#endif