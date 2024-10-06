#include <iostream>
using std::cout;
using std::endl;

// template <class T1, class T2>
// T1 add(T1 t1, T2 t2) {
//   return t1 + t2;
// }

template <class T1, class T2>
T1 add(T2 t2, T1 t1) {
  return t1 + t2;
}

int main(void) {
  int i = 10;
  double d = 3.7;
  cout << add(i, d) << endl;
  return 0;
}
