#ifndef ACCEPTOR_H_
#define ACCEPTOR_H_

#include <string>

#include "InetAddress.h"
#include "Socket.h"
using std::string;

class Acceptor {
 public:
  Acceptor(const string &ip, const string &port);
  ~Acceptor();
  // return fd
  int accept();
  void ready();

 private:
  void setReuseAddr();
  void setReusePort();
  void bind();
  void listen();

 private:
  Socket _sock;
  InetAddress _addr;
};

#endif  // !ACCEPTOR_H_
