#include "Consumer.h"

#include "TaskQueue.h"
using std::cout;
using std::endl;

Consumer::Consumer() {}

Consumer::~Consumer() {}

void Consumer::consume(TaskQueue &taskqueue) {
  int count = 20;
  while (count--) {
    int num = taskqueue.pop();
    cout << "consume: " << num << endl;
  }
}
