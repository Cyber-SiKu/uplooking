#include "../NetTalk/protocal.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <signal.h>
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

static int rgshandler(const struct rgs_st *rcv);

int main(int argc, char const *argv[]) {
  //使子进程不变成僵尸进程
  struct sigaction act;
  act.sa_handler = SIG_IGN;
  act.sa_flags = SA_NOCLDWAIT;
  sigaction(SIGCHLD, &act, NULL);

  //创建数据库>>并创建注册表
  sqlite3 *db = NULL;
  int ret = sqlite3_open("./nettalk.sqlite3", &db);
  if (ret != SQLITE_OK) {
    fprintf(stderr, "%s\n", "sqlite3_open() failed");
    exit(1);
  }

  const char *sql =
      "create table if not exists rgsTable(no integer primary key "
      "autoincrement not null,count text not null ,passwd text "
      "not null)";

  char *errmsg = NULL;
  ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
  if (ret != SQLITE_OK) {
    fprintf(stderr, "sqlite3_exec():%s1\n", errmsg);
    goto ERROR1;
  }
  sqlite3_close(db);

  //初始化与客户端通信的报式套接字
  int sd;
  sd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sd < 0) {
    perror("socket()");
    goto ERROR2;
  }

  struct sockaddr_in laddr;
  laddr.sin_family = AF_INET; // ipv4
  laddr.sin_port = htons(REGISTER_SEVER_PORT);
  inet_aton(REGISTER_SEVER_IP, &laddr.sin_addr);

  //收发数据包
  struct sockaddr_in raddr;
  socklen_t raddrlen;
  raddrlen = sizeof(raddr);
  struct rgs_st rcvbuf;
  while (1) {
    recvfrom(sd, &rcvbuf, sizeof(rcvbuf), 0, (struct sockaddr *)&raddr,
             &raddrlen);
    if (ret < 0) {
      perror("recvfrom()");
      goto ERROR3;
    }
    pid_t pid = fork();
    if (pid < 0) {
      perror("fork()");
      goto ERROR3;
    }
    if (pid == 0) {
      // child-->traval 注册表
      ret = rgshandler(&rcvbuf);
      if (ret == 0) {
        rcvbuf.statues = REGISTER_STATUS_OK;
      } else if (ret == 1) {
        rcvbuf.statues = REGISTER_STATUS_FAIL;
      }
      sendto(sd, &rcvbuf, sizeof(rcvbuf), 0, (struct sockaddr *)&raddr,
             raddrlen);
      exit(0);
    }
  }

  exit(0);

ERROR1:
  sqlite3_close(db);
  exit(1);
ERROR3:
  close(sd);
ERROR2:
  exit(1);
}

static int rgshandler(const struct rgs_st *rcv) {
  //打开数据库-->traval注册表->查看是否有rcv->count->有statues=1否则0
  sqlite3 *db;
  int ret = sqlite3_open("./nettalk.sqlite3", &db);
  if (ret < 0) {
    fprintf(stderr, "%s\n", "sqlite3_open()failed");
    goto ERROR1;
  }

  const char *sql;
  sql = "select * from rgsTable where count = ?";
  sqlite3_stmt *stmt;
  sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  sqlite3_bind_text(stmt, 1, rcv->count, -1, NULL);
  ret = sqlite3_step(stmt);
  if (ret != SQLITE_ROW && ret != SQLITE_DONE) {
    fprintf(stderr, "%s\n", "sqlite3_step()failed");
    goto ERROR2;
  }
  sqlite3_finalize(stmt);
  if (ret == SQLITE_ROW) {
    sqlite3_close(db);
    //账户已存在==>注册失败
  } else {
    //可以注册
    sql = "insert into rgsTable(count, passwd) values(?,?)";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, rcv->count, -1, NULL);
    sqlite3_bind_text(stmt, 2, rcv->password, -1, NULL);
    ret = sqlite3_step(stmt);
    if (ret != SQLITE_DONE) {
      fprintf(stderr, "%s\n", "sqlite3_step() fqiled");
      goto ERROR2;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
  }

ERROR2:
  sqlite3_finalize(stmt);
  sqlite3_close(db);
ERROR1:
  return -1;
}
