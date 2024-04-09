//
// Created by 王泽鑫 on 2024/4/9.
//

#include "StrBlob.h"

void StrBlob::push_back(const std::string &str) {
    data->push_back(str);
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string &StrBlob::front() const {
    check(0, "front const on empty StrBlob");
    return data->front();
}

const std::string &StrBlob::back() const {
    check(0, "back const on empty StrBlob");
    return data->back();
}
