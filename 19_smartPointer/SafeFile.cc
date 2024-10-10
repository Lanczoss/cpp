#include <stdio.h>

#include <string>
// using std::cout;
// using std::endl;
using std::string;

class SafeFile {
 public:
  SafeFile(FILE *);
  ~SafeFile();

  void write(const string &);

 private:
  FILE *_fp;
};

SafeFile::SafeFile(FILE *fp) : _fp(fp) {}

SafeFile::~SafeFile() {
  if (_fp) {
    fclose(_fp);
  }
}

void SafeFile::write(const string &rhs) {
  fwrite(rhs.c_str(), 1, rhs.size(), _fp);
}

int main(void) {
  string str("hello");
  SafeFile sf(fopen("1.txt", "w"));
  sf.write(str);
  return 0;
}
