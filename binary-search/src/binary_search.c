#include "binary_search.h"


int32_t* binary_search (int32_t key, int32_t arr[], size_t length) {
	if (arr == NULL) { return NULL; }
	if (length <= 0) { return NULL; }

	int32_t* iHead = arr;
	int32_t* iTail = arr + length - 1;
	
	while (iHead <= iTail) {
		int32_t* middle = iHead + (iTail - iHead) / 2;
		if (*middle == key) { return middle; }
		else if (*middle > key) { iTail = middle - 1; }
		else { iHead = middle + 1; }
	}
	return NULL;
}
