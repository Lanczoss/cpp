#include <iostream>

#include "Line.hpp"
using std::cout;
using std::endl;

class Line::LineImpl {
  class Point {
   public:
    Point(int x, int y) : _ix(x), _iy(y) {}

    void print() const { cout << "(" << _ix << ", " << _iy << ")"; }

   private:
    int _ix;
    int _iy;
  };

 public:
  LineImpl(int x1, int y1, int x2, int y2) : pt1(x1, y1), pt2(x2, y2) {}

  void printLine() const {
    pt1.print();
    cout << " ------> ";
    pt2.print();
    cout << endl;
  }

 private:
  Point pt1;
  Point pt2;
};

Line::Line(int x1, int y1, int x2, int y2)
    : _pimpl(new LineImpl(x1, y1, x2, y2)) {}

Line::~Line() {
  if (_pimpl) {
    delete _pimpl;
    _pimpl = nullptr;
  }
}

void Line::printLine() const { _pimpl->printLine(); }
