/*
 * _getline.c
 *
 * while (まだ行がある)
 *  if (以前に一番長かった行よりも長い)
 *    その行を格納する
 *    その長さを格納する
 *  一番長い行を表示する
 *
 */

#include <stdio.h>

#define MAXLINE 1000  // 入力行の最大長

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(int ac, char *av[])
{

  int len;              // 現在行の長さ
  int max;              // 今まで出てきた最大長
  char line[MAXLINE];   // 現在の入力行
  char longest[MAXLINE];  // 格納されている最長行

  max = 0;

  while (( len = _getline (line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)
    printf("%s", longest);
  
  return 0;
}

/* _getline : sに行を入れ、長さを返す */
int _getline(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n'){
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: fromをtoにコピー ; toは十分大きいと仮定 */

void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
