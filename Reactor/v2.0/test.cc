#include "Acceptor.h"
#include "EventLoop.h"
#include "InetAddress.h"

int main(int argc, char** argv) {
  Acceptor ac(argv[1], argv[2]);

  ac.ready();

  EventLoop eventloop(ac);

  eventloop.loop();

  return 0;
}
