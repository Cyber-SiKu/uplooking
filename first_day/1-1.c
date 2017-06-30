#include <stdio.h>

int main(int argc, char const *argv[]) {
  int valueHeight = 0; // value_height
  printf("input the number:\n");
  do {
    scanf("%d", &valueHeight);
  } while (valueHeight <= 0);
  printf("the number is %d .\n", valueHeight);

  if (valueHeight % 2 == 0) {
    printf("%s\n", "偶数");
  } else {
    if (valueHeight > 10) {
      // sum of 1 to valueHeight
      int sum = 0;
      for (size_t i = 1; i <= valueHeight; i++) {
        sum += i;
      }
      printf("前 n 项和 : %d.", sum);
    }
    printf("%s\n", "奇数");
  }
#if 0
    swirvh(vlaueHeight % 2){
    case 0:
    case 1:
    defalut:
  }
#endif
  return 0;
}
