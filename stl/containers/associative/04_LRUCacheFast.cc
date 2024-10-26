#include <list>
#include <unordered_map>
using std::list;
using std::unordered_map;
struct Node {
  Node(int key, int value) : _key(key), _value(value) {}
  int _key;
  int _value;
};

class LRUCache {
 public:
  LRUCache(int capacity) : _capacity(capacity) {}

  int get(int key) {
    auto findIt = _cache.find(key);
    if (findIt != _cache.end()) {
      // 将其移到链表最前面
      _lst.splice(_lst.begin(), _lst, _cache[key]);
      _cache[key] = _lst.begin();
      return _lst.front()._value;
    }
    return -1;
  }

  void put(int key, int value) {
    auto findIt = _cache.find(key);
    if (findIt != _cache.end()) {
      // 更新value
      // 将其移到链表最前面
      _lst.splice(_lst.begin(), _lst, _cache[key]);
      _lst.front()._value = value;
      _cache[key] = _lst.begin();
    } else {
      // 不存在
      if (_capacity == _lst.size()) {
        // 若容量已满
        // 将最后一个移除
        _cache.erase(_lst.back()._key);
        _lst.pop_back();
      }
      // 头插
      _lst.push_front(Node(key, value));
      _cache[key] = _lst.begin();
    }
  }

 private:
  int _capacity;
  // 链表存储LRU的key
  list<Node> _lst;
  // map加速映射
  unordered_map<int, list<Node>::iterator> _cache;
};
