/* Generates a hash from hashName, and then divides hash by plugMax, returning the remainder. */

uint32_t genHash(char *str, uint32_t hashMax)
{
  size_t len = strlen(str);
  uint32_t hash = 0;
  for(size_t i = 0; i <= len; i++)
    hash += (uint32_t)str[i];
  hash %= hashMax;
  return hash;
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
