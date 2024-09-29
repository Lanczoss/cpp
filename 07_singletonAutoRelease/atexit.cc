#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

class Singleton {
 public:
  //静态成员函数允许使用类名+作用域运算符调用
  //指针操作堆空间
  static Singleton *getInstance() {
    if (_pInstance == nullptr) {
      atexit(destroy);
      _pInstance = new Singleton();
    }
    return _pInstance;
  }

  //赋值用
  void init(int x, int y) {
    _ix = x;
    _iy = y;
  }

  void print() const { cout << "x = " << _ix << ", y = " << _iy << endl; }

 private:
  //回收堆空间
  static void destroy() {
    if (_pInstance != nullptr) {
      delete _pInstance;
      _pInstance = nullptr;
    }
  }

  //构造函数需要private
  Singleton(int x = 0, int y = 0) {
    _ix = x;
    _iy = y;
  }

  //禁止编译器生成或调用拷贝构造函数和赋值运算符函数
  Singleton(const Singleton &rhs) = delete;
  Singleton &operator=(const Singleton &rhs) = delete;

 private:
  int _ix;
  int _iy;
  //静态成员函数只能访问非静态成员
  static Singleton *_pInstance;
};
//饿汉式
// Singleton *Singleton::_pInstance = nullptr;

//懒汉式
Singleton * Singleton::_pInstance = getInstance();

int main(void) {
  Singleton::getInstance();
  Singleton::getInstance()->print();
  Singleton::getInstance()->init(1, 2);
  Singleton::getInstance()->print();
  return 0;
}
