//
// Created by 王泽鑫 on 2024/5/13.
//

#ifndef DEMO1_STRING_H
#define DEMO1_STRING_H

#include <memory>

class String {
public:
    String() : String("") {}

    String(const char *);

    String(const String &s);

    String &operator=(const String &s);

    ~String();

    [[nodiscard]]const char *c_str() const {
        return elements;
    }

    [[nodiscard]] size_t size() const {
        return end - elements;
    }

    [[nodiscard]] size_t length() const {
        return end - elements - 1;
    }

private:
    std::pair<char*,char*> alloc_n_copy(const char *b, const char *e);

    void range_initializer(const char *b, const char *e);

    void free();

private:
    char *elements;
    char *end;
    std::allocator<char> alloc;
};


#endif //DEMO1_STRING_H
