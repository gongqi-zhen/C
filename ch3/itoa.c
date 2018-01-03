/* itoa: nをs中の文字に変換する */

void itoa(int n, char s[])
{
  int i, sign;
  if ((sign = n) < 0) /* 符号を記録する */
    n = -n; /* nを正にする*/
  i = 0;
  do {                   /* 数字を逆順に生成する */
    s[i++] = n % 10 + '0';  /* 次の桁をとってくる */
  } while (( n /= 10) > 0); /* それを削除する */

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}
