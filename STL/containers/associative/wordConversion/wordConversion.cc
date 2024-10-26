#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::string;
using std::unordered_map;

unordered_map<string, string> handleMap(ifstream &ifs) {
  unordered_map<string, string> wordMap;
  string key;
  string line;
  while (ifs >> key && getline(ifs, line)) {
    // 删除前面的空格
    string::iterator it = line.begin();
    line.erase(it);
    // cout << line << endl;
    wordMap[key] = line;
  }
  ifs.close();
  return wordMap;
}

void wordTransform(ifstream &map_txt, ifstream &file_txt) {
  unordered_map<string, string> wordMap = handleMap(map_txt);
  string line;
  while (getline(file_txt, line)) {
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
      unordered_map<string, string>::iterator findIt = wordMap.find(word);
      if (findIt != wordMap.end()) {
        // 符合条件
        cout << findIt->second;
      } else {
        cout << word;
      }
    }
    cout << endl;
  }
  file_txt.close();
}

int main(void) {
  ifstream map_txt("map.txt");
  ifstream file_txt("file.txt");
  wordTransform(map_txt, file_txt);
  return 0;
}
