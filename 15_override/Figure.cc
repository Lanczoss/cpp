#include <math.h>

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Figure {
 public:
  virtual string getName() const = 0;
  virtual double getArea() const = 0;
};

class Rectangle : public Figure {
 public:
  Rectangle(double length, double width) : _length(length), _width(width) {}

  string getName() const override { return "矩形"; }

  double getArea() const override { return _length * _width; }

 private:
  double _length;
  double _width;
};

//#define PI 3.14
class Circle : public Figure {
 public:
  Circle(double radius) : _radius(radius) {}

  string getName() const override { return "圆形"; }

  double getArea() const override { return PI * _radius * _radius; }

 private:
  static constexpr double PI = 3.14;
  //static const double PI;
  double _radius;
};
//const double Circle::PI = 3.14;

class Triangle : public Figure {
 public:
  Triangle(double edge1, double edge2, double edge3)
      : _edge1(edge1), _edge2(edge2), _edge3(edge3) {}

  string getName() const override { return "三角形"; }

  double getArea() const override {
    double p = (_edge1 + _edge2 + _edge3) / 2;
    return sqrt(p * (p - _edge1) * (p - _edge2) * (p - _edge3));
  }

 private:
  double _edge1;
  double _edge2;
  double _edge3;
};

void display(Figure& fig) {
  cout << fig.getName() << "的面积是:" << fig.getArea() << endl;
}

void test() {
  Rectangle r(10, 20);
  Circle c(15);
  Triangle t(3, 4, 5);
  display(r);
  display(c);
  display(t);
}

int main(void) {
  test();
  return 0;
}