//
// Created by 王泽鑫 on 2024/5/11.
//

#ifndef DEMO1_STRVEC_H
#define DEMO1_STRVEC_H

#include <string>
#include <memory>

//using std::string;

/**
 * 13.5节练习
 * 练习13.39：编写你自己版本的StrVec，包括自己版本的reserve、
 * capacity（参见9.4节，第318页）和resize（参见9.3.5节，第314页）。
 */

/**
 * 练习13.40：为你的StrVec类添加一个构造函数，它接受一个
 * initializer_list<string>参数。
 */

class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    StrVec(const StrVec &sv);

    StrVec(StrVec &&sv) noexcept;

    StrVec(std::initializer_list<std::string> il);

    StrVec &operator=(const StrVec &sv);

    StrVec &operator=(StrVec &&sv) noexcept;

    ~StrVec();

    void push_back(const std::string &str);

    size_t size() const {
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

    void resize(size_t count, const std::string &);

private:
    static std::allocator<std::string> alloc;

    void chk_n_alloc(); // 检查是否还有可用内存，无可用内存则进行内存扩展

    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);

    void free(); // 销毁元素并释放内存

    void reallocate(); // 重新分配更多内存

    void alloc_n_move(size_t new_cap);

    std::string *elements; // 指向分配的内存中的首元素
    std::string *first_free; // 指向最后一个实际元素之后的位置
    std::string *cap; // 指向分配的内存末尾之后的位置
};


#endif //DEMO1_STRVEC_H
