#include "nth_prime.h"


uint32_t nth (uint16_t nthNum)
{
	if (nthNum == 0) { return 0; }
	if (nthNum == 1) { return 2; }

	uint32_t curPrime = 1;
	for (uint16_t count = 1; count < nthNum; ++count) {
		uint32_t testPrime = curPrime + 2;
		while (testPrime < UINT32_MAX) {
			uint32_t num = 3;
			while (num <= testPrime / 2) {
				if (testPrime % num == 0) {
					testPrime += 2;
					break;
				}
				num += 2;
			}
			if (num >= testPrime / 2) {
				curPrime = testPrime;
				break;
			}
		}
	}
	return curPrime;
}
