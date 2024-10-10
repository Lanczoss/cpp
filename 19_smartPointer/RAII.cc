#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Computer {
 public:
  Computer(const char *brand, int price)
      : _brand(new char[strlen(brand) + 1]()), _price(price) {
    strcpy(_brand, brand);
    cout << "Computer()" << endl;
  }

  ~Computer() {
    if (_brand) {
      delete[] _brand;
      _brand = nullptr;
    }
    cout << "~Computer()" << endl;
  }

  void print() const {
    cout << "brand: " << _brand << endl;
    cout << "price: " << _price << endl;
  }

 private:
  char *_brand;
  int _price;
};

class RAII {
 public:
  RAII(Computer *data) : _data(data) { cout << "RAII()" << endl; }
  ~RAII() {
    if (_data) {
      delete _data;
      _data = nullptr;
    }
    cout << "~RAII()" << endl;
  }

  Computer *operator->() { return _data; }

  void reset(Computer *data) {
    if (_data) {
      delete _data;
      _data = nullptr;
    }
    _data = data;
  }

  RAII(const RAII &) = delete;
  RAII &operator=(const RAII &) = delete;

 private:
  Computer *_data;
};

int main() {
  RAII ra(new Computer("Lenove", 6000));
  ra->print();
  return 0;
}
