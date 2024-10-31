#include <sw/redis++/redis++.h>

#include <iostream>
int main() {
  // 创建 Redis 客户端
  sw::redis::Redis redis("tcp://127.0.0.1:6379");

  // 设置一个键值对
  redis.set("key1", "value1");
  std::cout << "SET key1: value1" << std::endl;

  // 获取并打印值
  auto val = redis.get("key1");
  if (val) {
    std::cout << "GET key1: " << *val << std::endl;
  } else {
    std::cout << "key1 not found" << std::endl;
  }

  // 尝试获取一个不存在的键
  auto missingVal = redis.get("key2");
  if (missingVal) {
    std::cout << "GET key2: " << *missingVal << std::endl;
  } else {
    std::cout << "key2 not found" << std::endl;
  }

  // 设置多个值
  std::vector<std::pair<std::string, std::string>> key_values = {
      {"key2", "value2"}, {"key3", "value3"}};
  redis.mset(key_values.begin(), key_values.end());
  std::cout << "SET key2: value2, key3: value3" << std::endl;

  // 获取并打印多个值
  std::vector<std::string> keys = {"key2", "key3"};
  std::vector<std::optional<std::string>> vals;
  redis.mget(keys.begin(), keys.end(), std::back_inserter(vals));

  for (const auto &v : vals) {
    if (v) {
      std::cout << "GET: " << *v << std::endl;
    } else {
      std::cout << "Key not found" << std::endl;
    }
  }

  return 0;
}
