#include <stdio.h>
#include <stdlib.h>

int main()
{

  int c, i;
  int nwhite, nother;
  int ndigit[10];
  nwhite = nother = 0;
  for (i = 0; i < 10; ++i)
    ndigit[i] = 0;

  while ( (c = getchar()) != EOF ) {
    if (c == ' ' || c == '\t' || c == '\n')
      ++nwhite;
    else if (c >= '0' && c <= '9') {
//      printf("%d : %c\n", c, c); exit(0);
      ++ndigit[c-'0'];
//      ++ndigit[c];
    } else
      ++nother;
  }

  printf("ndigit =");
  for (i = 0; i < 10; ++i)
    printf(" %d", ndigit[i]);
  printf(", nwhite = %d, nother = %d\n", nwhite, nother);

}
