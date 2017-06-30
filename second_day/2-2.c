#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void int_handler(int s);

int main(int argc, char const *argv[]) {
  // signal(2 /*SIGNT*/, int_handler);
  signal(SIGALRM, int_handler);
  alarm(1);
  while (1) {
    pause();
#if 0
    printf("*");
    fflush(stdout);
    sleep(1);
#endif
  }
  return 0;
}

void int_handler(int s) {
  alarm(1);
  write(1, "!", 1);
  printf("\33[44m\33[10;20H!");
}
