#include <iostream>
using std::cout;
using std::endl;

class FunctionObject {
 public:
  void operator()() { cout << "operator()()" << endl; }
};

int main(void) {
  FunctionObject fo;
  fo();
  return 0;
}
