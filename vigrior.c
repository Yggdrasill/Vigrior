#include "vigrior.h"

/* Generates a hash from str, and then divides hash by max, returning the remainder. */

uint32_t gen_hash(char *str, uint32_t max)
{
  unsigned hash = 0;
  unsigned len = strlen(str);
  for(unsigned i = 0; i < len; i++ ) {
    hash += str[i];
    hash += ( hash << 10 );
    hash ^= ( hash >> 6 );
  }

  hash += ( hash << 3 );
  hash ^= ( hash >> 11 );
  hash += ( hash << 15 );

  return hash % max;
}

/* Checks for hash collisions. Returns non-zero on collision and zero otherwise. */

int check_hash(char *s1, char *s2, uint32_t max)
{
  int hashCol = 0;
  uint32_t hash = gen_hash(s1, max);
  uint32_t hash2 = gen_hash(s2, max);
  if(hash == hash2)
    hashCol = strcmp(s1, s2);
  return hashCol;
}

