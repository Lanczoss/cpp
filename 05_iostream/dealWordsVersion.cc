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
  Record(const string &word, int frequency = 1)
      : _word(word), _frequency(frequency) {}
  string _word;
  int _frequency = 0;
};

bool operator<(const Record &lhs, const Record & rhs) {
  return lhs._word < rhs._word; 
}

class Dictionary {
 public:

   Dictionary(int capa) {
     _dict.reserve(capa);
   } 

  void read(const std::string &filename) {
    ifstream ifs(filename);
    if (!ifs) {
      cerr << "open file failed in Dictionary.read()" << endl;
      return;
    }
    string line;
    while (std::getline(ifs, line)) {
      std::istringstream ist(line);
      string word;
      //以空格符、换行符和制表符分割
      while (ist >> word) {
        dealWord(word);
        insert(word);
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
    sort(_dict.begin(), _dict.end());
    for (auto &vec : _dict) {
      ofs << vec._word << " " << vec._frequency << endl;
    }
    ofs.close();
  }

  void dealWord(string &word) {
    auto it = word.begin();
    while (it != word.end()) {
      if (!isalpha(*it)) {
        it = word.erase(it);
      } else {
        ++it;
      }
    }
  }

  void insert(const string &word) {
    if(word == string()) {
      return;
    }
    for (auto &re : _dict) {
      if (word == re._word) {
        ++re._frequency;
        return;
      }
    }
    _dict.push_back(Record(word));
  }

 private:
  /* static bool cmp(const Record &r1, const Record &r2) { */
  /*   return r1._word < r2._word; */
  /* } */

 private:
  vector<Record> _dict;
};

int main(int argc, char *argv[]) {
  Dictionary dic(13000);
  dic.read(argv[1]);
  dic.store("dict.txt");
  return 0;
}
