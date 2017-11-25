#include "largest_series_product.h"
#include <string.h>


int64_t setUpSeries (const char** pHead, const char** pTail, unsigned int count);

int64_t largest_series_product (const char* numbers, unsigned int count) 
{
	int64_t sum = 0;
	int64_t largestSum = 0;
	const char* pTail = numbers;
	const char* pHead = pTail;

	
	if (count == 0) { return 1; }
	if (strlen(numbers) < count) { return -1; }
	//set up
	if ((sum = setUpSeries(&pHead, &pTail, count)) == -1) { return 0; }
	if (sum > largestSum) { largestSum = sum; }

	while (*pTail != '\0') { 
		if (*pTail == '0') {
			pTail++;
			pHead = pTail;
			if ((sum = setUpSeries(&pHead, &pTail, count)) == -1) { break; }	
		}
		else {
			sum /= *pHead - '0';
			pHead++;
			sum *= *pTail - '0';
			pTail++;
		}
		if (sum > largestSum) { largestSum = sum; }
	}
	return largestSum;
/*
	//walk !through array
	while (*pTail != '\0') {
		while (pTail - pHead < count && *pTail != '\0') {
			if (*pTail == '0') {
				while (*pTail == '0') { pTail++; }
				pHead = pTail;
				if (*pTail != '\0') {
					sum = *pHead - '0';
					pTail++;
				}
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
*/
}

int64_t setUpSeries (const char** pHead, const char** pTail, unsigned int count) 
{
	int64_t sum;
	*pHead = *pTail;
	do {
		sum = 1;
		while (**pHead == '0') { 
			*pTail += 1; 
			*pHead = *pTail;
			}

		if (**pTail == '\0') { return -1; }
		while (*pTail - *pHead < count && **pTail != '\0') {
			if(**pTail < '0' || **pTail > '9') { return -1; }
			sum *= **pTail - '0';
			*pTail += 1;
			if (**pTail == '0') { 
				*pTail += 1;
				*pHead = *pTail;
				sum = 0;
				break;
			}
		if (*pTail - *pHead == count) { return sum; }
		}
	} while (sum == 0);
	return -2;  //Major error, should never reach here
}
