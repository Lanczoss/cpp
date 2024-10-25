#include "ThreadPool.h"

#include <iostream>

#include "Task.h"
using std::cout;
using std::endl;

ThreadPool::ThreadPool(size_t threadNum, size_t queueSize)
    : _threadNum(threadNum),
      _taskQueue(queueSize),
      _queueSize(queueSize),
      _isExit(false) {}

ThreadPool::~ThreadPool() {}

void ThreadPool::start() {
  // initialize _threads
  for (size_t idx = 0; idx < _threadNum; ++idx) {
    _threads.push_back(std::thread(&ThreadPool::doTask, this));
  }
}

void ThreadPool::stop() {
  // if want to process all the tasks in queue
  while (!_taskQueue.empty()) {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
  }

  _isExit = true;

  // wake up all
  _taskQueue.wakeup();

  for (auto &th : _threads) {
    th.join();
  }
}

void ThreadPool::addTask(ElemType newTask) {
  if (newTask) {
    _taskQueue.push(newTask);
  }
}

ThreadPool::ElemType ThreadPool::getTask() { return _taskQueue.pop(); }

// thread entry function
void ThreadPool::doTask() {
  // when thread can leave?
  while (!_isExit) {
    // pop will wait for newTask
    ElemType newTask = getTask();
    if (newTask) {
      newTask->process();
    } else {
      cout << "thread got a void task." << endl;
    }
  }
}
