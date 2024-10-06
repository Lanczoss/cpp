#include <iostream>
using std::cout;
using std::endl;

int add(int x) { return x; }

double add(double x) { return x; }

template <class T, class... Args>
T add(T x, Args... args) {
  T sum = 0;
  sum += x + add(args...);
  return sum;
}

int main(void) {
  int sum1 = add(1, 2, 3, 4, 5);
  cout << sum1 << endl;
  double sum2 = add(3.1, 2.2, 2, 3);
  cout << sum2 << endl;
  return 0;
}
