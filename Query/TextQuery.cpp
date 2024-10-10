#include "TextQuery.h"

#include <iostream>
#include <sstream>
using std::cerr;
using std::endl;
using std::istringstream;

// 行号智能指针的类型
typedef shared_ptr<set<TextQuery::lines_t>> lines_p;

typedef shared_ptr<int> dict_p;

// 给vector扩容
TextQuery::TextQuery(ifstream &ifs) : _lines(new vector<string>) {
  if (!ifs) {
    cerr << "open file failed in TextQuery(ifstream &)" << endl;
    return;
  }
  // std::cout << "1" << endl;
  string line;
  lines_t lineNumber = 1;
  while (std::getline(ifs, line)) {
    // 记录每一行的原始信息
    _lines->push_back(line);

    // 先把一些符号转换为空格
    dealLine(line);

    string word;
    istringstream ist(line);
    while (ist >> word) {
      // 统计单词与出现的次数
      dict_p &dict_ptr = _dict[word];
      if (!dict_ptr) {
        dict_ptr.reset(new int(0));
      }
      ++(*_dict[word]);

      lines_p &lines_ptr = _wordNumbers[word];
      if (!lines_ptr) {
        // 如果是个空指针
        lines_ptr.reset(new set<lines_t>);
      }

      // 统计行号，_wordNumbers[word]是个set
      _wordNumbers[word]->insert(lineNumber);
    }
    ++lineNumber;
  }
  ifs.close();
  // std::cout << "1" << endl;
}

string &TextQuery::dealLine(string &line) {
  for (auto &ch : line) {
    if (!isalpha(ch)) {
      // 不是字母替换为空格
      ch = ' ';
    } else if (isupper(ch)) {
      // 如果是大写转换为小写
      ch = tolower(ch);
    }
  }
  return line;
}

// set<int> getWordNumbers(const string &word) const {
//   auto it = _wordNumbers.find(word);
//   if (it != _wordNumbers.end()) {
//     return it->second;
//   }
//   return {};
// }

QueryResult TextQuery::query(const string &seek) const {
  // 如果没查到数据，返回一个空的智能指针
  static shared_ptr<set<lines_t>> nullspset(new set<lines_t>);
  static shared_ptr<int> nullspi(new int);

  map<string, shared_ptr<set<lines_t>>>::const_iterator loc =
      _wordNumbers.find(seek);
  if (loc == _wordNumbers.end()) {
    return QueryResult(seek, nullspset, _lines, nullspi);
  } else {
    return QueryResult(seek, loc->second, _lines, _dict.find(seek)->second);
  }
}

ostream &print(ostream &os, const QueryResult &qr) {
  os << "---------------------------------------------" << endl;
  os << qr._seek << " occurs " << (*qr._dictSecond)
     << ((*qr._dictSecond) > 1 ? " times." : " time. ") << endl;

  set<TextQuery::lines_t> lineNums = (*qr._wordNumbersSecond);
  for (auto &num : lineNums) {
    os << "(line " << num << ") " << (*qr._lines)[num - 1] << endl;
  }
  os << "---------------------------------------------" << endl;
  return os;
}
