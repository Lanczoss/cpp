#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;

void readFile(const string & filename) {
  //创建一个ifstream对象
  ifstream ifs(filename);
  if(!ifs) {
    cerr << "open file failed in readFile." << endl;
    return;
  }
  string line;
  while(std::getline(ifs, line)) {
    cout << line << endl;
  }
  ifs.close();
}

int main(int argc, char *argv[]) {
  if(argc != 2) {
    cerr << "输入参数错误" << endl;
    return -1;
  } 
  string filename(argv[1]);
  readFile(filename);
  return 0;
}
