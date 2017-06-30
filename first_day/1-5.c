/*
bubble sort
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 10

static void function(int *arry, int number);

typedef int (*fun_t)(const void *, const void *);

static void bubble_another(void *arry, int size, int n, fun_t fun);

// compare function
int number_cmp(const void *data1, const void *data2);

static void show(int *arry, int number);

int main(int argc, char const *argv[]) {
#if 0
  int arry[] = {1, 2, 33, 4456, 6676, 77787, 13425, 2134123, 45675687, 352351};
#endif
  int arry[MAX];
  srand(getpid());
  for (size_t i = 0; i < MAX; i++) {
    arry[i] = rand() % 100;
    printf("%d \n", arry[i]);
  }
  printf("未排序前:\n");
  int number = sizeof(arry) / sizeof(int);
  show(arry, number);
  function(arry, number);
  printf("排序后:\n");
  show(arry, number);
  return 0;
}

//冒泡排序
static void function(int *arry, int number) {
#if 0
  int temp; //用于交换
#endif
  for (size_t i = 0; i < number - 1; i++) {
    for (size_t j = 0; j < number - i - 1; j++) {
      if (arry[j] < arry[j + 1]) {
// swap
#if 0
        temp = arry[j];
        arry[j] = arry[j + 1];
        arry[j + 1] = temp;
#endif
        arry[j] = arry[j] ^ arry[j + 1];
        arry[j + 1] = arry[j] ^ arry[j + 1];
        arry[j] = arry[j] ^ arry[j + 1];
      }
    }
  }
}

static void show(int *arry, int number) {
  for (size_t i = 0; i < number; i++) {
    printf("%d ", arry[i]);
  }
  printf("\n");
}

int number_cmp(const void *data1, const void *data2) {
  const int *d1 = (const int *)data1;
  const int *d2 = (const int *)data2;
  return *d2 - *d1;
}
static void bubble_another(void *arry, int size, int n, fun_t fun) {
  char *buf = (char *)malloc(size);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (fun((char *)arry + j * size, (char *)arry + (j + 1) * size) > 0) {
        memcpy(buf, (char *)arry + j * size, size);
        memcpy((char *)arry + j * size, (char *)arry + (j + 1) * size, size);
        memcpy((char *)arry + (j + 1) * size, buf, size);
      }
    }
  }
}
