#include <iostream>
using std::cout;
using std::endl;

class Stack {
 public:
  Stack() : _top(-1), _size(0) { _stack = new int[10](); }
  ~Stack() {
    delete[] _stack;
    _stack = nullptr;
  }

  bool empty() {
    if (_size == 0) {
      return true;
    } else {
      return false;
    }
  }  //判断栈是否为空

  bool full() {
    if (_size == 10) {
      return true;
    } else {
      return false;
    }
  }  //判断栈是否已满

  void push(int new_element) {
    if (full()) {
      cout << "栈已满" << endl;
      return;
    }
    _stack[++_top] = new_element;
    _size++;
  }  //元素入栈

  void pop() {
    if (empty()) {
      cout << "栈已空" << endl;
    }
    _top--;
    _size--;
  }  //元素出栈

  int top() { return _stack[_top]; }  //获取栈顶元素

  void print() {
    for (int idx = 0; idx <= _top; idx++) {
      cout << _stack[idx] << " ";
    }
    cout << endl;
  }

 private:
  int _size;
  int _top;
  int *_stack;
};

int main(void) {
  Stack s;
  s.push(1);
  s.push(2);
  s.print();
  s.pop();
  s.print();
  cout << "top = " << s.top() << endl;
  return 0;
}
