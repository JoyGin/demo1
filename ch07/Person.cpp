//
// Created by 王泽鑫 on 2024/3/3.
//

#include "Person.h"

/**
 * 练习7.9：对于7.1.2节（第233页）练习中的代码，添加读取和打印
 * Person对象的操作。
 */
std::istream &read(std::istream &is, Person &person) {
    is >> person.name >> person.name;
    return is;
}

std::ostream &print(std::ostream &os, const Person &person) {
    os << "_name: " + person.name << ", address: " << person.address;
    return os;
}