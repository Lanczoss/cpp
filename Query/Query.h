#ifndef QUERY_H_
#define QUERY_H_

#include <string>

#include "TextQuery.h"
using std::string;

// 基类（抽象类）
class Query_base {
  // 声明Query是友元类
  // 可以访问Query_base的虚函数（覆盖）
  friend class Query;

  // 不是public是为了用户和其它派生类不能直接访问
  // 访问Query_base需要通过派生类Query
  // 受保护成员是为了在派生类中使用
 protected:
  // 在eval函数中要使用行号类型
  typedef TextQuery::lines_t lines_t;
  // 要在派生类中的析构函数中被隐式调用
  virtual ~Query_base() = default;

  // 以下为只有Query及其派生类能访问（覆盖）的纯虚函数
 private:
  virtual QueryResult eval(const TextQuery &) const = 0;

  virtual string rep() const = 0;
};

// 这是文本查询程序的接口
class Query {
  // 重载|
  friend Query operator|(const Query &, const Query &);
  // 重载&
  friend Query operator&(const Query &, const Query &);

 public:
  // 根据输入的单词创建一个对象
  Query(const string &);

  // 定义基类虚函数
  // 从而可以调用所有覆盖后的虚函数
  QueryResult eval(const TextQuery &t) const { return _query->eval(t); }
  string rep() const { return _query->rep(); }

 private:
  // 让智能指针指向一个派生类对象
  // 移动构造
  Query(shared_ptr<Query_base> query) : _query(query) {}
  // 用于访问Query_base的智能指针
  // 类似基类指针的效果（可以进行动态多态）
  shared_ptr<Query_base> _query;
};

// 用于是一个抽象类
// 存储两个操作数的情况
class BinaryQuery : public Query_base {
 protected:
  BinaryQuery(const Query &lhs, const Query &rhs, const string &operatorType)
      : _lhs(lhs), _rhs(rhs), _operatorType(operatorType) {}

  // 用于打印输入情况的覆盖
  string rep() const { return "(" + _lhs.rep() + ", " + _rhs.rep() + ")"; }

 protected:
  Query _lhs, _rhs;
  string _operatorType;
};

// 处理接受到and操作符的情况
class AndQuery : public BinaryQuery {
  // 将运算符重载声明为友元
  // 从而可以在运算符重载中访问私有的移动构造函数
  friend Query operator&(const Query &, const Query &);

  AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {}

  // 定义eval函数从而可以创建AndQuery对象
  QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
  // 隐式转换
  return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
  friend Query operator|(const Query &, const Query &);

  OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}

  QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &lhs, const Query &rhs) {
  return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

// 用于保存查找单词的类
class WordQuery : public Query_base {
  // 让Query可以访问所有成员（因为默认都是private）
  friend class Query;

  WordQuery(const string &rhs) : _word(rhs) {}

  // 定义所有继承的虚函数
  // 从而可以创建WordQuery对象
  QueryResult eval(const TextQuery &t) const { return t.query(_word); }
  string rep() const { return _word; }

  string _word;
};

// 根据传入的单词用WordQuery对象保存
inline Query::Query(const string &rhs) : _query(new WordQuery(rhs)) {}
inline std::ostream &operator<<(std::ostream &os, const Query &query) {
  // Query::rep makes a virtual call through its Query_base pointer to rep()
  return os << query.rep();
}

bool getInputSeek(string &);
bool getInputSeeks(string &, string &);

#endif  // !QUERY_H_
