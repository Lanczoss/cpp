#include <iostream>
using std::cout;
using std::endl;

class A {
  void func() {}
  virtual void run() { cout << "A::run()" << endl; }
  virtual void run1() { cout << "A::run1()" << endl; }
  virtual void run2() { cout << "A::run2()" << endl; }
  double a = 10;
};

class B : virtual public A {
  void run() { cout << "B::run()" << endl; }
  void run1() { cout << "B::run1()" << endl; }
  double b = 1;
};

class C : virtual public A {
  virtual void run() { cout << "C::run()" << endl; }
  virtual void run1() { cout << "C::run1()" << endl; }
  virtual void run3() { cout << "C::run3()" << endl; }
};

int main() {
  cout << sizeof(A) << endl;
  cout << sizeof(B) << endl;
  cout << sizeof(C) << endl;

  C c;
  long *p = (long *)(&c);
  cout << p[0] << endl;
  cout << p[1] << endl;
  cout << p[2] << endl;

  cout << endl;
  long *pt = (long *)(p[0]);
  cout << pt[0] << endl;
  cout << pt[1] << endl;
  cout << pt[2] << endl;
}
