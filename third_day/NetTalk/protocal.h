#ifndef PROTOCAL_H
#define PROTOCAL_H

#pragma pack(1) //设置1(必须是2^n)字节对齐

#define DEFAULT_IP "127.0.0.1"
#define TEARHCER_IP "192.168.100.32"

//注册
#define REGISTER_SEVER_IP TEARHCER_IP
#define REGISTER_SEVER_PORT 1111
#define SIZE 11
#define REGISTER_STATUS_OK 0
#define REGISTER_STATUS_FAIL 1

struct rgs_st {
  char count[SIZE];
  char password[SIZE];
  int statues; // sever 给 client 是否发送成功
};

#endif // PROTOCAL_H
