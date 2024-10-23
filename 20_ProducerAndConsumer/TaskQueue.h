#ifndef TASKQUEUE_H_
#define TASKQUEUE_H_

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
using std::condition_variable;
using std::mutex;
using std::queue;
using std::unique_lock;

class TaskQueue {
 public:
  TaskQueue(int);
  ~TaskQueue();
  void push(const int &value);
  int pop();
  bool empty() const;
  bool full() const;

 private:
  size_t _capacity;
  queue<int> _que;
  mutex _mutex;
  condition_variable _notFull;
  condition_variable _notEmpty;
};

#endif
