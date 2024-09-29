#include "CowString.hpp"
using std::cout;
using std::endl;

int main() {
  CowString str1="hello";
  CowString str3 = str1;
  cout << str1[0] << endl;  //读操作
  str1[0] = 'H';            //写操作
  cout << str3[0] << endl;  //发现str3的内容也被改变了
  cout << str1 << endl;
  cout << str3 << endl;
}