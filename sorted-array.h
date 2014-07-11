#pragma once

#define NEW(type, count) ((type*)malloc(sizeof(type) * count))

struct SortedArray_Wrapper_t {
  
}

struct SortedArray_t {
  size_t memberSize;
  size_t bufferLength;
  size_t numElements;
  size_t bufferIncrease;
  Bitset_t bitset;
  void* buffer;
}; 

struct Pair_t {
  void* a;
  void* b;
};

/**
 * Compares a to b, and returns 
 * -1  if a < b
 *  0  if a = b
 *  1  if a > b
 */
typedef int (*SortedArray_Compare)(void *a, void *b);
