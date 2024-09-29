#include <iostream>
using std::cout;
using std::endl;

class FFF {
 public:
  void print(int num) { cout << "num = " << num << endl; }
};

typedef void (FFF::*MemberFunc)(int);

int main(void) {
  MemberFunc p = &FFF::print;
  FFF f;
  (f.*p)(20);
  return 0;
}
