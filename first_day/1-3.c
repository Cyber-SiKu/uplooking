#include <stdio.h>

#define STUDENTNR 30

int main(int argc, char const *argv[]) {
  int score_c[STUDENTNR] = {[9] = 1};
  for (size_t i = 0; i < STUDENTNR; i++) {
    printf("%d ", score_c[i]);
  }
  return 0;
}
