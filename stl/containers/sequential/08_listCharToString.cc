#include <iostream>
#include <list>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main(void) {
  list<char*> lst = {"hello", "world", "!"};
  vector<string> vec;
  for (char*& c : lst) {
    vec.push_back(string(c));
  }
  for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it) {
    cout << *it << endl;
  }
}
