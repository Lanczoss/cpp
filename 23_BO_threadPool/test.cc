#include "MyTask.h"
#include "ThreadPool.h"

int main(void) {
  std::unique_ptr<MyTask> ptask(new MyTask());

  // threadnum = 5
  // taskqueue size = 10
  ThreadPool tp(5, 10);

  // start threadpool
  tp.start();

  int count = 20;
  while (count--) {
    tp.addTask([&ptask]() { ptask.get()->process(10); });
  }

  // stop threadpool
  tp.stop();
  return 0;
}
