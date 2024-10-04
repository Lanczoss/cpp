#include <iostream>

using std::cout;
using std::endl;

class A {
 public:
  int x;
  A(int a = 0) { x = a; }
  void display() { cout << "A.x = " << x << endl; }
};
class B {
 public:
  int x;
  B(int a = 0) { x = a; }

  void display() { cout << "B.x = " << x << endl; }
};

class C : public A, public B {
 public:
  C(int a, int b, int c) : A(a), B(b) { y = c; }

  int gety() { return y; }
  int x;
  void display() { cout << "C.x = " << x << endl; }
 private:
  int y;
};
int main() {
  C myc(1, 2, 3);
  myc.x = 10;
  myc.display();

  return 0;
}