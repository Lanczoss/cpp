#ifndef TCPCONNECTION_H_
#define TCPCONNECTION_H_

#include <string>

#include "SocketIO.h"
using std::string;

class TcpConnection {
 public:
  TcpConnection(int fd);
  ~TcpConnection();
  void send(const string &msg);
  string receive();

 private:
  SocketIO _sockIO;
};

#endif  // !TCPCONNECTION_H_
