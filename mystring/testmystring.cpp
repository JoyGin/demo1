//
// Created by 王泽鑫 on 2024/5/16.
//

#include "MyString.h"
#include <iostream>

int main() {
    MyString myString1; // 测试默认构造函数
    MyString myString2("hello"); // 测试 c 字符串构造函数
    MyString myString3 = myString2; // 测试复制构造函数

    std::cout << myString1.c_str() << std::endl;
    std::cout << myString2.c_str() << std::endl;
    std::cout << myString3.c_str() << std::endl;

    // 测试拷贝赋值运算符
    myString3 = myString1;
    std::cout << myString3.c_str() << std::endl;

    // 测试拷贝赋值运算符
    myString3 = myString2;
    std::cout << myString3.c_str() << std::endl;
    return 0;
}