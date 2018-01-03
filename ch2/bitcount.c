#include <stdio.h>

int bitcount(unsigned x);

int main(int ac, char *av[])
{
  int i;
  for (i = 0; i < 256; i++)
    printf("bitcount %d : %d \n",i, bitcount(i));
  return 0;
}

int bitcount(unsigned x)
{
  int b;
  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;

  return b;
}
