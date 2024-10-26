#include <deque>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::string;

int main(void) {
  string str;
  deque<string> dstr;
  while (true) {
    cin >> str;
    if (str == "q") {
      break;
    }
    dstr.push_back(str);
  }

  for (auto it = dstr.begin(); it != dstr.end(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
