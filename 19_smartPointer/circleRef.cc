#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Child;
class Parent {
 public:
  Parent() { cout << "Parent()" << endl; }
  ~Parent() { cout << "~Parent()" << endl; }
  weak_ptr<Child> _wpChild;
};

class Child {
 public:
  Child() { cout << "Child()" << endl; }
  ~Child() { cout << "~Child()" << endl; }
  shared_ptr<Parent> _spParent;
};

int main() {
  shared_ptr<Parent> parentPtr(new Parent());
  shared_ptr<Child> childPtr(new Child());
  parentPtr->_wpChild = childPtr;
  childPtr->_spParent = parentPtr;
  return 0;
}
