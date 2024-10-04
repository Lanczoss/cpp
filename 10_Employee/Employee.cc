#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Person {
 public:
  Person(const char *name, int age)
      : _name(new char[strlen(name) + 1]()), _age(age) {
    strcpy(_name, name);
  }

  ~Person() {
    if (_name != nullptr) {
      delete[] _name;
    }
    _name = nullptr;
  }

  Person(const Person &rhs) {
    _name = new char[strlen(rhs._name) + 1]();
    strcpy(_name, rhs._name);
    _age = rhs._age;
  }

  Person &operator=(const Person &rhs) {
    if (this != &rhs) {
      delete[] _name;
      _name = new char[strlen(rhs._name) + 1]();
      strcpy(_name, rhs._name);
      _age = rhs._age;
    }
    return *this;
  }

  void display() const {
    cout << "name: " << _name << endl;
    cout << "age: " << _age << endl;
  }

 private:
  char *_name;
  int _age;
};

class Employee : public Person {
 public:
  Employee(const char *name, int age, const char *department, double salary)
      : Person(name, age),
        _department(new char[strlen(department) + 1]()),
        _salary(salary) {
    ++employeenums;
    total += salary;
    strcpy(_department, department);
  }

  ~Employee() {
    if (_department != nullptr) {
      delete[] _department;
    }
    _department = nullptr;
  }

  Employee(const Employee &rhs) : Person(rhs), _salary(rhs._salary) {
    _department = new char[strlen(rhs._department) + 1]();
    strcpy(_department, rhs._department);
  }

  Employee &operator=(const Employee &rhs) {
    if (this != &rhs) {
      Person::operator=(rhs);
      delete[] _department;
      _department = new char[strlen(rhs._department) + 1]();
      strcpy(_department, rhs._department);
      _salary = rhs._salary;
    }
    return *this;
  }

  static double countAvg(const Employee ems[], int nums) {
    if (nums == 0) {
      cout << "除数不能为0" << endl;
      return 0;
    }
    for (int idx = 0; idx < nums; ++idx) {
      total += ems[idx]._salary;
    }
    return total / nums;
  }

  void display() const {
    Person::display();
    cout << "department: " << _department << endl;
    cout << "_salary: " << _salary << endl;
    cout << endl;
  }

 private:
  char *_department;
  double _salary;
  static double total;
  static int employeenums;
};

double Employee::total = 0;
int Employee::employeenums = 0;

int main(void) {
  Employee emp1("Alice", 30, "HR", 5000.0);
  Employee emp2("Bob", 25, "IT", 6000.0);
  Employee emp3("Charlie", 28, "Marketing", 5500.0);

  emp1.display();
  emp2.display();
  emp3.display();

  // 计算平均工资
  Employee employees[] = {emp1, emp2, emp3};
  std::cout << "平均工资: " << Employee::countAvg(employees, 3)
            << std::endl;
  return 0;
}