#include <iostream>

#include "Acceptor.h"
#include "InetAddress.h"
#include "TcpConnection.h"
using std::cout;
using std::endl;

int main(int argc, char** argv) {
  Acceptor ac(argv[1], argv[2]);

  ac.ready();

  TcpConnection tcp(ac.accept());

  cout << tcp.toString() << endl;

  while (1) {
    cout << ">>recv msg from client: " << tcp.receive() << endl;
    tcp.send("receive once\n");
  }
  return 0;
}
