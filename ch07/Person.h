//
// Created by 王泽鑫 on 2024/3/3.
//

#ifndef DEMO1_PERSON_H
#define DEMO1_PERSON_H

#include <string>
#include <iostream>

class Person;

std::istream &read(std::istream &is, Person &person);

class Person {
public:
    std::string name;
    std::string address;

    /**
    * 练习7.15：为你的Person类添加正确的构造函数。
    */
    Person() = default;

    Person(const std::string &name, const std::string &address) : name(name), address(address) {}

    explicit Person(std::istream &is) {
        read(is, *this);
    }

    [[nodiscard]] const std::string &getName() const {
        return name;
    }

    [[nodiscard]] const std::string &getAddress() const {
        return address;
    }
};

/**
 * 练习7.9：对于7.1.2节（第233页）练习中的代码，添加读取和打印
 * Person对象的操作。
 */

std::ostream &print(std::ostream &os, const Person &person);

#endif //DEMO1_PERSON_H
