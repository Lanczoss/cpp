#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

// QueryResult类是为了打印出不一样的结果
class QueryResult {
  friend ostream &print(ostream &, const QueryResult &);

 public:
  typedef vector<string>::size_type lines_t;
  // 行号的迭代器
  typedef set<lines_t>::const_iterator lines_it;

  QueryResult(string seek, shared_ptr<set<lines_t>> wordNumbersSecond,
              shared_ptr<vector<string>> lines, shared_ptr<int> dictSecond)
      : _seek(seek),
        _wordNumbersSecond(wordNumbersSecond),
        _lines(lines),
        _dictSecond(dictSecond) {}

  lines_it begin() const { return _wordNumbersSecond->begin(); }
  lines_it end() const { return _wordNumbersSecond->end(); }
  set<lines_t>::size_type size() const { return _wordNumbersSecond->size(); }
  shared_ptr<vector<string>> getLines() { return _lines; }
  shared_ptr<int> getDictSecond() { return _dictSecond; }

 private:
  string _seek;
  shared_ptr<set<lines_t>> _wordNumbersSecond;
  // 行信息
  shared_ptr<vector<string>> _lines;

  // 词频
  shared_ptr<int> _dictSecond;
};

ostream &print(ostream &, const QueryResult &);

#endif  // !QUERY_RESULT_H
