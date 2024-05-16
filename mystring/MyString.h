//
// Created by 王泽鑫 on 2024/5/16.
//

#ifndef DEMO1_MYSTRING_H
#define DEMO1_MYSTRING_H

#include <memory>

class MyString {
public:
    MyString() : MyString("") {}

    explicit MyString(const char *ib);

    MyString(const MyString &str);

    MyString &operator=(const MyString &str);

    ~MyString();

    [[nodiscard]] const char *c_str() const {
        return elements;
    }

    [[nodiscard]] size_t size() const {
        return end - elements;
    }

    [[nodiscard]] size_t length() const {
        return end - elements - 1;
    }

private:
    std::pair<char *, char *> alloc_n_copy(const char *b, const char *e);

    void free();

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};


#endif //DEMO1_MYSTRING_H
