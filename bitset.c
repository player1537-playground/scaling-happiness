#include "bitset.h"

struct Bitset_t *new_Bitset(int nbits) {
  struct Bitset_t *bitset = NEW(Bitset_t, 1);
  bitset->nwords = (n / WORD_SIZE + 1);
  bitset->words = NEW(Bitset_Word_t, bitset->nwords);
  clearAll_Bitset(bitset);
  return bitset;
}

void free_Bitset(struct Bitset_t *bitset) {
    free(bitset->words);
    free(bitset);
}

inline int bindex(int b) { 
  return b / WORD_SIZE; 
}

inline int boffset(int b) { 
  return b % WORD_SIZE; 
}

void setBit_Bitset(Bitset_t *bitset, int b) { 
    bitset->words[bindex(b)] |= 1 << (boffset(b)); 
}

void clearBit_Bitset(Bitset_t *bitset, int b) { 
    bitset->words[bindex(b)] &= ~(1 << (boffset(b)));
}

int getBit_Bitset(Bitset_t *bitset, int b) { 
  return bitset->words[bindex(b)] & (1 << (boffset(b)));
}

void clearAll_Bitset(Bitset_t *bitset) {
  memset(bitset->words, 0, bitset->nwords * sizeof(Bitset_Word_t));
}

void setAll_Bitset(Bitset_t *bitset) { 
  memset(bitset->words, ~0, bitset->nwords * sizeof(Bitset_Word_t);
}
