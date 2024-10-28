#include "TcpConnection.h"

TcpConnection::TcpConnection(int fd) : _sockIO(fd) {}

TcpConnection::~TcpConnection() {}

void TcpConnection::send(const string &msg) {
  _sockIO.writen(msg.data(), msg.size());
}

string TcpConnection::receive() {
  char buf[65535] = {0};
  _sockIO.readLine(buf, sizeof(buf));
  return buf;
}
