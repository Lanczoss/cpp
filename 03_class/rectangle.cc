#include <iostream>
using std::cout;
using std::endl;

class Rectangle {
public:
    Rectangle(double length, double width)
        : _length(length),
        _width(width) {
            cout << "length = " << _length << endl;
            cout << "width = " << _width << endl;
        }

    void printPerimeter(void) {
        cout << "Perimeter = " << (_length + _width) * 2 << endl; 
    }

    void printArea(void) {
        cout << "Area = " << _length * _width << endl;
    }
private:
    double _length;
    double _width;
};

int main(void) {
    Rectangle rec(3.3, 4.5);
    rec.printPerimeter();
    rec.printArea();
    return 0;
}
