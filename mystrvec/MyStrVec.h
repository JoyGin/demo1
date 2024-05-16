//
// Created by 王泽鑫 on 2024/5/16.
//

#ifndef DEMO1_MYSTRVEC_H
#define DEMO1_MYSTRVEC_H

#include <string>
#include <memory>

// 分配空间存储数据
// 当缓存空间不够用时，才扩容

class MyStrVec {
public:
    MyStrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    MyStrVec(const MyStrVec &sv);

    MyStrVec(std::initializer_list<std::string> il);

    MyStrVec &operator=(const MyStrVec &sv);

    ~MyStrVec();

    void push_back(const std::string &str);

    [[nodiscard]] size_t size() const {
        return first_free - elements;
    }

    [[nodiscard]] size_t capacity() const {
        return cap - elements;
    }

    [[nodiscard]] std::string *begin() const {
        return elements;
    }

    [[nodiscard]] std::string *end() const {
        return first_free;
    }

    void reserve(size_t new_cap);

    void resize(size_t count);

    void resize(size_t count, const std::string &str);

private:
    void chk_n_alloc();

    void free();

    std::pair<std::string*, std::string*> alloc_n_copy(const std::string* b, const std::string *e);

private:
    std::allocator<std::string> alloc;
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};


#endif //DEMO1_MYSTRVEC_H
