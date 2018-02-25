#include <stdio.h>
#include <ctype.h>

int getch(void);
int ungetch(int);
int getint(int *);

int main(void)
{
	int n, array[10];
	int i;
	for (n = 0; n < 10 && getint(&array[n]) != EOF; n++)
		;
	for (i = 0; i < 10; i++) {
		printf("%d\n", array[i]);
	}
	return 0;
}

/* getint: 入力から次の整数を取り出して*pnに入れる */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()) ) /* 空白を飛ばす */
		;
	if ( !isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c); /*数字ではない*/
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = *pn * 10 + (c-'0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
