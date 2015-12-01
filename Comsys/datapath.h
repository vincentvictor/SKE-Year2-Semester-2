#ifndef DATAPATH_H
#define DATAPATH_H

#include <systemc.h>
#include <math.h>
#include <bitset>
#include <conv.h>
#include <add.h>
SC_MODULE(Dtp) {
	sc_in<float> fin1, fin2;
	sc_out<sc_uint<32> > fout_s;
	sc_signal<sc_uint<32> > out1, out2;
	Conv conv1, conv2;
	Add add;

	SC_CTOR(Dtp): conv1("Conv1"), conv2("Conv2"), add("Add"){     
        conv1.fin(fin1);
		conv1.fout(out1);
		conv2.fin(fin2);
		conv2.fout(out2);

		add.fin1(out1);
		add.fin2(out2);
		add.fout(fout_s);
    }
};
#endif


