#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Point {
 public:
  Point(int xx = 0, int yy = 0) {
    X = xx;
    Y = yy;
  }

  Point(const Point &p);

  int GetX() { return X; }

  int GetY() { return Y; }

 private:
  int X, Y;
};

Point::Point(const Point &p) : X(p.X), Y(p.Y) {}

int main(void) {
  vector<Point> points{{2, 6}, {3, 7}};
  points.push_back(Point(1, 3));
  points.push_back(Point(4, 5));
  points.push_back(Point(1, 5));
  points.push_back(Point(4, 9));

  for (Point &pt : points) {
    cout << "x = " << pt.GetX() << ", y = " << pt.GetY() << endl;
  }
  return 0;
}
