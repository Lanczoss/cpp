#include "String.hh"
using std::cout;
using std::endl;
using std::cin;

int main(void) {
  String s1("hello");
  String s2(s1);
  String s3;
  s3 = "world";
  s3 += s3;
  s3 += "!!";
  cout << s1 << endl;
  cout << s2 << endl;
  cout << s3 << endl;
  cout << (s1 == s2) << endl;//返回 1
  cout << (s2 == s3) << endl;//返回 0
  cout << (s1 != s2) << endl;//返回 0
  String s4 = "A";
  String s5 = "Z";
  cout << (s4 > s5) << endl;//返回 0
  cout << (s4 < s5) << endl;//返回 1
  
  String s6 = s4 + s5;
  cout << s6 << endl;
  s6 = s4 + "Hello hi";
  cout << s6 << endl;
  s6 = "OK" + s4;
  cout << s6 << endl;
  cout << s6[4] << endl; //报错
  cout << s6[1] << endl; //K
                         
  cin >> s6;
  cout << s6 << endl;
  
  cin >> s6;
  cout << s6 << endl;
  return 0;
}
