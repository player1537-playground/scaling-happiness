#pragma once

typedef uint32_t Bitset_Word_t;

struct Bitset_t { 
  Bitset_Word_t words;
  size_t nwords;
};

#define WORD_SIZE 32

struct Bitset_t *new_Bitset(int nbits);
void free_Bitset(struct Bitset_t *bitset);
inline int bindex(int b);
inline int boffset(int b);
void setBit_Bitset(Bitset_t *bitset, int b);
void clearBit_Bitset(Bitset_t *bitset, int b);
int getBit_Bitset(Bitset_t *bitset, int b);
void clearAll_Bitset(Bitset_t *bitset);
void setAll_Bitset(Bitset_t *bitset);
