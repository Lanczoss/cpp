#include "CowString.hpp"

// 用于引用计数的长度
const int CowString::kRefcountlength = 4;

// 开辟空间用的函数
char *CowString::malloc(const char *pstr = nullptr) {
  if (pstr) {
    return new char[strlen(pstr) + 1 + kRefcountlength]() + kRefcountlength;
  } else {
    return new char[1 + kRefcountlength]() + kRefcountlength;
  }
}

// 构造函数，还需要将引用计数记为1
CowString::CowString() : _pstr(malloc()) { initRefcount(); }

// 使用const char *创建新的CowString对象
CowString::CowString(const char *pstr) : _pstr(malloc(pstr)) {
  strcpy(_pstr, pstr);
  initRefcount();
}

// 拷贝构造函数创建新CowString对象只需添加引用计数
CowString::CowString(const CowString &rhs) : _pstr(rhs._pstr) {
  increaseRefcount();
}

// 析构函数，一个对象的销毁引用计数减一，当减至0时回收空间
CowString::~CowString() {
  decreaseRefcount();
  if (Refcount() == 0) {
    delete [] (_pstr - kRefcountlength);// 从开头开始回收
  }
  _pstr = nullptr;//将对象的指针置空
}

// 赋值运算符函数
CowString & CowString::operator=(const CowString &rhs) {
  if(this != &rhs) {
    release();
    _pstr = rhs._pstr;
    increaseRefcount();
  }
  return *this;
}

// 用于对象销毁操作引用计数，引用计数为零释放空间的函数
void CowString::release() {
  decreaseRefcount();
  if (Refcount() == 0) {
    delete[](_pstr - kRefcountlength);
  }
  // 断开链接 此时引用计数减一或者空间已经释放
  _pstr = nullptr;
}

// 下标运算符重载
CowString::CharProxy CowString::operator[](size_t idx) {
  return CharProxy(*this, idx);
}

std::ostream & operator<<(std::ostream &os, const CowString &rhs) {
  os << rhs._pstr;
  return os;
}

// 封装用于对引用计数操作的函数
void CowString::increaseRefcount() { ++*(int *)(_pstr - kRefcountlength); }
void CowString::decreaseRefcount() { --*(int *)(_pstr - kRefcountlength); }
void CowString::initRefcount() { *(int *)(_pstr - kRefcountlength) = 1; }
int CowString::Refcount() const { return *(int *)(_pstr - kRefcountlength); }

size_t CowString::size() const {
  return strlen(_pstr);
}

//然后用赋值运算符函数和输出流运算符函数分析读写情况
char CowString::CharProxy::operator=(char ch) {
  if (_idx < _self.size()) {
    if (_self.Refcount() > 1) {
      _self.decreaseRefcount();
      char *temp = _self.malloc(_self._pstr);
      strcpy(temp, _self._pstr);
      _self._pstr = temp;
      _self.initRefcount();
    }
    _self._pstr[_idx] = ch;
    return ch;
  } else {
    static char nullchar = '\0';
    return nullchar;  
  }
}

CowString::CharProxy & CowString::CharProxy::operator=(const CharProxy &rhs) {
  if (_idx < _self.size() && rhs._idx < rhs._self.size()) {
    if (_self.Refcount() > 1) {
      _self.decreaseRefcount();
      char *temp = _self.malloc(_self._pstr);
      strcpy(temp, _self._pstr);
      _self._pstr = temp;
      _self.initRefcount();
    }
  _self._pstr[_idx] = rhs._self._pstr[_idx];
  } else {
    
  }
  return *this;
}

CowString::CharProxy::operator char() {
      return _self._pstr[_idx];
}