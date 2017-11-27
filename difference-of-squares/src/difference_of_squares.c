#include "difference_of_squares.h"
#include  <math.h>


uint32_t square_of_sum (uint16_t input) 
{
	uint32_t squareOfSum = 0;
	for (int n = 1; n <= input; ++n) {
		squareOfSum += n;
	}
	squareOfSum = pow(squareOfSum, 2);

	return squareOfSum;
}


uint32_t sum_of_squares (uint16_t input) 
{
	uint32_t sumOfSquare = 0;
	for (int n = 1; n <= input; ++n) {
		sumOfSquare += pow(n, 2);
	}

	return sumOfSquare;
}


uint32_t difference_of_squares (uint16_t input)
{
	return square_of_sum(input) - sum_of_squares(input);
}
