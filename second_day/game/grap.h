#ifndef GRAPH_H_
#define GRAPH_H_

#include <signal.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define IMGMAX 4
//使用16进制数表示图形
static int IMG_Z[IMGMAX] = {0x08C4, 0x006C, 0x08C4, 0x006C};
// static int img_1[IMGMAX] = {};

typedef struct {
  int x_ = 1;
  int y_ = 30;
} Cooradinate_;

void alrm_handler(int s);

static void draw_gragh(int img, int color);

void init();

int main(int argc, char const *argv[]) {
  init();
  return 0;
}

void init() {
  struct termios oldTermios, newTermios;
  tcgetattr(0, &oldTermios);
  newTermios = oldTermios;
  newTermios.c_lflag = newTermios.c_lflag & ~ECHO;
  newTermios.c_lflag = newTermios.c_lflag & ~ICANON;
  tcsetattr(0, TCSANOW, &newTermios);
  draw_gragh(COLOR);
}

#endif
