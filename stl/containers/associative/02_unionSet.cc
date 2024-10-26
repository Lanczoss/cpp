#include <iostream>
#include <set>
using std::cin;
using std::cout;
using std::endl;
using std::set;

int main(void) {
  set<int> s;
  int cA, cB;
  cin >> cA >> cB;
  int temp;
  for (int idx = 0; idx < cA + cB; ++idx) {
    cin >> temp;
    s.insert(temp);
  }

  for (const int &i : s) {
    cout << i << " ";
  }
  cout << endl;
}
