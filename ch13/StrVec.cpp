//
// Created by 王泽鑫 on 2024/5/11.
//

#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;

void StrVec::chk_n_alloc() {
    if (size() == capacity()) {
        reallocate();
    }
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto begin = first_free; begin != elements;) {
            alloc.destroy(--begin);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

//void StrVec::free() {
//    for_each(elements, first_free, [](std::string &rhs){ alloc.destroy(&rhs); });
//}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

StrVec::StrVec(const StrVec &sv) {
    auto newdata = alloc_n_copy(sv.begin(), sv.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &sv) {
    if (this != &sv) {
        auto data = alloc_n_copy(sv.begin(), sv.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
    }
    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string &str) {
    chk_n_alloc();
    alloc.construct(first_free++, str);
}

//StrVec::StrVec(std::initializer_list<std::string> il) {
//    elements = alloc.allocate(il.size());
//    first_free = cap = elements + il.size();
//    int i = 0;
//    for (auto cur = il.begin(); cur != il.end(); ++cur, ++i) {
//        alloc.construct(elements + i, *cur);
//    }
//}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

void StrVec::reserve(size_t new_cap) {
    if (new_cap > capacity()) {
        alloc_n_move(new_cap);
    }
}

void StrVec::resize(size_t count) {
    resize(count, std::string());
}

void StrVec::resize(size_t count, const std::string &s) {
    if (count > size()) {
        if (count > capacity()) {
            reserve(count * 2);
        }
        for (size_t i = size(); i != count; ++i) {
            alloc.construct(first_free++, s);
        }
    } else {
        while (first_free != elements + count) {
            alloc.destroy(--first_free);
        }
    }
}

void StrVec::alloc_n_move(size_t new_cap) {
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (int i = 0; i < size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = cap = dest;
}
