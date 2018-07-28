#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
  
  FILE *fp;
  char *line = NULL;
  size_t linecap = 0;
  ssize_t linelen;

  fp = fopen(av[1],"r");
  if (fp == NULL){
    fprintf(stderr, "cant open\n");
    exit(0);
  }

  while ((linelen = getline(&line, &linecap, fp)) > 0)
    fwrite(line, linelen, 1, stdout);
  free(line);

  fclose(fp);
  exit(0);
}
