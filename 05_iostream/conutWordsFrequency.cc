#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

struct Record {
  string _word;
  int _frequency = 0;
};

class Dictionary {
 public:
  void read(const std::string &filename) {
    ifstream ifs(filename);
    if (!ifs) {
      cerr << "open file failed in Dictionary.read()" << endl;
      return;
    }
    /* string word; */
    string line;
    while (std::getline(ifs, line)) {
      std::istringstream ist(line);
      string word;
      int is_exist = 0;
      //以空格符、换行符和制表符分割
      while (ist >> word) {
        for (auto &vec : _dict) {
          if (vec._word == word) {
            vec._frequency++;
            is_exist = 1;
            break;
          }
        }
        if (is_exist == 0 && isWord(word) == 1) {
          Record tmp;
          tmp._word = word;
          tmp._frequency++;
          _dict.push_back(tmp);
        }
        is_exist = 0;
      }
    }
    ifs.close();
  }

  void store(const std::string &filename) {
    //默认为w模式
    ofstream ofs(filename);
    if (!ofs) {
      cerr << "open file failed in Dictionary.store()" << endl;
      return;
    }
    sort(_dict.begin(), _dict.end(), cmp);
    for (auto &vec : _dict) {
      ofs << vec._word << " " << vec._frequency << endl;
    }
    ofs.close();
  }

  bool isWord(const string &word) {
    for (auto &ch : word) {
      if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        continue;
      } else {
        return 0;
      }
    }
    return 1;
  }

 private:
  static bool cmp(const Record &r1, const Record &r2) {
    return r1._word < r2._word;
  }

 private:
  vector<Record> _dict;
};

int main(int argc, char *argv[]) {
  Dictionary dic;
  dic.read(argv[1]);
  dic.store("dict.txt");
  return 0;
}
