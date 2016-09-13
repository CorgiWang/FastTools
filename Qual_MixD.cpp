#include "DCT.h"
#include "Qual_MixD.h"

Qual_MixD::Qual_MixD() {
	clear();
}

Qual_MixD::~Qual_MixD() {
	clear();
}

void Qual_MixD::clear() {
	M = 0;
	W = 0;
	H = 0;
	coreF.clear();
	coreT.clear();
}

void Qual_MixD::from_Qual_TD(Qual_TimeD& td) {
	Stamp(__func__, 0);

	clear();
	M = td.M;
	W = td.W;
	H = td.H;
	coreF.resize(H);
	coreT.resize(H);
	DCT dct(W);
	RealVec tReal;

	for (U4 i = 0; i < H; i++) {
		coreF[i].resize(W);
		coreT[i].resize(W);
		dct.transform(td.core[i], tReal);
		for (U2 j = 0; j < W; j++) {
			coreF[i][j] = lround(tReal[j]);
		}
		dct.transform(coreF[i], tReal, true);
		for (U2 j = 0; j < W; j++) {
			coreT[i][j] = td.core[i][j] - lround(tReal[j]);
		}
		if (0 == i % 10000) {
			cout << i << endl;
		}
	}

	Stamp(__func__, 1);

}

void Qual_MixD::load_Qual_MD(string path, U1 op) {
	Stamp(__func__, 0);

	ifstream ifs(path, ios::binary);
	ifs.read(RPt(&M), sizeof (M));
	ifs.read(RPt(&W), sizeof (W));
	ifs.read(RPt(&H), sizeof (H));
	if (1 & op) {
		coreF.resize(H);
		for (U4 i = 0; i < H; i++) {
			coreF[i].resize(W);
			ifs.read(RPt(coreF[i].data()), W * sizeof(Int));
		}
	}
	if (2 & op) {
		coreT.resize(H);
		for (U4 i = 0; i < H; i++) {
			coreT[i].resize(W);
			ifs.read(RPt(coreT[i].data()), W);
		}
	}
	ifs.close();

	Stamp(__func__, 1);
}

void Qual_MixD::save_Qual_MD(string path, U1 op) {
	Stamp(__func__, 0);

	ofstream ofs(path, ios::binary);
	ofs.write(WPt(&M), sizeof (M));
	ofs.write(WPt(&W), sizeof (W));
	ofs.write(WPt(&H), sizeof (H));
	if (1 & op) {
		for (U4 i = 0; i < H; i++) {
			ofs.write(WPt(coreF[i].data()), W* sizeof(Int));
		}
	}
	if (2 & op) {
		for (U4 i = 0; i < H; i++) {
			ofs.write(WPt(coreT[i].data()), W);
		}
	}
	ofs.close();

	Stamp(__func__, 1);
}

void Qual_MixD::show_Qual_MD(string path, U1 op, U4 begin, U4 dh) {
	Stamp(__func__, 0);

	ofstream ofs(path);
	U4 end = (0 == dh ? H : begin + dh);
	for (U4 i = begin; i < end; i++) {
		if (1 & op) {
			for (U2 j = 0; j < W; j++) {
				ofs << I2(coreF[i][j]) << '\t';
			}
			ofs << endl;
		}
		if (2 & op) {
			for (U2 j = 0; j < W; j++) {
				ofs << I2(coreT[i][j]) << '\t';
			}
			ofs << endl;
		}
		if (3 == op) {
			ofs << endl;
		}
	}
	ofs.close();

	Stamp(__func__, 1);
}



