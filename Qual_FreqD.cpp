#include "DCT.h"
#include "Qual_FreqD.h"

Qual_FreqD::Qual_FreqD() {
	clear();
}

Qual_FreqD::~Qual_FreqD() {
	clear();
}

void Qual_FreqD::clear() {
	M = 0;
	W = 0;
	H = 0;
	core.clear();
}

void Qual_FreqD::from_Qual_TD(Qual_TimeD& td) {
	Stamp(__func__, 0);

	clear();
	M = td.M;
	W = td.W;
	H = td.H;

	DCT dct(W);
	core.resize(H);
	for (U4 i = 0; i < H; i++) {
		dct.transform(td.core[i], core[i]);
		if (0 == i % 10000) {
			cout << i << endl;
		}
	}

	Stamp(__func__, 1);
}

void Qual_FreqD::load_Qual_FD(string path) {
	Stamp(__func__, 0);

	clear();
	ifstream ifs(path, ios::binary);
	ifs.read(RPt(&M), sizeof (M));
	ifs.read(RPt(&W), sizeof (W));
	ifs.read(RPt(&H), sizeof (H));
	core.resize(H);
	for (U4 i = 0; i < H; i++) {
		core[i].resize(W);
		ifs.read(RPt(core[i].data()), W * sizeof (Real));
	}

	Stamp(__func__, 1);
}

void Qual_FreqD::save_Qual_FD(string path) {
	Stamp(__func__, 0);

	ofstream ofs(path, ios::binary);
	ofs.write(WPt(&M), sizeof (M));
	ofs.write(WPt(&W), sizeof (W));
	ofs.write(WPt(&H), sizeof (H));
	for (U4 i = 0; i < H; i++) {
		ofs.write(WPt(core[i].data()), W * sizeof (Real));
	}
	ofs.close();

	Stamp(__func__, 1);
}

void Qual_FreqD::show_Qual_FD(string path, U4 begin, U4 dh) {
	Stamp(__func__, 0);

	ofstream ofs(path);
	ofs.setf(ios::fixed);
	U4 end = (0 == dh ? H : begin + dh);
	for (U4 i = begin; i < end; i++) {
		for (U2 j = 0; j < W; j++) {
			ofs << setprecision(1) << setw(7) << core[i][j] << '\t';
		}
		ofs << endl;
	}
	ofs.close();

	Stamp(__func__, 1);
}
