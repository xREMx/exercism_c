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

	if ((sum = setUpSeries(&pHead, &pTail, count)) < 0) { 
		if (sum == -1) { return -1; }  //dissalowed char
		if (sum == -2) { return 0; }  //could not create string
	}
	largestSum = sum;

	while (*pTail != '\0') { 
		if (*pTail == '0') {
			pTail++;
			pHead = pTail;
			if ((sum = setUpSeries(&pHead, &pTail, count)) < 0 ) { 
				if (sum == -1) { return -1; }  //dissalowed char
				break;
			}	
		}
		else {
			sum /= *pHead - '0';
			pHead++;
			if(*pTail < '0' || *pTail > '9') { return -1; }
			sum *= *pTail - '0';
			pTail++;
		}
		if (sum > largestSum) { largestSum = sum; }
	}

	return largestSum;
}

int64_t setUpSeries (const char** pHead, const char** pTail, unsigned int count) 
{
	int64_t sum = 0;
	*pHead = *pTail;
	while (sum == 0) {
		while (**pHead == '0') { 
			*pTail += 1; 
			*pHead = *pTail;
			}

		sum = 1;
		while (**pTail != '\0') {
			if(**pTail < '0' || **pTail > '9') { return -1; }  //if we found a dissalowed char
			sum *= **pTail - '0';
			*pTail += 1;
			if (*pTail - *pHead == count) { return sum; }
			if (**pTail == '0') { 
				*pTail += 1;
				*pHead = *pTail;
				sum = 0;
				break;
			}
		}
	if (**pTail == '\0') { return -2; }  //if we were unable to make a full series
	} 
	return -11;  //Major error, should never reach here
}
