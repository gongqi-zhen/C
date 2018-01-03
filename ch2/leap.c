
#include <stdio.h>

int main()
{

  int leap;
//  printf("input check year ( 0 - 1000 ) : ");
//  scanf("%d",&leap);
  for (leap = 0 ; leap < 100; ++leap) {
    if (( leap % 4 == 0 && leap % 100 != 0 ) || leap % 400 == 0 )
     printf("%d is leap year\n", leap);
    else
     printf("%d is not leap year\n", leap);
  }
  return 0;

}
