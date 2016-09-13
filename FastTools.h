#ifndef FastTools_H
#define FastTools_H

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <random>

using namespace std;

class FastX;
class Qual_TimeD;
class Qual_FreqD;
class Qual_MixD;


typedef __int8_t I1;
typedef __int16_t I2;
typedef __int32_t I4;
typedef __int64_t I8;

typedef __uint8_t U1;
typedef __uint16_t U2;
typedef __uint32_t U4;
typedef __uint64_t U8;

typedef double Real;
typedef I2 Int;

typedef vector<Real> RealVec;
typedef vector<Int> VecInt;

typedef const char* WPt;
typedef char* RPt;

const string PHRED[] = {
	"\0~",
	"!K",
};

inline void Stamp(const char* fn, U1 op) {

	static const U4 T0 = time(NULL);
	const char* s[3] = {
		"Enter",
		"Leave",
		"Check",
	};
	static U2 depth = 0;

	U2 cur = depth;
	switch (op) {
		case 0:
			depth++;
			cur++;
			break;
		case 1:
			depth--;
			break;
	}
	for (U2 i = 1; i < cur; i++) {
		printf("    ");
	}
	printf("%6ld: [%s] %s\n", time(NULL) - T0, fn, s[op]);
}


#endif /* FastTools_H */

