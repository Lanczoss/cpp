#include <functional>
#include <thread>

#include "Consumer.h"
#include "Producer.h"
#include "TaskQueue.h"

using std::thread;

void test() {
  Producer pr;
  Consumer co;

  TaskQueue taskQue(10);

  thread pro(&Producer::produce, &pr, std::ref(taskQue));
  thread con(&Consumer::consume, &co, std::ref(taskQue));

  pro.join();
  con.join();
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
