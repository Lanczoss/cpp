#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using std::cerr;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::string;
using std::unordered_map;

class wordTrans {
 public:
  void handleMap(const string &);

  void wordTransform(const string &);

 private:
  unordered_map<string, string> _um;
};

void wordTrans::handleMap(const string &map_txt) {
  ifstream ifs(map_txt);
  if (!ifs) {
    cerr << "open file " << map_txt << " error!" << endl;
    return;
  }
  string key;
  string line;
  while (ifs >> key && getline(ifs, line)) {
    // // 删除前面的空格
    // string::iterator it = line.begin();
    // line.erase(it);
    // cout << key << endl;
    // cout << line << endl;
    // _um[key] = line;
    // 取子串
    if (line.size() > 1) {
      // cout << line << endl;
      _um[key] = line.substr(1);
    }
  }
}

void wordTrans::wordTransform(const string &file_txt) {
  ifstream ifs(file_txt);
  if (!ifs) {
    cerr << "open file " << file_txt << " error!" << endl;
    return;
  }
  string line;
  while (getline(ifs, line)) {
    string word;
    istringstream ist(line);
    bool isFirstWord = true;
    while (ist >> word) {
      if (isFirstWord) {
        isFirstWord = false;
      } else {
        cout << " ";
      }
      // 识别是否符合映射条件
      unordered_map<string, string>::iterator findIt = _um.find(word);
      if (findIt != _um.end()) {
        // 符合条件
        cout << findIt->second;
      } else {
        cout << word;
      }
    }
    cout << endl;
  }
}

int main(void) {
  wordTrans wt;
  wt.handleMap("map.txt");
  wt.wordTransform("file.txt");
  return 0;
}
