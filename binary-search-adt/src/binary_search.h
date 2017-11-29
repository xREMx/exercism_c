#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>
#include <stdint.h>

void* binary_search (const void* key, void* array, size_t numElm, size_t elmSize, int8_t (*compare) (const void*, const void*));

#endif
