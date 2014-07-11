#include <malloc.h>
#include <stdlib.h>
#include "sorted-array.h"
#include "bitset.c"

/**
 * Constraint: no two objects will be inserted of the same value
 */
struct SortedArray_t *new_SortedArray(size_t memberSize, size_t initialBufferLength, size_t bufferIncrease) {
  struct SortedArray_t *sortedArray = NEW(struct SortedArray_t, 1);
  sortedArray->memberSize = memberSize;
  sortedArray->bufferLength = initialBufferLength;
  sortedArray->bufferIncrease = bufferIncrease;
  sortedArray->numElements = 0;
  sortedArray->buffer = (void*)NEW(uint8, initialBufferLength);
  if (sortedArray->buffer == NULL) {
    fprintf(stderr, "Malloc failed to allocated %d bytes", initialBufferLength);
    exit(1);
  }
  memset(sortedArray->buffer, 0, initialBufferLength);
  return sortedArray;
}

void *search_SortedArray(SortedArray_t *haystack, void *needle, size_t size, SortedArray_Compare compare) {
  size_t lo = 0;
  size_t hi = haystack->bufferLength - 1;
  while (lo != hi) {
    size_t mid = (lo + hi) / 2;
    
    if (getBit_Bitset(haystack->bitset, mid)) {

    } else {
      
    }
    
    int comparison = (*compare)(data, mid);
    if (comparison < 0) {
      /* data comes before midpoint, move left */
      hi = mid;
    } else if (comparison > 0) {
      /* data comes after midpoint, move right */
      lo = mid;
    } else {
      /* data is at the midpoint, return a pointer to this data */
      return mid;
    }
  }
  
  /* If we get here, we didn't find the element, so return the current position */
  return lo;
}

void insert_SortedArray(void *data, size_t size) {
  
}
