#include <iostream>
#include <limits>
using std::cout;
using std::endl;
using std::cin;

int main(void) {
  int num;
  cin >> num;
  if(!cin.good()) {
    cin.clear();//修改状态标志
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  cout << "num = " << num << endl;
  cin >> num;
  cout << "num = " << num << endl;
  return 0;
}
