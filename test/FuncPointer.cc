#include <iostream>
using std::cout;
using std::endl;

typedef void (*Function) (int);

void print(int num) {
  cout << "num = " << num << endl;
}

int main(void) {
  Function fp = print;
  fp(1);
  return 0;
}
