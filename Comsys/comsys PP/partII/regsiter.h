#ifndef REGISTER_H
#define REGISTER_H

#include <systemc.h>
#include "reg.h"

SC_MODULE(register) {

	sc_in<bool > clr;
	sc_in<bool > enable;
	sc_in<bool > rw;
	sc_in<sc_uint<5 > > addr;
	sc_in<sc_uint<32 > > din;

	//32 reg boxes
	reg reg0;	reg reg1;
	reg reg2;	reg reg3;
	reg reg4;	reg reg5;
	reg reg6;	reg reg7;
	reg reg8;	reg reg9;
	reg reg10;	reg reg11;
	reg reg12;	reg reg13;
	reg reg14;	reg reg15;
	reg reg16;	reg reg17;
	reg reg18;	reg reg19;
	reg reg20;	reg reg21;
	reg reg22;	reg reg23;
	reg reg24;	reg reg25;
	reg reg26;	reg reg27;
	reg reg28;	reg reg29;
	reg reg30;	reg reg31;
	

	void init() {
		reg0.
	}
	SC_CTOR(register) :
	reg0("reg0"), reg1("reg1"), reg2("reg2"), reg3("reg3"), reg4("reg4"), reg5("reg5"), reg6("reg6"), reg7("reg7"), 
	reg8("reg8"), reg9("reg9"), reg10("reg10"), reg11("reg11"), reg12("reg12"), reg13("reg13"), reg14("reg14"), reg15("reg15"), 
	reg16("reg16"), reg17("reg17"), reg18("reg18"), reg19("reg19"), reg20("reg20"), reg21("reg21"), reg22("reg22"), reg23("reg23"), 
	reg24("reg24"), reg25("reg25"), reg26("reg26"), reg27("reg27"), reg28("reg28"), reg29("reg29"), reg30("reg30"), reg31("reg31") 	
	{
		SC_METHOD();

	}
};
#endif