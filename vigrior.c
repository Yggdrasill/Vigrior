/* Generates a hash from str, and then divides hash by hashMax, returning the remainder. */

uint32_t genHash(char *str, uint32_t hashMax)
{
  unsigned hash = 0;
  unsigned len = strlen(str);
  for(int i = 0; i < len; i++ ) {
    hash += str[i];
    hash += ( hash << 10 );
    hash ^= ( hash >> 6 );
  }

  hash += ( hash << 3 );
  hash ^= ( hash >> 11 );
  hash += ( hash << 15 );

  return hash % hashMax;
}

/* Checks for hash collisions. Returns non-zero on collision and zero otherwise. */

int hashColCk(char *s1, char *s2, uint32_t hashMax)
{
  int hashCol = 0;
  uint32_t hash = genHash(s1, hashMax);
  uint32_t hash2 = genHash(s2, hashMax);
  if(hash == hash2 && strcmp(s1, s2) )
    hashCol = 1;
  return hashCol;
}
