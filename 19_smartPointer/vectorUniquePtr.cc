#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

class Point {
 public:
  Point(int x, int y) : _ix(x), _iy(y) { cout << "Point()" << endl; }
  ~Point() { cout << "~Point()" << endl; }

  void print() const { cout << "(" << _ix << ", " << _iy << ")" << endl; }

 private:
  int _ix;
  int _iy;
};

int main() {
  unique_ptr<Point> up(new Point(1, 2));
  unique_ptr<Point> up2(new Point(3, 4));
  unique_ptr<Point> up3(new Point(5, 6));
  vector<unique_ptr<Point>> vec;
  vec.push_back(std::move(up));
  vec.push_back(std::move(up2));
  vec.push_back(std::move(up3));
  for (auto &unp : vec) {
    unp->print();
  }
  vec.push_back(unique_ptr<Point>(new Point(1, 2)));
  return 0;
}
