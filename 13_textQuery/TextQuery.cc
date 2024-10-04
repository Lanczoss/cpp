#include <fstream>
#include <iostream>
#include <map>
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
  //给vector扩容
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
      //记录每一行的原始信息
      _lines.push_back(line);

      //先把一些符号转换为空格
      dealLine(line);

      string word;
      istringstream ist(line);
      while (ist >> word) {
        //统计单词与出现的次数
        ++_dict[word];

        //统计行号，_wordNumbers[word]是个set
        _wordNumbers[word].insert(lineNumber);
      }
      ++lineNumber;
    }
  }

  void dealLine(string &line) {
    for (auto &ch : line) {
      if (!isalpha(ch)) {
        //不是字母替换为空格
        ch = ' ';
      } else if (isupper(ch)) {
        //如果是大写转换为小写
        ch = tolower(ch);
      }
    }
  }

  void query(const string &word) {
    cout << "---------------------------------------------" << endl;
    int count = _dict[word];
    cout << word << " occurs " << _dict[word]
         << (count > 1 ? " times." : " time. ") << endl;
  
    set<int> lineNums = _wordNumbers[word];
    for (auto &num : lineNums) {
      cout << "(line " << num << ") "
      << _lines[num - 1] << endl;
    }
    cout << "---------------------------------------------" << endl;
  }

 private:
  //......
  vector<string> _lines;                // O(1)
  map<string, set<int> > _wordNumbers;  // the the
  map<string, int> _dict;               //
};

//程序测试用例
int main(int argc, char *argv[]) {
  string queryWord("the");

  TextQuery tq(107);
  tq.readFile("china_daily.txt");
  tq.query(queryWord);
  return 0;
}