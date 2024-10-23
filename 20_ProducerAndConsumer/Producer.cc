#include "Producer.h"

#include "TaskQueue.h"

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
  }
}
