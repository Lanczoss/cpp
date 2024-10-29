#include <iostream>

#include "InetAddress.h"
#include "MyTask.h"
#include "TcpConnection.h"
#include "TcpServer.h"
#include "ThreadPool.h"
using std::cout;
using std::endl;

ThreadPool *gPool = nullptr;

// TcpConnectionPtr
// 连接建立
void onNewConnection(const TcpConnectionPtr &con) {
  cout << con->toString() << " has connected!!!" << endl;
}

// 文件描述符可读，读客户端的数据
void onMessage(const TcpConnectionPtr &con) {
  string msg = con->receive();
  cout << ">>recv msg from client: " << msg << endl;

  // 接收到客户端的数据之后，可以将数据做业务逻辑的处理
  // add the task(msg) to threadPool

  MyTask mt(msg, con);

  gPool->addTask([&mt]() { mt.process(); });

  // Task can send now
  // con->send(msg);
}

// 连接断开
void onClose(const TcpConnectionPtr &con) {
  cout << con->toString() << " has closed!!!" << endl;
}

int main(int argc, char **argv) {
  TcpServer tcp(argv[1], argv[2]);

  ThreadPool pool(4, 10);
  gPool = &pool;

  tcp.setAllCallback(std::move(onNewConnection), std::move(onMessage),
                     std::move(onClose));

  tcp.start();

  tcp.stop();
  return 0;
}
