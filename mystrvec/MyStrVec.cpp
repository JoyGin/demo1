//
// Created by 王泽鑫 on 2024/5/16.
//

#include "MyStrVec.h"

MyStrVec::MyStrVec(const MyStrVec &sv) {
    auto bepair = alloc_n_copy(sv.begin(), sv.end());
    elements = bepair.first;
    first_free = cap = bepair.second;
}

MyStrVec::MyStrVec(std::initializer_list<std::string> il) {
    auto bepair = alloc_n_copy(il.begin(), il.end());
    elements = bepair.first;
    first_free = cap = bepair.second;
}

MyStrVec &MyStrVec::operator=(const MyStrVec &sv) {
    if (this != &sv) {
        auto bepair = alloc_n_copy(sv.begin(), sv.end());
        free();
        elements = bepair.first;
        first_free = cap = bepair.second;
    }
    return *this;
}

MyStrVec::~MyStrVec() {
    free();
}

void MyStrVec::push_back(const std::string &str) {
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

void MyStrVec::chk_n_alloc() {
    // 判断是否有可用内存
    if (first_free == cap) {
        // 无可用内存，重新分配
        auto sz = size();
        size_t newCapacity = sz > 0 ? sz * 2 : 1;
        auto pNewElems = alloc.allocate(newCapacity);
        // 拷贝数据到新内存
        for (int i = 0; i < sz; ++i) {
            alloc.construct(pNewElems + i, std::move(*(elements + i)));
        }
        // 释放旧内存
        free();
        elements = pNewElems;
        first_free = pNewElems + sz;
        cap = elements + newCapacity;
    }
}

void MyStrVec::free() {
    size_t sz = size();
    auto pend = first_free;
    for (int i = 0; i < sz; ++i) {
        alloc.destroy(--pend);
    }
    alloc.deallocate(elements, sz);
    elements = first_free = cap = nullptr;
}

std::pair<std::string *, std::string *> MyStrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto newElems = alloc.allocate(e - b);
    auto newEnd = std::uninitialized_copy(b, e, newElems);
    return {newElems, newEnd};
}

void MyStrVec::reserve(size_t new_cap) {
    // 如果新内存比较大，则分配新的，否则不改变
    if (new_cap > capacity()) {
        auto pNewElems = alloc.allocate(new_cap);
        auto sz = size();
        for (int i = 0; i < sz; ++i) {
            alloc.construct(pNewElems + i, std::move(*(elements + i)));
        }
        free();
        elements = pNewElems;
        first_free = elements + sz;
        cap = elements + new_cap;
    }
}

void MyStrVec::resize(size_t count) {
    resize(count, std::string());
}

void MyStrVec::resize(size_t count, const std::string &str) {
    auto sz = size();
    if (count > sz) {
        if (count > capacity()) {
            reserve(count * 2);
        }
        for (auto i = sz; i < count; ++i) {
            alloc.construct(first_free++, str);
        }
    } else {
        for (int i = 0; i < sz - count; ++i) {
            alloc.destroy(--first_free);
        }
    }
}


