#include "String.hh"

#include <limits>
using std::cout;
using std::endl;

String::String() : _pstr(new char[1]()) {}

String::String(const char *pchar) : _pstr(new char[strlen(pchar) + 1]()) {
  strcpy(_pstr, pchar);
}

String::String(const String &ps) {
  if (_pstr != nullptr) {
    delete[] _pstr;
  }
  _pstr = new char[ps.size() + 1]();
  strcpy(_pstr, ps._pstr);
}

String::~String() {
  if (_pstr) {
    delete[] _pstr;
    _pstr = nullptr;
  }
}

String &String::operator=(const String &rhs) {
  if (this != &rhs) {
    delete[] _pstr;
    _pstr = new char[rhs.size() + 1]();
    strcpy(_pstr, rhs._pstr);
  }
  return *this;
}

String &String::operator=(const char *rhs) {
  String temp(rhs);
  *this = temp;
  return *this;
}

// String &String::operator+=(const String &rhs) {
//   String temp1(*this);
//   String temp2(rhs);
//   delete[] _pstr;
//   _pstr = new char[temp1.size() + temp2.size() + 1]();
//   strcpy(_pstr, temp1._pstr);
//   strcat(_pstr, temp2._pstr);
//   return *this;
// }

String &String::operator+=(const String &rhs) {
  char * temp = new char[this->size() + rhs.size() + 1]();
  strcpy(temp, _pstr);
  strcat(temp, rhs._pstr);
  delete [] _pstr;
  _pstr = temp;
  return *this;
}

String &String::operator+=(const char *rhs) {
  String temp(rhs);
  *this += temp;
  return *this;
}

char &String::operator[](std::size_t index) {
  //判断是否越界
  if (index < strlen(_pstr)) {
    return _pstr[index];
  } else {
    cout << "out of range" << endl;
    static char nullchar = '\0';
    return nullchar;
  }
}
const char &String::operator[](std::size_t index) const {
  //判断是否越界
  if (index < strlen(_pstr)) {
    return _pstr[index];
  } else {
    cout << "out of range" << endl;
    static char nullchar = '\0';
    return nullchar;
  }
}

std::size_t String::size() const { return strlen(_pstr); }
const char *String::c_str() const { return _pstr; }

bool operator==(const String &lhs, const String &rhs) {
  return !(strcmp(lhs._pstr, rhs._pstr));
}

bool operator!=(const String &lhs, const String &rhs) {
  return strcmp(lhs._pstr, rhs._pstr);
}

bool operator<(const String &lhs, const String &rhs) {
  int ret = strcmp(lhs._pstr, rhs._pstr);
  if (ret < 0) {
    return true;
  } else {
    return false;
  }
}
bool operator>(const String &lhs, const String &rhs) {
  int ret = strcmp(lhs._pstr, rhs._pstr);
  if (ret > 0) {
    return true;
  } else {
    return false;
  }
}

bool operator<=(const String &lhs, const String &rhs) {
  int ret = strcmp(lhs._pstr, rhs._pstr);
  if (ret <= 0) {
    return true;
  } else {
    return false;
  }
}

bool operator>=(const String &lhs, const String &rhs) {
  int ret = strcmp(lhs._pstr, rhs._pstr);
  if (ret >= 0) {
    return true;
  } else {
    return false;
  }
}

std::istream &operator>>(std::istream &is, String &s) {
  char buf[5] = {0};
  //判定是否超过1024
  //这里使用最高接受4个字符来模拟1024
  size_t index = 0;
  char ch;
  //遇到空白字符结束
  while (is.get(ch), !isspace(ch)) {
    if (index == 4) {
      //清空后抛出
      is.clear();
      is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "输入字符超过上限" << endl;
      break;
    }
    buf[index++] = ch;
  }
  delete[] s._pstr;
  s._pstr = new char[index + 1]();
  strcpy(s._pstr, buf);
  return is;
}

std::ostream &operator<<(std::ostream &os, const String &s) {
  if (s._pstr) {
    os << s._pstr;
  }
  return os;
}

String operator+(const String &lhs, const String &rhs) {
  String temp(lhs);
  temp += rhs;
  return temp;
}

String operator+(const String &lhs, const char *rhs) {
  String temp(lhs);
  temp += rhs;
  return temp;
}

String operator+(const char *lhs, const String &rhs) {
  String temp(lhs);
  temp += rhs;
  return temp;
}
