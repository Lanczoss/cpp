#include "TcpConnection.h"

#include <stdio.h>

TcpConnection::TcpConnection(int fd)
    : _sockIO(fd), _localAddr(getLocalAddr()), _peerAddr(getPeerAddr()) {}

TcpConnection::~TcpConnection() {}

void TcpConnection::send(const string &msg) {
  _sockIO.writen(msg.data(), msg.size());
}

string TcpConnection::receive() {
  char buf[65535] = {0};
  _sockIO.readLine(buf, sizeof(buf));
  return buf;
}

InetAddress TcpConnection::getLocalAddr() {
  struct sockaddr_in addr;
  socklen_t length = sizeof(addr);
  int ret = getsockname(_sockIO.fd(), (struct sockaddr *)&addr, &length);
  if (-1 == ret) {
    perror("getsockname");
  }

  return InetAddress(addr);
}

InetAddress TcpConnection::getPeerAddr() {
  struct sockaddr_in addr;
  socklen_t length = sizeof(addr);
  int ret = getpeername(_sockIO.fd(), (struct sockaddr *)&addr, &length);
  if (-1 == ret) {
    perror("getpeername");
  }

  return InetAddress(addr);
}

string TcpConnection::toString() {
  return _localAddr.ip() + ":" + _localAddr.port() + " <-----> " +
         _peerAddr.ip() + ":" + _peerAddr.port() + " connected";
}

bool TcpConnection::isClosed() const {
  char buf[10] = {0};
  int ret = ::recv(_sockIO.fd(), buf, sizeof(buf), MSG_PEEK);
  return (0 == ret);
}
