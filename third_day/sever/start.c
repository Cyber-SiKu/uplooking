#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  //使子进程不变成僵尸进程
  struct sigaction act;
  act.sa_handler = SIG_IGN;
  act.sa_flags = SA_NOCLDWAIT;
  sigaction(SIGCHLD, &act, NULL);
  pid_t pid = fork();
  if (pid == 0) {
    // child
    // the sever of register is starting
    execl("./rgs_server", "./rgs_server", NULL);
    perror("execl()");
  }
  sleep(1);
  pid = fork();
  if (pid == 0) {
    execl("./login_server", "./login_server", NULL);
    perror("execl()");
  }
  while (1) {
    pause();
  }
}
