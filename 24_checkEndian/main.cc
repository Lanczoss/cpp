#include <arpa/inet.h>

#include <iostream>
using namespace std;

void print(unsigned int n) {
  unsigned char *p = reinterpret_cast<unsigned char *>(&n);
  for (size_t idx = 0; idx < sizeof(n); ++idx) {
    cout << std::hex << static_cast<int>(p[idx]) << " ";
  }
}

int main(void) {
  unsigned int num = 0x12345678;
  unsigned int ret = htonl(num);

  cout << "machine save = 0x ";
  print(num);
  cout << endl;
  cout << "net save = 0x ";
  print(ret);
  cout << endl;
  return 0;
}
