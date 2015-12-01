#include <systemc.h>
#include <bitset>

void normalize(sc_uint<8> &exp, sc_uint<23> &man, int df) {
		// std::bitset<8> old(exp);
		// cout << old << endl;
		int newExp = exp + df;
		exp = newExp;
		// std::bitset<8> x(exp);
		// cout << x << endl;

		// std::bitset<23> y(man);
		// cout << "before shift: " << y << endl;
		//no shift if = 0
		if (df > 0) {
			int i;
			man = man >> 1;
			//reveal hidden bit
			man[22] = 1;
			df--;
			man = man >> df;
		}
		// std::bitset<23> z(man);
		// cout << "after  shift: " << z << endl;
}

int sc_main (int argc, char* argv[]) {
	sc_uint<8> exp = 10;
	sc_uint<23> man = 1;
	man[22] = 1;
	man[21] = 1;
	man[1] =1;
	man[19] = 1;

	// normalize(exp, man, 3);

	sc_uint<3> a = 7;
	sc_uint<3> b = 1;
	sc_uint<4> s = a+b;
	std::bitset<4> p(s);
	// cout << p << endl;

	a = a >> 0;
	cout << a << endl;

	// int df = 2;
	// int newExp = exp + df;
	// std::bitset<8> x(exp);
	// exp = newExp;
	// cout << x << endl;

	return 0;
}