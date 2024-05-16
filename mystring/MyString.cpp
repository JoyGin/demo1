//
// Created by 王泽鑫 on 2024/5/16.
//

#include "MyString.h"
#include <algorithm>

MyString::MyString(const char *ib) {
    char *ie = const_cast<char *>(ib);
    while (*ie) {
        ++ie;
    }
    ++ie;
    auto bepair = alloc_n_copy(ib, ie);
    elements = bepair.first;
    end = bepair.second;
}

MyString::MyString(const MyString &str) {
    auto bepair =  alloc_n_copy(str.elements, str.end);
    elements = bepair.first;
    end = bepair.second;
}

MyString &MyString::operator=(const MyString &str) {
    if (this != &str) {
        auto bepair =  alloc_n_copy(str.elements, str.end);
        free();
        elements = bepair.first;
        end = bepair.second;
    }
    return *this;
}

MyString::~MyString() {
    free();
}

std::pair<char *, char *> MyString::alloc_n_copy(const char *ib, const char *ie) {
    auto ob = alloc.allocate(ie - ib);
    auto oe = std::uninitialized_copy(ib, ie, ob);
    return {ob, oe};
}

void MyString::free() {
    if (elements) {
        std::for_each(elements, end, [this](auto &c){
            alloc.destroy(&c);
        });
        alloc.deallocate(elements, end - elements);
    }
}
