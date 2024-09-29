#ifndef COWSTRING_HPP_
#define COWSTRING_HPP_

#include <string.h>
#include <iostream>
class CowString {
  //代理模式用的对象
  class CharProxy {
   public:
    //首先拿到CowString下标运算符给到的数据
    CharProxy(CowString &self, size_t idx) : _self(self), _idx(idx) {}
    //然后用赋值运算符函数和输出流运算符函数分析读写情况
    char operator=(char);
    CharProxy & operator=(const CharProxy &);

    operator char();

   private:
    CowString &_self;
    size_t _idx;
  };

 public:
  CowString();
  CowString(const char *);
  CowString(const CowString &);
  ~CowString();

  CowString &operator=(const CowString &);
  CharProxy operator[](size_t idx);

  size_t size() const;

  friend std::ostream & operator<<(std::ostream &, const CowString &);

 private:
  // 封装用于对引用计数操作的函数
  void increaseRefcount();
  void decreaseRefcount();
  void initRefcount();
  int Refcount() const;

  // 用于引用计数为零释放空间的函数
  void release();

 private:
  // 开辟空间用的函数
  char *malloc(const char *);

 private:
  char *_pstr;                       // 指向字符串的指针
  static const int kRefcountlength;  // 用于引用计数的长度
};

#endif