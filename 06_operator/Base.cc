#include <iostream>
using std::cout;
using std::endl;

class Base {
 public:
  Base(int base) : _base(base) {}

  //只需将加号运算符重载为相减数据成员即可
  friend int operator+(const Base &lhs, const Base &rhs);

 private:
  int _base;
};

int operator+(const Base &lhs, const Base &rhs) {
  return rhs._base - lhs._base;
}

int main(void) {
  int i = 2;
  int j = 7;

  Base x(i);
  Base y(j);
  cout << (x + y == j - i) << endl;
  return 0;
}
