#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Student {
public:
    Student(int id, const char *name, int age)
        : _id(id),
        _age(age) {
            strcpy(_name, name);
        }

    Student(const Student & rhs)
        : _id(rhs._id),
        _age(rhs._age) {
            strcpy(_name, rhs._name);
        }

    Student & operator=(const Student & rhs) {
        this->_id = rhs._id;
        this->_age = rhs._age;
        strcpy(this->_name, rhs._name);
        return *this;
    }

    void print() {
        cout << "Student " << _name << endl;
        cout << "id " << _id << endl;
        cout << "age " << _age << endl;
    }
private:
    int _id;
    char _name[24];
    int _age;
};

int main(void) {
    Student s1(1, "xiaoming", 18);
    Student s2(s1);
    Student s3 = s2;
    s1.print();
    s2.print();
    s3.print();
    return 0;
}
