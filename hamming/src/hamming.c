#include <string.h>
#include "hamming.h"

int compute (const char* dnaStrA, const char* dnaStrB)
{
	if (dnaStrA == NULL || dnaStrB == NULL) { return -1; }

	int strlenA = strlen(dnaStrA);
	int strlenB = strlen(dnaStrB);
	
	if (strlenA != strlenB) { return -1; }

	int countMismatch = 0;
	for (int i = 0; i < strlenA; i++) {
		if (dnaStrA[i] != dnaStrB[i]) { countMismatch++; }
	}

	return countMismatch;
}
