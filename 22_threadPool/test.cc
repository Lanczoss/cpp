#include "MyTask.h"
#include "Task.h"
#include "TaskQueue.h"
#include "ThreadPool.h"

int main(void) {
  std::unique_ptr<Task> ptask(new MyTask());

  // threadnum = 5
  // taskqueue size = 10
  ThreadPool tp(5, 10);

  // start threadpool
  tp.start();

  int count = 20;
  while (count--) {
    tp.addTask(ptask.get());
  }

  // stop threadpool
  tp.stop();
  return 0;
}
