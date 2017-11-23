#include "largest_series_product.h"
#include <string.h>


unsigned int largest_series_product (const char* numbers, int count) 
{
	unsigned int sum = 1;
	unsigned int largestSum = 0;
	const char* pHead = numbers;
	const char* pTail = numbers;


	while (*pTail != '\0') {
		while (pTail - pHead < count && *pTail != '\0') {
			if (*pTail == '0') {
				while (*pTail == '0') { pTail++; }
				pHead = pTail;
				sum = *pHead - '0';
				pTail++;
			}
			else {
				sum *= *pTail - '0';
				pTail++;
			}
		}
		if (*pTail == '\0') { break; }
		if (*pTail == '0') {
			pHead = pTail;
		}
		else { 
			sum /= *pHead - '0';
			pHead++;
			sum *= *pTail - '0';
			pTail++;
		}
		if (sum > largestSum) { largestSum = sum; }
	}
	if (sum > largestSum) { largestSum = sum; }
	return largestSum; 
}
