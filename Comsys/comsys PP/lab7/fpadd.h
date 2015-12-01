#ifndef FPADDER_H
#define FPADDER_H

#include <systemc.h>

SC_MODULE(fpadder) {
	sc_in<float> a;
	sc_in<float> b;

	SC_CTOR(fpadder) {

	}
};
#endif