#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

// 通用模板
template <class T> T add(T a, T b) { return a + b; }

// 特化模板
template <> set<int> add<set<int>>(set<int> a, set<int> b) {
  set<int> temp = a;
  temp.insert(b.begin(), b.end());
  return temp;
}

int main(void) {
  int i1 = 10, i2 = 12;
  double d1 = 4.7, d2 = 3.8;
  cout << add(i1, i2) << endl;
  cout << add(d1, d2) << endl;
  set<int> nums1{1, 2};
  set<int> nums2{2, 7, 3, 4, 10};
  set<int> nums3 = add<set<int>>(nums1, nums2);
  for (auto &s : nums3) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}
