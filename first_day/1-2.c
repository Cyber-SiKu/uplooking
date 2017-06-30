/*
40 人 1圈 1-40  3号退出
*/

#include <stdio.h>

void init_people(int pepole[]);

void run(int pepole[]);

int remain(int pepole[]);

int main(int argc, char const *argv[]) {
  int pepole[40];

  init_people(pepole);

  run(pepole);

  printf("remain : %d\n", remain(pepole));

  return 0;
}

void init_people(int pepole[]) {
  for (size_t i = 0; i < 40; i++) {
    pepole[i] = 0;
  }
}

void run(int pepole[]) {
  int i = 0;
  int count = 0;
  int killed = 0;
  while (killed != 39) {
    if (i % 40 == 0) {
      // 下标 40 归零
      i = 0;
    }
    if (pepole[i] == 1) {
      i++; //已退出的人跳过
      continue;
    } else if (count % 3 == 2) {
      //应退出
      count = 0;
      pepole[i] = 1;
      killed++;
    } else {
      //非退出人
      i++;
      count++;
    }
  }
}

int remain(int pepole[]) {
  int remain = 0;
  for (size_t i = 0; i < 40; i++) {
    if (pepole[i] == 0) {
      remain = i;
      break;
    }
  }
  return remain + 1;
}
