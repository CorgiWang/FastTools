#ifndef Qual_MixD_H
#define Qual_MixD_H

#include "FastTools.h"
#include "Qual_TimeD.h"

class Qual_MixD {
public:
	U1 M;
	U2 W;
	U4 H;
	vector<VecInt> coreF;
	vector<string> coreT;

	Qual_MixD();
	~Qual_MixD();
	void clear();

	void from_Qual_TD(Qual_TimeD&);
	void load_Qual_MD(string, U1 op = 3);
	void save_Qual_MD(string, U1 op = 3);
	void show_Qual_MD(string, U1 op = 3, U4 begin = 0, U4 dh = 0);

};

#endif /* Qual_MixD_H */

