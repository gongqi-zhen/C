#include <stdio.h>

int main()
{
  int i = 65;
  while (i < 100) {
    printf("%d = %c\n",i, i);
    ++i;
  }
}
