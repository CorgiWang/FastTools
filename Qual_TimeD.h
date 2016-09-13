#ifndef Qual_TimeD_H
#define Qual_TimeD_H

#include "FastTools.h"
#include "FastX.h"
#include "Qual_MixD.h"

class Qual_TimeD {
public:

	U1 M;
	U2 W;
	U4 H;
	vector<string> core;

	Qual_TimeD();
	~Qual_TimeD();
	void clear();

	void from_FX(FastX&);
	void from_Qual_MD(Qual_MixD&);

	void load_Qual_TD(string);
	void save_Qual_TD(string);
	void show_Qual_TD(string, U4 begin = 0, U4 dh = 0);
	
	void set_Model(U1);
};

#endif /* Qual_TimeD_H */

