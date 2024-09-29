#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main() {
  string s1("hello");
  s1+=s1;
  cout << s1 << endl;
  return 0;
}
