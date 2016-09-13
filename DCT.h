#ifndef DCT_H
#define DCT_H

#include "FastTools.h"

class DCT {
public:
	const double PI = 3.14159265358979323846;
	const U2 W;
	RealVec COEF;
	vector<RealVec> TM, ITM;
	DCT(U2);

	template<typename T>
	bool transform(T& x, RealVec& y, bool inv = false) {
		bool ok = (x.size() == W);

		if (ok) {
			vector<RealVec>& mat = (inv ? ITM : TM);
			y.clear();
			y.resize(W, 0);
			for (U2 i = 0; i < W; i++) {
				for (U2 j = 0; j < W; j++) {
					y[i] += mat[i][j] * x[j];
				}
			}
		}

		return ok;
	}

};

#endif /* DCT_H */

