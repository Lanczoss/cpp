#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;
using std::unique_ptr;

// 删除器
template <class T>
struct FILECloser {
  void operator()(FILE *fp) {
    if (fp) {
      cout << "fclose(fp)" << endl;
      fclose(fp);
    }
  }
};

void test1(void) {
  string str("hello\n");
  unique_ptr<FILE, FILECloser<FILE>> up(fopen("wd.txt", "a+"));
  fwrite(str.c_str(), 1, str.size(), up.get());
}

void test2(void) {
  string str("helloworld\n");
  FILECloser<FILE> fc;
  shared_ptr<FILE> sp(fopen("wd.txt", "a+"), fc);
  fwrite(str.c_str(), 1, str.size(), sp.get());
}

int main(void) {
  // test1();
  test2();
  return 0;
}
