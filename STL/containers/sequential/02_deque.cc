#include <deque>
#include <iostream>
using std::cout;
using std::deque;
using std::endl;

template <typename container>
void display(const container &con) {
  for (auto &elem : con) {
    cout << elem << " ";
  }
  cout << endl;
}

int main(void) {
  deque<int> vt1;
  display(vt1);

  deque<int> vt2(5, 3);
  display(vt2);

  int arr[5] = {1, 3, 5, 7, 8};
  deque<int> vt3(arr, arr + 5);
  display(vt3);

  deque<int> vt4 = vt3;
  display(vt4);

  deque<int> vt5 = {3, 4, 67, 7686, 8, 787, 87, 32};
  display(vt5);
  return 0;
}
