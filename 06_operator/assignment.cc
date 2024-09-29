#include <iostream>
using std::cout;
using std::endl;

//前向声明
class Point;

class Complex {
 public:
  Complex(int real, int image) : _real(real), _image(image) {}

  void print() const { cout << _real << " + " << _image << "i" << endl; }

  Complex & operator=(const Point &);

  Complex(const Point &);

 private:
  int _real;
  int _image;
};

class Point {
 public:
  Point(int x, int y) : _ix(x), _iy(y) {}

  //类型转换函数
  operator Complex() {
    cout << "类型转换函数" << endl;
    return Complex(_ix, _iy);
  }

  //声明Complex是Point的友元类
  friend class Complex;

 private:
  int _ix;
  int _iy;
};

//赋值运算符函数重载
Complex & Complex::operator=(const Point & rhs) {
  cout << "赋值运算符函数" << endl;
  _real = rhs._ix;
  _image = rhs._iy;
  return *this;
}

//隐式转换
Complex::Complex(const Point &rhs) : _real(rhs._ix), _image(rhs._iy) {
  cout << "隐式转换" << endl;
}

int main(void) {
  Point pt(8, 9);
  Complex cx(4, 6);
  cx = pt;
  cx.print();
  return 0;
}
