#include <deque>
#include <iostream>
#include <list>
using std::cout;
using std::deque;
using std::endl;
using std::list;
int main(void) {
  list<int> lst = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  deque<int> odd;
  deque<int> even;
  for (list<int>::iterator i = lst.begin(); i != lst.end(); ++i) {
    if (1 & *i) {
      // odd
      odd.push_back(*i);
    } else {
      even.push_back(*i);
    }
  }

  cout << "odd: " << endl;
  for (int &o : odd) {
    cout << o << " ";
  }
  cout << endl;

  cout << "even: " << endl;
  for (int &e : even) {
    cout << e << " ";
  }
  cout << endl;
}
