#include <iostream>

#include "TextQuery.h"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

TextQuery getFile(int argc, char** argv) {
  ifstream ifs;
  // 打开文件用
  if (argc == 2) {
    ifs.open(argv[1]);
  } else {
    cerr << "wrong arg numbers." << endl;
    throw "wrong arg numbers.";
  }
  return TextQuery(ifs);
}

bool getInputSeek(string& rhs) {
  cout << "请输入要查询的单词，'q'可退出程序：" << endl;
  cin >> rhs;
  if (!cin || rhs == "q") {
    return false;
  } else {
    return true;
  }
}

bool getInputSeeks(string& lhs, string& rhs) {
  cout << "请输入要查询的单词，'q'可退出程序：" << endl;
  cin >> lhs;
  if (!cin || lhs == "q") return false;
  cin >> rhs;
  return true;
}
