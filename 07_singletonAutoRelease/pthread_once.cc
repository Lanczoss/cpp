#include <stdlib.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;

class Singleton {
 public:
  //静态成员函数允许使用类名+作用域运算符调用
  //指针操作堆空间
  static Singleton *getInstance() {
    pthread_once(&_once, init_r);
    return _pInstance;
  }

  //赋值用
  void init(int x, int y) {
    _ix = x;
    _iy = y;
  }

  void print() const { cout << "x = " << _ix << ", y = " << _iy << endl; }

 private:
  static void init_r() {
      atexit(destroy);
      _pInstance = new Singleton();
  }

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
  static pthread_once_t _once;
};
//饿汉式
// Singleton *Singleton::_pInstance = nullptr;

//懒汉式
Singleton * Singleton::_pInstance = getInstance();

pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void) {
  Singleton::getInstance();
  Singleton::getInstance()->print();
  Singleton::getInstance()->init(1, 2);
  Singleton::getInstance()->print();
  return 0;
}
