//
// Created by 王泽鑫 on 2024/5/16.
//

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "MyStrVec.h"

int main() {
    MyStrVec myStrVec1;
    MyStrVec myStrVec2({"hello", "world", "hi", "universe"});
    MyStrVec myStrVec3 = myStrVec1;

    myStrVec1.push_back("hello1");
    myStrVec1.push_back("world1");

    myStrVec3.push_back("hello3");
    myStrVec3.push_back("world3");
    myStrVec3.push_back("today");
    myStrVec3.push_back("is");
    myStrVec3.push_back("Thursday");
    myStrVec3.push_back("tomorrow");
    myStrVec3.push_back("is");
    myStrVec3.push_back("Friday");
    myStrVec3.push_back("Good");

    std::cout << "myStrVec1(size=" << myStrVec1.size() << ", capacity=" << myStrVec1.capacity() << ")" << std::endl;
    std::for_each(myStrVec1.begin(), myStrVec1.end(), [](const std::string &str) {
       std::cout << str << std::endl;
    });

    std::cout << "myStrVec2(size=" << myStrVec2.size() << ", capacity=" << myStrVec2.capacity() << ")" << std::endl;
    std::for_each(myStrVec2.begin(), myStrVec2.end(), [](const std::string &str) {
        std::cout << str << std::endl;
    });

    std::cout << "myStrVec3(size=" << myStrVec3.size() << ", capacity=" << myStrVec3.capacity() << ")" << std::endl;
    std::for_each(myStrVec3.begin(), myStrVec3.end(), [](const std::string &str) {
        std::cout << str << std::endl;
    });
    return 0;
}