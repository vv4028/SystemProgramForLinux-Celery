#include <errno.h>
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp;

  fp = fopen("tmp", "r");
  if (fp == NULL) {
    // fprintf((stderr, "fopen() filled! errno = %d\n"), errno);
    // perror("fopen()");
    fprintf(stderr, "fopen():%s\n", strerror(errno));
    exit(1);
  }
  puts("OK!");

  fclose(fp);
  exit(0);
}
