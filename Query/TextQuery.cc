#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::map;
using std::set;
using std::string;
using std::vector;
class TextQuery {
 public:
  // 给vector扩容
  TextQuery(int capa) { _lines.reserve(capa); }

  void readFile(const string &filename) {
    ifstream ifs(filename);
    if (!ifs) {
      cerr << "open file failed in Dictionary.read()" << endl;
      return;
    }
    string line;
    size_t lineNumber = 1;
    while (std::getline(ifs, line)) {
      // 记录每一行的原始信息
      _lines.push_back(line);

      // 先把一些符号转换为空格
      dealLine(line);

      string word;
      istringstream ist(line);
      while (ist >> word) {
        // 统计单词与出现的次数
        ++_dict[word];

        // 统计行号，_wordNumbers[word]是个set
        _wordNumbers[word].insert(lineNumber);
      }
      ++lineNumber;
    }
  }

  void dealLine(string &line) {
    for (auto &ch : line) {
      if (!isalpha(ch)) {
        // 不是字母替换为空格
        ch = ' ';
      } else if (isupper(ch)) {
        // 如果是大写转换为小写
        ch = tolower(ch);
      }
    }
  }

  set<int> getWordNumbers(const string &word) const {
    auto it = _wordNumbers.find(word);
    if (it != _wordNumbers.end()) {
      return it->second;
    }
    return {};
  }

  void query(const string &word) {
    cout << "---------------------------------------------" << endl;
    int count = _dict[word];
    cout << word << " occurs " << _dict[word]
         << (count > 1 ? " times." : " time. ") << endl;

    set<int> lineNums = _wordNumbers[word];
    for (auto &num : lineNums) {
      cout << "(line " << num << ") " << _lines[num - 1] << endl;
    }
    cout << "---------------------------------------------" << endl;
  }

 private:
  //......
  vector<string> _lines;               // O(1)
  map<string, set<int>> _wordNumbers;  // the the
  map<string, int> _dict;              //
};

// 抽象基类
class Query_base {
  friend class Query;  // 通过Query对象使用Query_base

 protected:
  virtual ~Query_base() = default;

 private:
  // set<int>> 返回TextQuer所在的行号
  virtual set<int> eval(const TextQuery &) const = 0;
};

// 是Query_base的接口类
class Query {
  // 接受Query对象，友元函数都是私有
  friend Query operator~(const Query &);
  friend Query operator|(const Query &, const Query &);
  friend Query operator&(const Query &, const Query &);

 public:
  Query(const string &);  // 负责构造WordQuery

  // Query用于调用Query_base的操作
  set<int> eval(const TextQuery &t) const { return q->eval(t); }

 private:
  // 智能指针
  Query(std::shared_ptr<Query_base> query) : q(query) {}
  std::shared_ptr<Query_base> q;
};

class WordQuery : public Query_base {
  // Query的构造函数使用
  friend class Query;
  set<int> eval(const TextQuery &t) const override {
    return t.getWordNumbers(query_word);
  }
  WordQuery(const string &s) : query_word(s) {}
  string query_word;
};

inline Query::Query(const string &s) : q(new WordQuery(s)) {}

// 程序测试用例
int main(int argc, char *argv[]) {
  string queryWord("the");

  TextQuery tq(107);
  tq.readFile("china_daily.txt");
  tq.query(queryWord);
  return 0;
}
