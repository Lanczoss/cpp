#include <iostream>
#include <list>
#include <string>
using std::cout;
using std::endl;
using std::list;
using std::string;

struct Student {
  string name;
  int age;
  double chinese;
  double math;
  double english;

  double sum() const { return chinese + math + english; }
};

bool CompareStu(const Student &lhs, const Student &rhs) {
  if (lhs.sum() > rhs.sum()) {
    return true;
  } else if (lhs.sum() == rhs.sum()) {
    // if (lhs.chinese > rhs.chinese) {
    //   return true;
    // } else {
    //   return false;
    // }
    return lhs.chinese > rhs.chinese;
  } else {
    return false;
  }
}

int main(void) {
  list<Student> students = {{"Alice", 18, 90, 85, 88},
                            {"Bob", 19, 85, 95, 90},
                            {"Charlie", 17, 90, 90, 95},
                            {"David", 18, 85, 80, 78},
                            {"Eva", 20, 95, 90, 85}};
  students.sort(CompareStu);
  // students.sort(std::greater<Student>());
  for (auto &stu : students) {
    cout << stu.name << " " << "sum:" << stu.sum() << " chinese:" << stu.chinese
         << endl;
  }
  return 0;
}
