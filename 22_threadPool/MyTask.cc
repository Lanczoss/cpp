#include "MyTask.h"

#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

void MyTask::process() {
  ::srand(::clock());
  cout << "process: " << ::rand() % 100 << endl;
}
