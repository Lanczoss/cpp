#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::map;

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
      //以空格符、换行符和制表符分割
      while (ist >> word) {
        if (isWord(word) == 1) {
          ++_dict[word];
        }
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
    for (auto &map : _dict) {
      ofs << map.first << " " << map.second << endl;
    }
    ofs.close();
  }

  bool isWord(const string &word) {
    for (auto &ch : word) {
      if (isalpha(ch)) {
        continue;
      } else {
        return 0;
      }
    }
    return 1;
  }
 private:
  map<string, int> _dict;
};

int main(int argc, char *argv[]) {
  Dictionary dic;
  dic.read(argv[1]);
  dic.store("dict.txt");
  return 0;
}
