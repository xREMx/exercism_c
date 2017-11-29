#include "binary_search.h"


void* binary_search (const void* key, void* array, size_t numElm, size_t elmSize, int8_t (*compare) (const void*, const void*)) 
{
	if (array == NULL) { return NULL; }

	void* pHead = array;
	void* pTail = (char*)pHead + (numElm - 1) * elmSize;

	while (pHead <= pTail) {
		void* pMiddle = (char*)pHead + ((char*)pTail - (char*)pHead) / elmSize / 2 * elmSize;
		const int8_t comparison = compare(key, pMiddle);
		if (comparison == 0) { return pMiddle; }
		else if (comparison < 0) { pTail = (char*)pMiddle - elmSize; }
		else { pHead = (char*)pMiddle + elmSize; }
	}
	return NULL;
}
