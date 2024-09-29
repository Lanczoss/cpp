#include "Mylogger.hh"
#include <iostream>
using std::cout;
using std::endl;

int main() {
  Mylogger::getInstance()->warn("this is a warn msg");
  Mylogger::destroy();
  return 0;
}
