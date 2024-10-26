#include <time.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::deque;
using std::endl;
using std::string;
using std::vector;

class Person {
 public:
  Person(const string &str, const double score = 0)
      : _name(str), _score(score) {}

  string _name;
  double _score;
};

void inputScore(Person &person) {
  deque<double> judgement;
  for (size_t idx = 0; idx < 10; ++idx) {
    // 录入10个裁判的分数
    judgement.push_back(::rand() % 100);
  }
  std::sort(judgement.begin(), judgement.end());
  judgement.pop_back();
  judgement.pop_front();
  double judgeAvg = 0;
  for (auto &elm : judgement) {
    judgeAvg += elm;
  }
  judgeAvg /= judgement.size();
  person._score = judgeAvg;
}

void printScore(const vector<Person> vec) {
  for (auto &elm : vec) {
    cout << elm._name << ": " << elm._score << endl;
  }
}

int main(void) {
  ::srand(::time(NULL));
  vector<Person> vec = {Person("A"), Person("B"), Person("C"), Person("D"),
                        Person("E")};
  for (auto &person : vec) {
    inputScore(person);
  }

  printScore(vec);
}
