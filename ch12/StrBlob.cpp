//
// Created by 王泽鑫 on 2024/4/9.
//

#include "StrBlob.h"

void StrBlob::push_back(const std::string &str) const {
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

StrBlobPtr StrBlob::begin() const {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() const {
    return StrBlobPtr(*this, size());
}

void StrBlob::push_back(std::string &&str) const {
    data->push_back(std::move(str));
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    if (!lhs.wptr.expired() && !rhs.wptr.expired()) {
        return (lhs.wptr.lock() == rhs.wptr.lock()) && (lhs.curr == rhs.curr);
    } else {
        return false;
    }
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}
