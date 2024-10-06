#include <iostream>
using std::cout;
using std::endl;

template <class T = int, int kCapacity = 10>
class Stack {
 public:
  Stack() : _top(-1), _data(new T[kCapacity]()) {}

  ~Stack() {
    if (_data) {
      delete[] _data;
      _data = nullptr;
    }
  }

  bool empty() const { return _top == -1; }

  bool full() const { return _top == kCapacity - 1; }

  void push(const T &value) {
    if (!full()) {
      _data[++_top] = value;
    } else {
      cout << "栈已满" << endl;
    }
  }

  void pop() {
    if (!empty()) {
      --_top;
    } else {
      cout << "栈已空" << endl;
    }
  }

  T top() {
    if (!empty()) {
      return _data[_top];
    } else {
      throw "栈已空";
    }
  }

  void print() const {
    for (int idx = 0; idx < _top + 1; ++idx) {
      cout << _data[idx] << " ";
    }
    cout << endl;
  }

 private:
  int _top;
  T *_data;
};

int main(void) {
  Stack<> s;
  // s.push(10);
  // s.push(20);
  s.pop();
  s.print();

  return 0;
}
