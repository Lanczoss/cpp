#include <algorithm>
#include <iostream>
#include <vector>

using std::remove_if;
int main() {
  std::vector<int> vec = {1, 3, 5, 8, 6, 4, 7, 9};
  vec.erase(remove_if(vec.begin(), vec.end(),
                      [](int value) -> bool { return value > 6; }),
            vec.end());
  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << std::endl;
  }
}
