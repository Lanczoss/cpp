#include <list>
using std::list;

struct Node {
  Node(int key, int value) : _key(key), _value(value) {}
  int _key;
  int _value;
};

class LRUCache {
 public:
  LRUCache(int capacity) : _capacity(capacity) {}

  int get(int key) {
    list<Node>::iterator findIt = _cache.begin();
    for (; findIt != _cache.end(); ++findIt) {
      if (findIt->_key == key) {
        // 将其移到链表最前面
        _cache.splice(_cache.begin(), _cache, findIt);
        return findIt->_value;
      }
    }
    return -1;
  }

  void put(int key, int value) {
    list<Node>::iterator findIt = _cache.begin();
    for (; findIt != _cache.end(); ++findIt) {
      if (findIt->_key == key) {
        findIt->_value = value;
        // 将其移到链表最前面
        _cache.splice(_cache.begin(), _cache, findIt);
        break;
      }
    }
    if (findIt == _cache.end()) {
      // 不存在
      if (_capacity == _cache.size()) {
        // 若容量已满
        // 将最后一个移除
        _cache.pop_back();
      }
      // 头插
      _cache.push_front(Node(key, value));
    }
  }

 private:
  int _capacity;
  list<Node> _cache;
};
