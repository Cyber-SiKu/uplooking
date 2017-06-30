#include <stdio.h>

static int max(int (*arry)[2], int *maxRet);

int main(int argc, char const *argv[]) {
  int arry[3][2] = {{1, 2}, {3, 4}, {5, 6}};

  printf("arry[0][3]:%d,*(*arry+3):%d,arry[1][1]:%d \n", arry[0][3],
         *(*arry + 3), arry[1][1]);
  for (int i = 0; i < 3; i++) {
    for (size_t j = 0; j < 2; j++) {
      printf("%d ", arry[i][j]);
      /* code */
    }
    printf("\n");
  }

  int Max = 0;
  max(arry, &Max);
  printf("MAX = %d\n", Max);
  return 0;
}

static int max(int (*arry)[2], int *maxRet) {
  int max = arry[0][0];
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 2; j++) {
      if (j == 0 && j == i) {
        continue;
      }
      if (max < arry[i][j]) {
        max = arry[i][j];
      }
    }
  }
  (*maxRet) = max;
}
