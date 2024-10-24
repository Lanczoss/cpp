#include "Consumer.h"

#include <iostream>
#include <thread>

#include "TaskQueue.h"
using std::cout;
using std::endl;
using namespace std::chrono_literals;

Consumer::Consumer() {}

Consumer::~Consumer() {}

void Consumer::consume(TaskQueue &taskqueue) {
  int count = 20;
  while (count--) {
    int num = taskqueue.pop();
    cout << "consume: " << num << endl;
    std::this_thread::sleep_for(1s);
  }
}
