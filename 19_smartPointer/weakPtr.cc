#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

int main(void) {
  shared_ptr<int> sp(new int(10));
  weak_ptr<int> wp;
  wp = sp;
  shared_ptr<int> sp2 = wp.lock();
  cout << *sp << endl;
  cout << *sp2 << endl;
  return 0;
}
