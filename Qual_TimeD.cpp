#include "Qual_TimeD.h"
#include "DCT.h"

Qual_TimeD::Qual_TimeD() {
	clear();
}

Qual_TimeD::~Qual_TimeD() {
	clear();
}

void Qual_TimeD::clear() {
	M = 0;
	W = 0;
	H = 0;
	core.clear();
}

void Qual_TimeD::from_FX(FastX& fx) {
	Stamp(__func__, 0);

	clear();
	M = fx.M;
	W = fx.W;
	H = fx.H;
	core = fx.core[3];

	//	set_Model(1);

	Stamp(__func__, 1);
}

void Qual_TimeD::from_Qual_MD(Qual_MixD& md) {
	Stamp(__func__, 0);

	clear();
	M = md.M;
	W = md.W;
	H = md.H;
	core.resize(H);

	DCT dct(W);
	RealVec tReal;
	for (U4 i = 0; i < H; i++) {
		core[i].resize(W);
		dct.transform(md.coreF[i], tReal, true);
		for (U2 j = 0; j < W; j++) {
			core[i][j] = lround(tReal[j]) + md.coreT[i][j];
		}
		if (0 == i % 10000) {
			cout << i << endl;
		}
	}

	Stamp(__func__, 1);
}

void Qual_TimeD::load_Qual_TD(string path) {
	Stamp(__func__, 0);

	clear();
	ifstream ifs(path, ios::binary);
	ifs.read(RPt(&M), sizeof (M));
	ifs.read(RPt(&W), sizeof (W));
	ifs.read(RPt(&H), sizeof (H));
	core.resize(H);
	for (U4 i = 0; i < H; i++) {
		core[i].resize(W);
		ifs.read(RPt(core[i].data()), W);
	}

	Stamp(__func__, 1);
}

void Qual_TimeD::save_Qual_TD(string path) {
	Stamp(__func__, 0);

	ofstream ofs(path, ios::binary);
	ofs.write(WPt(&M), sizeof (M));
	ofs.write(WPt(&W), sizeof (W));
	ofs.write(WPt(&H), sizeof (H));
	for (U4 i = 0; i < H; i++) {
		ofs.write(WPt(core[i].data()), W);
	}
	ofs.close();

	Stamp(__func__, 1);
}

void Qual_TimeD::show_Qual_TD(string path, U4 begin, U4 dh) {
	Stamp(__func__, 0);

	ofstream ofs(path);
	U4 end = (0 == dh ? H : begin + dh);
	for (U4 i = begin; i < end; i++) {
		for (U2 j = 0; j < W; j++) {
			ofs << U2(core[i][j]) << '\t';
		}
		ofs << endl;
	}
	ofs.close();

	Stamp(__func__, 1);
}

void Qual_TimeD::set_Model(U1 model) {
	Stamp(__func__, 0);

	if (model != M) {
		I1 delta = PHRED[M][0] - PHRED[model][0];
		for (U4 i = 0; i < H; i++) {
			for (U2 j = 0; j < W; j++) {
				core[i][j] += delta;
			}
		}
		M = model;
	}

	Stamp(__func__, 1);
}


