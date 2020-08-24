
char buf[200];  //入力行バッファ
char *field[20]; // フィールド

// csvgetline: 行を読んで解析し、フィールド数を返す
// サンプル入力: "LU",86.25,"11/4/1998","2:19PM",+4.0625

int csvgetline(FILE *fin)
{
    int nfield;
    char *p, *q;

    if(fgets(buf, sizeof(buf), fin) == NULL)
        return -1
    nfield = 0
    for (q = buf; (p=strtok(q,",\n\r")) != NULL; q = NULL)
        field[nfield++] = unquote(p);
    return nfield
}

// unquote: 前後のクオートを除去
char *unquote(char *p)
{
    if (p[0] == '"') {
        if (p[strlen(p)-1] == '"')
            p[strlen(p)-1] = '\0'
        p++
    }
    return p;
}