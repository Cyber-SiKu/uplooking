#include <signal.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int COLOR = 40;

static int graph[4]
                [4] = {{0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};

static int x = 1, y = 30; // the cooradinate

void alrm_handler(int s);

static void draw_gragh(int color);

int main(int argc, char const *argv[]) {
  struct termios old, new;
  tcgetattr(0, &old);
  new = old;
  new.c_lflag = new.c_lflag & ~ECHO;
  new.c_lflag = new.c_lflag & ~ICANON;
  tcsetattr(0, TCSANOW, &new);
  draw_gragh(COLOR);

  signal(SIGALRM, alrm_handler);
  alarm(1);
  char buf = 'd';
  while (1) {
    buf = getchar();
    switch (buf) {
    case 'w':
      COLOR = (COLOR + 1) % 7 + 40;
      break;
    }
  }
  return 0;
}

static void draw_gragh(int color) {
  printf("\33[2J");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (graph[i][j]) {
        printf("\33[%dm\33[%d;%dH[]", color, x + i, y + j * 2);
        printf("\33[0m");
        fflush(NULL);
      }
    }
  }
  printf("\n");
}

void alrm_handler(int s) {
  alarm(1);
  // down
  x++;
  draw_gragh(COLOR);
}
