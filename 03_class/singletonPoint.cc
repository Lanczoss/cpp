#include <iostream>
using std::cout;
using std::endl;

class Point {
public:
    //静态成员函数允许使用类名+作用域运算符调用
    //指针操作堆空间
    static Point * getInstance() {
        if(_pInstance == nullptr) {
            _pInstance = new Point();
        }
        return _pInstance;
    }

    //回收堆空间
    static void destroy() {
        if(_pInstance != nullptr) {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

    //赋值用
    void init(int x, int y) {
        _ix = x;
        _iy = y;
    }

    void print() const {
        cout << "x = " << _ix << ", y = " << _iy << endl;
    }

private:
    //构造函数需要private
    Point(int x = 0, int y = 0) {
        _ix = x;
        _iy = y;
    }

    //禁止编译器生成或调用拷贝构造函数和赋值运算符函数
    Point(const Point & rhs) = delete;
    Point & operator=(const Point & rhs) = delete;


private:
    int _ix;
    int _iy;
    //静态成员函数只能访问非静态成员
    static Point *_pInstance;
};
//静态数据成员需要类外初始化
Point * Point::_pInstance = nullptr;

int main(void) {
    Point::getInstance()->print();
    Point::getInstance()->init(1, 2);
    Point::getInstance()->print();
    Point::destroy();
    return 0;
}
