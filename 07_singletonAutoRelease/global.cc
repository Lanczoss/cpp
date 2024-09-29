#include <iostream>
using std::cout;
using std::endl;

class Singleton {
 public:
  //静态成员函数允许使用类名+作用域运算符调用
  //指针操作堆空间
  static Singleton *getInstance() {
    if (_pInstance == nullptr) {
      _pInstance = new Singleton();
    }
    return _pInstance;
  }

  //回收堆空间
  /* static void destroy() { */
  /*   if (_pInstance != nullptr) { */
  /*     delete _pInstance; */
  /*     _pInstance = nullptr; */
  /*   } */
  /* } */

  //赋值用
  void init(int x, int y) {
    _ix = x;
    _iy = y;
  }

  void print() const { cout << "x = " << _ix << ", y = " << _iy << endl; }

 private:
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
//静态数据成员需要类外初始化
Singleton *Singleton::_pInstance = nullptr;

//全局AutoRelease自动释放
class AutoRelease {
 public:
  AutoRelease(Singleton *p) : _p(p) {}

  ~AutoRelease() {
    if (_p) {
      delete _p;
      _p = nullptr;
    }
  }

 private:
  Singleton *_p;
};

int main(void) {
  AutoRelease ar(Singleton::getInstance());
  Singleton::getInstance()->print();
  Singleton::getInstance()->init(1, 2);
  Singleton::getInstance()->print();
  return 0;
}
