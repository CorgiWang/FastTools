#ifndef FastX_H
#define FastX_H

#include "FastTools.h"

class FastX {
public:
	U1 Th;
	U1 M;
	U2 W;
	U4 H;
	vector<string> core[4];

	FastX();
	~FastX();

	void clear();

	void load_FX(string);
	void save_FX(string);

};

#endif /* FastX_H */

