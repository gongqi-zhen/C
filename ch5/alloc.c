#define ALLOCSIZE 10000 /* 使用可能な場所の大きさ */

static char allocbuf[ALLOCSIZE]; /* allocのための記憶場所 */
static char *allocp = allocbuf; /* 次の空き位置 */

char *alloc(int n)  /* n文字へのポインタを返す */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { /* 入りきる */
		allocp += n;
		return allocp - n; /* 古いp */
	} else /* 十分な空きがない時 */
		return 0;
}

void afree(char *p) /* pによって指される領域を解放する */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
