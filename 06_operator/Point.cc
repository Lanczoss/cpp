#include <iostream>
using std::cout;
using std::endl;

class Point {
 public:
  Point(int x = 0, int y = 0) : _ix(x), _iy(y) {}

  void print() const { cout << "x = " << _ix << ", y = " << _iy << endl; }

  //加法不改变操作数的值使用友元函数
  friend Point operator+(const Point &lhs, const Point &rhs);

  //+= 使用成员函数
  Point &operator+=(Point &rhs) {
    _ix += rhs._ix;
    _iy += rhs._iy;
    return *this;
  }

  //前置++
  Point &operator++() {
    ++_ix;
    ++_iy;
    return *this;
  }

  //后置++
  Point operator++(int) {
    Point temp(*this);
    ++_ix;
    ++_iy;
    return temp;
  }

 private:
  int _ix;
  int _iy;
};

Point operator+(const Point &lhs, const Point &rhs) {
  return Point(lhs._ix + rhs._ix, lhs._iy + rhs._iy);
}

int main(void) {
  Point pt1(1, 2);
  Point pt2(3, 4);
  Point pt3 = pt1 + pt2;
  pt3.print();
  pt3 += pt2;
  pt3.print();

  ++pt3;
  pt3.print();

  pt3++;
  pt3.print();
  return 0;
}
