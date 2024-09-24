#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::string;
void test0(){
    string filename = "1.txt";
    ifstream ifs(filename); 

    if(!ifs){
        cerr << "ifs open file fail!";
        return;
    }
    
    //读取一个文件的所有内容先要获取文件的大小
    //将游标放到了文件的最后（尾后）
    ifs.seekg(0,std::ios::end);
    long length = ifs.tellg();//获取尾后下标，实际就是总的字符数
    cout << length << endl;

    char * pdata = new char[length + 1]();
    //需要将游标再放置到文件开头
    ifs.seekg(0,std::ios::beg);
    ifs.read(pdata,length);

    ifs.close();
}
int main() {
  test0();
  return 0;
}
