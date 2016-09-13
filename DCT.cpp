#include "DCT.h"

DCT::DCT(U2 w) : W(w) {
	COEF.clear();
	COEF.resize(W, 1);

	double A = 1 / sqrt(W);
	TM.resize(W);
	TM[0].resize(W, A);
	A *= sqrt(2);
	for (U2 i = 1; i < W; i++) {
		TM[i].resize(W, A);
		for (U2 j = 0; j < W; j++) {
			TM[i][j] *= cos(PI * i * (j + 0.5) / W);
		}
	}
	ITM.resize(W);
	for (U2 i = 0; i < W; i++) {
		ITM[i].resize(W);
		for (U2 j = 0; j < W; j++) {
			ITM[i][j] = TM[j][i] / COEF[j];
			TM[j][i] *= COEF[j];
		}
	}
}

