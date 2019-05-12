/* strlen: 文字列sの長さを返す */
int strlen(char *s)
{
	int n;
	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}

/* strlen: 文字列sの長さを返す */
int strlen(char *s)
{
	char *p = s;
	while (*p != '\0')
		p++;
	return p - s;
}
