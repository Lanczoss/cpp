#include <math.h>

#include <iostream>
#include <ostream>
#include <set>
using std::cout;
using std::endl;
using std::set;

class Point {
 public:
  Point(int x, int y) : _ix(x), _iy(y) {}

  friend std::ostream &operator<<(std::ostream &os, const Point &);

  int getX() const { return _ix; }

  int getY() const { return _iy; }

 private:
  int _ix;
  int _iy;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs) {
  os << "x: " << rhs._ix << endl << "y: " << rhs._iy << endl;
  return os;
}

template <typename Containers>
void print(Containers con) {
  for (auto &c : con) {
    cout << c << endl;
  }
  cout << endl;
}

// // 模板特化
// template <>
// struct std::less<Point> {
// bool operator()(const Point &lhs, const Point &rhs) const {
//  if (hypot(lhs.getX(), lhs.getY()) < hypot(rhs.getX(), rhs.getY())) {
// return true;
//  } else {
// return false;
//  }
//  }
// };
//

// // 运算符重载
// bool operator<(const Point &lhs, const Point &rhs) {
//   if (hypot(lhs.getX(), lhs.getY()) < hypot(rhs.getX(), rhs.getY())) {
//     return true;
//   } else {
//     return false;
//   }
// }
//

// 函数对象
struct ComparePoint {
  bool operator()(const Point &lhs, const Point &rhs) const {
    if (hypot(lhs.getX(), lhs.getY()) < hypot(rhs.getX(), rhs.getY())) {
      return true;
    } else {
      return false;
    }
  }
};

int main(void) {
  set<Point, ComparePoint> sp = {
      Point(5, 6),
      Point(1, 2),
      {3, 4},
  };
  print(sp);
  return 0;
}
