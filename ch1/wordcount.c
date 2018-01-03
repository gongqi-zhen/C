#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
  int c;
  int nl, nw, nc, state;
  nl = nw = nc = 0;
  state = OUT;

  while ( (c = getchar()) != EOF ) {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\t' || c == '\n' )
      state = OUT;
    else if (state == OUT){
      state = IN;
      ++nw;
    }
  }

  printf("nc = %d, nw = %d, nl = %d\n", nc, nw, nl);

}
