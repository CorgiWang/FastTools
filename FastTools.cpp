#include "FastTools.h"
#include "FastX.h"
#include "Qual_TimeD.h"
#include "Qual_MixD.h"

int main(int argc, char** argv) {
	Stamp(__func__, 0);

	vector<string> para;
	for (U1 i = 1; i < argc; i++) {
		para.push_back(argv[i]);
	}

	if (para[0] == "-eQ") {
		string pathIn = para[1];
		string pathOut = pathIn + ".Qual";
		FastX fx;
		fx.load_FX(pathIn);
		Qual_TimeD td;
		td.from_FX(fx);
		td.save_Qual_TD(pathOut);
	}
	if (para[0] == "-r") {
		string pathIn = para[1];
		string pathOutB = pathIn + ".B";
		string pathOutA = pathIn + ".A";
		Qual_TimeD td;
		td.load_Qual_TD(pathIn);
		Qual_MixD md;
		md.from_Qual_TD(td);
		md.save_Qual_MD(pathOutB, 1);
		md.save_Qual_MD(pathOutA, 2);
	}
	if (para[0] == "-m") {
		string pathOut = para[1];
		string pathIn_B = pathOut + ".B";
		string pathIn_A = pathOut + ".A";
		Qual_MixD md;
		md.load_Qual_MD(pathIn_B, 1);
		md.load_Qual_MD(pathIn_A, 2);
		Qual_TimeD td;
		td.from_Qual_MD(md);
		td.save_Qual_TD(pathOut);
	}

	Stamp(__func__, 1);
	return 0;

}

