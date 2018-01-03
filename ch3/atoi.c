#include <ctype.h>

/* atoi: sを整数に変換する: 第２版 */

int atoi(char s[])
{
  int i, n, sign;
  
  for(i = 0; isspace(s[i]) ; i++) /* 空白を読み飛ばす */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') /* 符号を飛ばす */
    i++;
  for (n = 0; isdigit(s[i]) ; i++)
    n = 10 * n + (s[i]-'0');

  return n;
}
