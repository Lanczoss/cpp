#include "String.hpp"
#include <string.h>
String::String(const char * pstr) : _size(strlen(pstr)), _capacity(15) {
  if(strlen(pstr) <= 15) {
    bzero(_buffer._local, sizeof(_buffer._local));
    strcpy(_buffer._local, pstr);
  } else {
    _capacity = _size;
    _buffer._pointer = new char[strlen(pstr) + 1]();
    strcpy(_buffer._pointer, pstr);
  }
}

String::~String() {
  if (_size > 15) {
    delete [] _buffer._pointer;
    _buffer._pointer = nullptr;
  }
}
char& String::operator[](size_t idx) {
  if (idx < _size - 1) {
    if (_size <= 15) {
      return _buffer._local[idx];
    } else {
      return _buffer._pointer[idx];
    }
  } else {
    static char nullchar = '\0';
    return nullchar;
  }
}

ostream & operator<<(ostream & os, const String & rhs) {
  if (rhs._size <= 15) {
    os << rhs._buffer._local;
  } else {
    os << rhs._buffer._pointer;
  }
  return os;
}
