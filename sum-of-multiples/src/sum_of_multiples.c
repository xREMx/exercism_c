#include "sum_of_multiples.h"
#include <stdlib.h>


uint32_t sum_of_multiples (const unsigned int multiples[], size_t numelmMultiples, uint16_t topVal) 
{
	if (multiples == NULL) { return 0; }
	if (multiples[0] == 0) { return 0; }

	uint8_t* multiplesOf = (uint8_t*) calloc(topVal, sizeof(uint8_t));

	for (size_t index = 0; index < numelmMultiples; ++index) {
		for (uint16_t i = 1; i * multiples[index]  < topVal; ++i) {
			uint8_t* pMultiplesOf= &multiplesOf[multiples[index] * i];
			if (*pMultiplesOf == 0) { *pMultiplesOf = 1; }
		}
	}
	uint32_t total = 0;
	for (size_t index = 0; index < topVal; ++index) {
		total += index * multiplesOf[index];
	}
	free(multiplesOf);
	return total;
}
