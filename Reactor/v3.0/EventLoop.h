#ifndef EVENTLOOP_H_
#define EVENTLOOP_H_

#include <functional>
#include <map>
#include <memory>
#include <vector>
using std::function;
using std::map;
using std::shared_ptr;
using std::vector;

class TcpConnection;

class Acceptor;

using TcpConnectionPtr = shared_ptr<TcpConnection>;
using TcpConnectionCallback = function<void(const TcpConnectionPtr &)>;

class EventLoop {
 public:
  // get socket_fd to do work
  EventLoop(Acceptor &);
  ~EventLoop();
  void loop();
  void unloop();

 private:
  void addEpollReadFd(int newFd);
  void delEpollReadFd(int delFd);
  void waitEpollFd();
  int createEpollFd();
  void handleNewConnecion();
  void handleMessage(int netFd);

 public:
  // connected event
  void setNewConnectionCallback(TcpConnectionCallback &&cb);
  // Message arrived event
  void setMessageCallback(TcpConnectionCallback &&cb);
  // disconnected event
  void setCloseCallback(TcpConnectionCallback &&cb);

 private:
  TcpConnectionCallback _onNewConnection;
  TcpConnectionCallback _onMessage;
  TcpConnectionCallback _onClose;

 private:
  int _epfd;
  vector<struct epoll_event> _evtList;
  bool _isLooping;
  Acceptor &_acceptor;
  map<int, shared_ptr<TcpConnection>> _conns;
};

#endif  // !EVENTLOOP_H_
