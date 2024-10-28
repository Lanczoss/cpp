#ifndef EVENTLOOP_H_
#define EVENTLOOP_H_

#include <map>
#include <memory>
#include <vector>
using std::map;
using std::shared_ptr;
using std::vector;

class TcpConnection;

class Acceptor;

class EventLoop {
 public:
  // get socket_fd to do work
  EventLoop(Acceptor &);
  ~EventLoop();
  void loop();

 private:
  void unloop();
  void addEpollReadFd(int newFd);
  void delEpollReadFd(int delFd);
  void waitEpollFd();
  int createEpollFd();
  void handleNewConnecion();
  void handleMessage(int netFd);

 private:
  int _epfd;
  vector<struct epoll_event> _evtList;
  bool _isLooping;
  Acceptor &_acceptor;
  map<int, shared_ptr<TcpConnection>> _conns;
};

#endif  // !EVENTLOOP_H_
