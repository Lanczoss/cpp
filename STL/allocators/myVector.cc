#include <iostream>
#include <memory>
using std::allocator;
using std::cout;
using std::endl;
using std::uninitialized_copy;

template <typename T>
class Vector {
 public:
  using iterator = T *;
  iterator begin() { return _start; }
  iterator end() { return _finish; }

  Vector();
  ~Vector();
  void push_back(const T &);
  void pop_back();
  int size();
  int capacity();

 private:
  void reallocate();  // 重新分配内存,动态扩容要用的
 private:
  static std::allocator<T> _alloc;
  T *_start;           // 指向数组中的第一个元素
  T *_finish;          // 指向最后一个实际元素之后的那个元素
  T *_end_of_storage;  // 指向数组本身之后的位置
};
template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
Vector<T>::Vector()
    : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}

template <typename T>
Vector<T>::~Vector() {
  if (_start) {
    // 摧毁对象 回收空间
    while (_start != _finish) {
      _alloc.destroy(--_finish);
    }
    _alloc.deallocate(_start, capacity());
  }
}

template <typename T>
int Vector<T>::size() {
  return _finish - _start;
}

template <typename T>
int Vector<T>::capacity() {
  return _end_of_storage - _start;
}

template <typename T>
void Vector<T>::pop_back() {
  if (size() > 0) {
    _alloc.destroy(--_finish);
  }
}

template <typename T>
void Vector<T>::push_back(const T &rhs) {
  if (size() == capacity()) {
    reallocate();
  }
  _alloc.construct(_finish++, rhs);
}

template <typename T>
void Vector<T>::reallocate() {
  int oldCapacity = capacity();
  int newCapacity = 2 * oldCapacity > 0 ? 2 * oldCapacity : 1;
  T *ptemp = _alloc.allocate(newCapacity);
  if (_start) {
    // 如果存在旧空间
    uninitialized_copy(_start, _finish, ptemp);
    // 摧毁对象 回收空间
    while (_start != _finish) {
      _alloc.destroy(--_finish);
    }
    _alloc.deallocate(_start, oldCapacity);
  }
  // 修改指向
  _start = ptemp;
  _finish = ptemp + oldCapacity;
  _end_of_storage = ptemp + newCapacity;
}

template <typename T>
void print(T &rhs) {
  cout << "size = " << rhs.size() << endl;
  cout << "capacity = " << rhs.capacity() << endl;
}

int main() {
  Vector<int> vec;
  vec.push_back(1);
  print(vec);
  vec.push_back(2);
  print(vec);
  vec.push_back(4);
  print(vec);
  vec.push_back(2);
  print(vec);
  vec.push_back(10);
  print(vec);
  vec.push_back(8);
  print(vec);

  for (auto &elem : vec) {
    cout << elem << " ";
  }
  cout << endl;
}
