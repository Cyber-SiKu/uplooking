#include <stdio.h>

//交换
void swap2num(int *num1, int *num2) {
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int main(int argc, char const *argv[]) {
  int a = 10;
  int b = 100;
  swap2num(&a, &b);

  /*
  * 两种代码效果等同
  * 不能使用p/p_来改变a的值
  */
  const int *p = &a;
  int const *p_ = &b;

  /** 不能改变p__的指向 */
  int *const p__ = &b;

  printf("a:%d b:%d\n", a, b);
  return 0;
}
