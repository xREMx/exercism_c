#include "all_your_base.h"
#include <math.h>


size_t rebase (int8_t* digits, int16_t input_base, int16_t output_base, size_t input_length) 
{
	uint64_t value = 0;

	if (input_base < 2) { return 0; }
	if (output_base < 2) { return 0; }
	if (digits[0] == 0) { return 0; }

	for (size_t exponent = input_length - 1, index = 0; index < input_length; --exponent, ++index) {
		if (digits[index] < 0) { return 0; }
		if (digits[index] >= input_base) { return 0; }
		value += digits[index] * pow(input_base, exponent);
	}

	size_t index1 = 0;
	while (value) {
		digits[index1] = value % output_base;
		value /= output_base;
		++index1;
	}

	size_t newlen = index1;
	--index1;
	for (size_t index2 = 0; index2 < newlen / 2; index2++, index1--) {
		int8_t  temp = digits[index1];
		digits[index1] = digits[index2];
		digits[index2] = temp;
	}

	return newlen;
}
