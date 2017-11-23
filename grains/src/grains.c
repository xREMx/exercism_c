#include "grains.h"
#include <math.h>


unsigned long square (int squareNum) 
{
	if (squareNum > 64) { return 0; }
	return pow(2, squareNum - 1);
}


unsigned long total (void) 
{
	return 18446744073709551615ul;
}
