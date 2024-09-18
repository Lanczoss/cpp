#include <iostream>
using std::cout;
using std::endl;

namespace MySpace {

int add(int a, int b) {
    return a + b;
}

double add(double a, int b) {
    return a + b;
}

double add(int a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}
}

int main(void) {
    cout << MySpace::add(2, 4) << endl;
    cout << MySpace::add(3.3, 4) << endl;
    cout << MySpace::add(6, 7.9) << endl;
    cout << MySpace::add(1, 2, 3) << endl;
    return 0;
}

