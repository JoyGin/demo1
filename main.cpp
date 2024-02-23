#include <iostream>

class MyClass {
private:
    int data;
public:
    MyClass(int data) : data(data) {}

    int getData() {
        return data;
    }
};

// 测试默认复制构造函数
void testMyClass() {
    MyClass myClass(10);
    MyClass myClass1(20);
    myClass1 = myClass;
    std::cout << myClass.getData() << std::endl;
    std::cout << myClass1.getData() << std::endl;
    // 输出 myClass 和 myClass1 的地址
    std::cout << &myClass << std::endl;
    std::cout << &myClass1 << std::endl;
}

int main() {
    std::string s = "some thing";
    std::cout << s << std::endl;
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); index++) {
        s[index] = toupper(s[index]);
    }
    std::cout << s << std::endl;
    return 0;
}
