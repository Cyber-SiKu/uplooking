#include <stdio.h>
#include <stdlib.h>

void j(int **i) {
  *i = (int *)malloc(sizeof(int));
  **i = 1;
}

void j_(int *i) {
  i = (int *)malloc(sizeof(int));
  *i = 1;
}

int main(int argc, char const *argv[]) {
  int i = 0;
  int *p = &i;
  j(&p);
  printf("%d %d\n", *p, i);
  p = &i;
  j_(p);
  printf("%d %d\n", *p, i);
  return 0;
}
