#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main(void) {
  vector<vector<int>> nums{{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};
  for(auto &vvi : nums) {
    for(auto &vi : vvi) {
      cout << vi << " ";
    }
    cout << endl;
  }
}
