#include <iostream>
using std::cout;
using std::endl;

template <class T>
double add(T x) {
  return x;
}

template <class T, class... Args>
double add(T x, Args... args) {
  return x + add(args...);
}

int main(void) {
  int sum1 = add(1, 2, 3.1, 4, 5);
  cout << sum1 << endl;
  double sum2 = add(2, 3.1, 2.2, 2, 3);
  cout << sum2 << endl;
  return 0;
}
