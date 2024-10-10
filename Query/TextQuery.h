#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_

#include <fstream>
#include <map>

#include "QueryResult.h"
using std::ifstream;
using std::map;

class QueryResult;  // 返回查询结果的对象

class TextQuery {
 public:
  typedef vector<string>::size_type lines_t;
  // 使用文件流打开一个文件
  // 并用构造函数初始化一个记录所有行信息的数据成员
  TextQuery(ifstream &);

  // 根据单词查询结果
  QueryResult query(const string &) const;

  void printWordNumbers();

 private:
  // 用智能指针共享行信息资源
  shared_ptr<vector<string>> _lines;

  // 用智能指针共享每个单词所对应的行号
  map<string, shared_ptr<set<lines_t>>> _wordNumbers;

  // // 用智能指针共享每个单词的词频
  map<string, shared_ptr<int>> _dict;

  // 处理单词用的静态成员函数
  static string &dealLine(string &);
};

TextQuery getFile(int, char **);

#endif  // !TEXTQUERY_H_
