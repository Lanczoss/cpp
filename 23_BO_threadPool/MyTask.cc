#include "MyTask.h"

#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

void MyTask::process(int x) {
  // mission main logic!!!!!!!!!!

  ::srand(::clock());
  cout << "process: " << ::rand() % 100 << endl;
}
