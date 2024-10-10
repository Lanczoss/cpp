#include <string.h>

#include <iostream>
using std::cout;
using std::endl;
class String {
 public:
  String() : _pstr(new char[1]()) { cout << "String()" << endl; }

  String(const char *pstr) : _pstr(new char[strlen(pstr) + 1]()) {
    cout << "String(const char *)" << endl;
    strcpy(_pstr, pstr);
  }

  String(const String &rhs) : _pstr(new char[rhs.length() + 1]()) {
    cout << "String(const String &rhs)" << endl;
    strcpy(_pstr, rhs.c_str());
    /* cout << "rhs = " << rhs.c_str() << endl; */
  }

  String(String &&rhs) : _pstr(rhs._pstr) {
    // 浅拷贝
    rhs._pstr = nullptr;
    cout << "移动构造函数" << endl;
  }

  String &operator=(const String &rhs) {
    if (this != &rhs) {
      if (_pstr) {
        delete[] _pstr;
      }
      _pstr = new char[rhs.length() + 1]();
      strcpy(_pstr, rhs.c_str());
    }
    cout << "String operator=()" << endl;
    return *this;
  }

  String &operator=(String &&rhs) {
    if (this != &rhs) {
      // 删除原本指向的空间
      if (_pstr) {
        delete[] _pstr;
      }
      // 浅拷贝
      _pstr = rhs._pstr;
      rhs._pstr = nullptr;
    }
    cout << "移动构造函数operator=" << endl;
    return *this;
  }

  ~String() {
    cout << "~String()" << endl;
    delete[] _pstr;
    _pstr = nullptr;
  }

  void print() const { cout << _pstr << endl; }

  size_t length() const { return strlen(_pstr); }

  const char *c_str() const { return _pstr; }

 private:
  char *_pstr;
};

int main() {
  String str1;
  // str1.print();

  String str2 = "Hello,world";
  String str3("wangdao");

  // str2.print();
  // str3.print();

  String str4 = str3;
  // str4.print();

  str4 = str2;
  str4 = String("hello");
  // str4.print();

  return 0;
}