#include <iostream>
using std::cout;
using std::endl;

class Data {
 public:
  Data() { cout << "Data()" << endl; }

  ~Data() { cout << "~Data()" << endl; }

  int getData() const {
    cout << "getData()" << endl;
    return _data;
  }

 private:
  int _data = 10;
};

class MiddleLayer {
 public:
  MiddleLayer(Data* p) : _pdata(p) { cout << "MiddleLayer()" << endl; }

  ~MiddleLayer() {
    if (_pdata) {
      delete _pdata;
      _pdata = nullptr;
    }
    cout << "~MiddleLayer()" << endl;
  }

  Data* operator->() {
    cout << "operator->()" << endl;
    return _pdata;
  }

  Data& operator*() {
    cout << "operator*()" << endl;
    return *_pdata;
  }

 private:
  Data* _pdata;
};

class ThirdLayer {
 public:
  ThirdLayer(MiddleLayer* pm) : _pml(pm) { cout << "ThirdLayer()" << endl; }

  ~ThirdLayer() {
    if(_pml) {
      delete _pml;
      _pml = nullptr;
    }
    cout << "~ThirdLayer()" << endl;
  }

  MiddleLayer & operator->() {
    cout << "ThirdLayer operator->()" << endl;
    return *_pml;
  }

  Data & operator*() {
    cout << "ThirdLayer operator*()" << endl;
    return *(*_pml);
  }

 private:
  MiddleLayer* _pml;
};

void test0() {
  MiddleLayer ml(new Data());
  cout << ml->getData() << endl;
  cout << (*ml).getData() << endl;
}

void test1() {
  ThirdLayer tl(new MiddleLayer(new Data()));
  cout << tl->getData() << endl;
  cout << (*tl).getData() << endl;
}

int main(void) {
  /* test0(); */
  test1();
  return 0;
}
