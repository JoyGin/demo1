//
// Created by 王泽鑫 on 2024/5/11.
//

#include "StrVec.h"


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
