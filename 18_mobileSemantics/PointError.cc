#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Point : public std::enable_shared_from_this<Point> {
 public:
  Point(int x, int y) : _ix(x), _iy(y) {}
  ~Point() {}

  shared_ptr<Point> addPoint() { return shared_from_this(); }

 private:
  int _ix;
  int _iy;
};

int main() {
  Point *p = new Point(1, 2);
  shared_ptr<Point> sp(p);
  cout << sp.use_count() << endl;
  shared_ptr<Point> sp2 = p->addPoint();
  cout << sp2.use_count() << endl;
  shared_ptr<Point> sp3(p);
  cout << sp3.use_count() << endl;
  shared_ptr<Point> sp4 = p->addPoint();
  cout << sp4.use_count() << endl;
  cout << sp.use_count() << endl;
  cout << sp2.use_count() << endl;
  cout << sp3.use_count() << endl;
  cout << sp4.use_count() << endl;
}
