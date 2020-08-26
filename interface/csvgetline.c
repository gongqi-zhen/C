/* csvgetline: 1行取得し、必要に応じて伸張 */
/* サンプル入力: "LU",86.25,"11/4/1998","2:19PM",+4.0625 */

char *csvgetline(FILE *fin)
{
    int i, c;
    char *newl, *news;

    if (line == NULL) { // 最初の呼び出し時に割り当て
        maxline = maxfield = 1;
        line = (char *) malloc(maxline);
        sline = (char *) malloc(maxline);
        field = (char **) malloc(maxfield * sizeof(field[0]));
        if (line == NULL || sline == NULL || field == NULL) {
            reset();
            return NULL;    // メモリ不足
        }
    }
    for (i = 0; (c=getc(fin)) != EOF && !endofline(fin,c); i++) {
        if (i >= maxline-1) { // 行を伸張
            maxline *= 2;   // 現在のサイズを倍に
            newl = (char *) realloc(line, maxline);
            news = (char *) realloc(sline, maxline);
            if (newl == NULL || news == NULL) {
                reset();
                return NULL;    // メモリ不足
            }
            line = newl;
            sline = news;
        }
        line[i] = c;
    }
    line[i] = '\0';
    if (split() == NOMEM) {
        reset();
        return NULL;    // メモリ不足
    }
    return (c == EOF && i == 0) ? NULL : line;
}

/* reset : 変数を最初の値に戻す */
static void reset(void)
{
    free(line); /* free(NULL)はANCI Cで容認されている */
    free(sline);
    free(field);
    line = NULL;
    sline = NULL;
    field = NULL;
    maxline = maxfield = nfield = 0;
}