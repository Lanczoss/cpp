#include "Producer.h"

#include <iostream>
#include <thread>

#include "TaskQueue.h"
using namespace std::chrono_literals;

Producer::Producer() {}
Producer::~Producer() {}

void Producer::produce(TaskQueue &taskqueue) {
  // produce random numbers
  ::srand(::time(NULL));
  int count = 20;
  while (count--) {
    int temp = ::rand() % 100;
    taskqueue.push(temp);
    std::cout << "produce: " << temp << std::endl;
    std::this_thread::sleep_for(1s);
  }
}
