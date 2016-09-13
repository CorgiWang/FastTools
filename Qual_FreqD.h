#ifndef Qual_FreqD_H
#define Qual_FreqD_H

#include "FastTools.h"
#include "Qual_TimeD.h"

class Qual_FreqD {
public:

	U1 M;
	U2 W;
	U4 H;
	vector<RealVec> core;

	Qual_FreqD();
	~Qual_FreqD();
	void clear();

	void from_Qual_TD(Qual_TimeD&);
	void load_Qual_FD(string);
	void save_Qual_FD(string);
	void show_Qual_FD(string, U4 begin = 0, U4 dh = 0);

};

#endif /* Qual_FreqD_H */

