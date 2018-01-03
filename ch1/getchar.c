#include <stdio.h>
#include <stdlib.h>

int main()
{
  int c;
  
  while ( (c = getchar()) != EOF ){
    if ( c == 'Q')
      break;
    putchar(c);
  }
  exit(0);
}
