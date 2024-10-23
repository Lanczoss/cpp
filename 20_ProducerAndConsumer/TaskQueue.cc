#include "TaskQueue.h"

TaskQueue::TaskQueue(int capacity)
    : _capacity(capacity), _que(), _mutex(), _notFull(), _notEmpty() {}

TaskQueue::~TaskQueue() {}

void TaskQueue::push(const int &value) {
  // get the lock
  // _mutex.lock();
  // condition_variable needs unique_lock
  unique_lock<mutex> m(_mutex);
  // check isFull
  while (full()) {
    // wait
    // std::cout << "one producer wait" << std::endl;
    _notFull.wait(m);
  }
  // push in queue
  _que.push(value);
  // notify consumer
  // std::cout << "one producer notify" << std::endl;
  _notEmpty.notify_one();
  // m.unlock();
}

int TaskQueue::pop() {
  // get the lock
  unique_lock<mutex> m(_mutex);
  while (empty()) {
    // std::cout << "one consumer wait" << std::endl;
    // wait
    _notEmpty.wait(m);
  }
  // pop from queue
  int temp = _que.front();
  _que.pop();

  // std::cout << "one consumer notify" << std::endl;
  _notFull.notify_one();
  // m.unlock();
  return temp;
}

bool TaskQueue::empty() const { return 0 == _que.size(); }

bool TaskQueue::full() const { return _capacity == _que.size(); }
