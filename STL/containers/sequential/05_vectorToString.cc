#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(void) {
  vector<char> vc = {'H', 'E', 'L', 'L', 'O'};
  // string str;
  // for (auto &ch : vc) {
  //   str.push_back(ch);
  // }
  // string str(vc.begin(), vc.end());
  string str(vc.data(), vc.size());
  cout << str << endl;
}
