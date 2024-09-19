#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer {
public:
    //静态成员函数
    static Computer * getInstance(void) {
        if(_pInstance == nullptr) {
            _pInstance = new Computer("Apple", 10000);
        }
        return _pInstance;
    }

    //init函数
    void init(const char * brand, int price) {
        delete [] _brand;
        _brand = new char[strlen(brand) + 1]();
        strcpy(_brand, brand);
        _price = price;
    }

    //destory函数
    static void destory(void) {
        if(_pInstance) {
            cout << "执行destory函数" << endl;
            delete _pInstance;
            _pInstance = nullptr;
            cout << "执行destory函数2" << endl;
        }
    }

    void print(void) const {
        cout << "brand: " << _brand << endl;
        cout << "price: " << _price << endl;
    }

private:
    //构造函数进入私有
    Computer(const char * brand, int price) {
        _brand = new char[strlen(brand) + 1]();
        strcpy(_brand, brand);
        _price = price;
    }

    //禁止生成或调用拷贝构造函数和赋值运算符函数
    Computer(const Computer & rhs) = delete;
    Computer & operator=(const Computer & rhs) = delete;

    //析构函数回收数据成员指向的堆空间
    ~Computer(void) {
        cout << "执行析构函数" << endl;
        delete [] _brand;
        _brand = nullptr;
    }

private:
    char *_brand;
    int _price;
    static Computer *_pInstance;
};
Computer * Computer::_pInstance = nullptr;

int main(void) {
    Computer::getInstance()->print();
    Computer::getInstance()->init("Lenovo", 6000);
    Computer::getInstance()->print();
    Computer::getInstance()->print();
    Computer::destory();
    return 0;
}
