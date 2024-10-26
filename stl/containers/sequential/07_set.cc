#include <set>
using std::set;
int main() {
  set<int> n = {1, 3, 4, 5, 67, 2, 3};
  set<int>::size_type cnt = n.count(4);

  for (auto it = n.begin(); it != n.end();) {
    if (1 == (*it & 1)) {
      n.erase(it);
    } else {
      ++it;
    }
  }
  auto it = n.begin();
  // *it = 100;
  return 0;
}
