#ifndef SOCKETIO_H_
#define SOCKETIO_H_

#include "Socket.h"

class SocketIO {
 public:
  SocketIO(int fd);
  ~SocketIO();
  int readn(void *buf, int length);
  int writen(const char *buf, int length);
  int readLine(void *buf, int length);

 private:
  Socket _netSock;
};

#endif  // !SOCKETIO_H_
