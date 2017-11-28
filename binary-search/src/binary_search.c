#include "binary_search.h"


int* binary_search (int key, int arr[], size_t length) {
	if (arr == NULL) { return NULL; }
	if (length <= 0) { return NULL; }

	int iHead = 0;
	int iTail = length - 1;
	
	while (iHead <= iTail) {
		int middle = (iHead + iTail) / 2;
		int arrCur = arr[middle];
		if (arrCur == key) { return &arr[middle]; }
		else if (arrCur > key) { iTail = middle - 1; }
		else { iHead = middle + 1; }
	}
	return NULL;
}
