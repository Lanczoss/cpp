#include <math.h>

#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Line;

class Point {
 public:
  Point(float x, float y) : _ix(x), _iy(y) { cout << "Point()" << endl; }
  ~Point() { cout << "~Point()" << endl; }

  friend class Line;

 private:
  float _ix;
  float _iy;
};

class Line {
 public:
  Line(float x1, float y1, float x2, float y2) : _pt1(x1, y1), _pt2(x2, y2) {
    cout << "Line()" << endl;
  }

  ~Line() { cout << "~Line()" << endl; }

  float lineLength() const {
    return sqrt(pow(_pt1._ix - _pt2._ix, 2) + pow(_pt1._iy - _pt2._iy, 2));
  }

 private:
  Point _pt1;
  Point _pt2;
};

class Color {
 public:
  Color(const char *color) : _color(color) { cout << "Color()" << endl; }
  ~Color() { cout << "~Color()" << endl; }

  void printColor() const {
    cout << "颜色: " << _color << endl;
  }

 private:
  string _color;
};

class Triangle : public Line, public Color {
 public:
  Triangle(const char *color, float x1, float y1, float x2, float y2,
           float height)
      : Color(color), Line(x1, y1, x2, y2), _height(height) {}

  float calPerimeter() const {
    return sqrt(pow(lineLength(), 2) + pow(_height, 2)) + lineLength() + _height;
  }

  float calArea() const {
    return lineLength() * _height / 2;
  }

  void print() const {
    printColor();
    cout << "周长: " << calPerimeter() << endl;
    cout << "面积: " << calArea() << endl;
  }

 private:
  float _height;
};

int main() {
  Triangle t("red", 2, 3, 4, 5, 8);
  t.print();
  return 0;
}
