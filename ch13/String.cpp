//
// Created by 王泽鑫 on 2024/5/13.
//

#include "String.h"

#include <algorithm>
#include <iostream>

String::String(const char *s) {
    char *sl = const_cast<char*>(s);
    while (*sl) {
        ++sl;
    }
    range_initializer(s, ++sl);
}

String::String(const String &s) {
    range_initializer(s.elements, s.end);
    std::cout << "copy constructor" << std::endl;
}

String::String(String &&s) noexcept {
    elements = s.elements;
    end = s.end;
    s.elements = s.end = nullptr;
}

String &String::operator=(const String &s) {
    if (this != &s) {
        auto newStr = alloc_n_copy(s.elements, s.end);
        free();
        elements = newStr.first;
        end = newStr.second;
        std::cout << "copy-assignment" << std::endl;
    }
    return *this;
}

String &String::operator=(String &&s) noexcept {
    if (this != &s) {
        free();
        elements = s.elements;
        end = s.end;
        s.elements = s.end = nullptr;
    }
    return *this;
}

String::~String() {
    free();
}

std::pair<char*,char*> String::alloc_n_copy(const char *b, const char *e) {
    auto newData = alloc.allocate(e - b);
    auto newEnd = std::uninitialized_copy(b, e, newData);
    return {newData, newEnd};
}

void String::range_initializer(const char *b, const char *e){
    auto newStr = alloc_n_copy(b, e);
    elements = newStr.first;
    end = newStr.second;
}

void String::free(){
    if (elements) {
        std::for_each(elements, end, [this](char &c) {
           alloc.destroy(&c);
        });
        alloc.deallocate(elements, end - elements);
    }
}