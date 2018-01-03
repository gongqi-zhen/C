#include <stdio.h>
int main()
{
  char num[10] = "abc";
  printf("%d %d\n",'a','b');
  if (num[2] == '\0')
    printf("end of array\n");
  else
    printf("%c %c %c %c\n", num[0],num[1],num[2],num[3]);
}
