//
// Created by 王泽鑫 on 2024/3/3.
//

#ifndef DEMO1_PERSON_H
#define DEMO1_PERSON_H

#include <string>
#include <iostream>

class Person {
    friend std::istream &read(std::istream &is, Person &person);

    friend std::ostream &print(std::ostream &os, const Person &person);

private:
    std::string name;
    std::string address;

public:
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

#endif //DEMO1_PERSON_H
