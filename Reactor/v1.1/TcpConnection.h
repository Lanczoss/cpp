#ifndef TCPCONNECTION_H_
#define TCPCONNECTION_H_

#include "InetAddress.h"
#include "SocketIO.h"

class TcpConnection {
 public:
  explicit TcpConnection(int fd);
  ~TcpConnection();
  void send(const string &msg);
  string receive();

  string toString();

 private:
  // get ip and port
  InetAddress getLocalAddr();
  InetAddress getPeerAddr();

 private:
  SocketIO _sockIO;
  InetAddress _localAddr;
  InetAddress _peerAddr;
};

#endif  // !TCPCONNECTION_H_
