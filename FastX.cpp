#include "FastX.h"

FastX::FastX() {
	clear();
	M = 0;
}

FastX::~FastX() {
	clear();
}

void FastX::clear() {
	Th = 0;
	M = 0;
	W = 0;
	H = 0;
	for (U1 i = 0; i < 4; i++) {
		core[i].clear();
	}
}

void FastX::load_FX(string path) {
	Stamp(__func__, 0);

	clear();
	for (U1 i = 0; i < 4; i++) {
		core[i].reserve(1E7);
	}
	ifstream ifs(path);
	string ts;

	getline(ifs, ts);
	core[0].push_back(ts);
	Th = ('@' == ts[0] ? 4 : 2);

	getline(ifs, ts);
	core[1].push_back(ts);
	W = ts.length();

	if (4 == Th) {
		getline(ifs, ts);
		core[2].push_back(ts);
		getline(ifs, ts);
		core[3].push_back(ts);
	}

	U1 ct = 0;
	while (!ifs.eof()) {
		getline(ifs, ts);
		core[ct++].push_back(ts);
		ct %= Th;
	}

	H = core[Th - 1].size();
	for (U1 i = 0; i < Th; i++) {
		core[i].resize(H);
	}
	ifs.close();

	Stamp(__func__, 1);
}

void FastX::save_FX(string path) {
	Stamp(__func__, 0);

	ofstream ofs(path);
	for (U4 i = 0; i < H; i++) {
		for (U1 j = 0; j < Th; j++) {
			ofs << core[j][i] << endl;
		}
	}
	ofs.close();

	Stamp(__func__, 1);
}
