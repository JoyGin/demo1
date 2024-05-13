//
// Created by 王泽鑫 on 2024/5/8.
//

#include <iostream>
#include <string>
#include <assert.h>
#include "StrVec.h"

class CopyCon {
public:
    CopyCon() : val(0) {}

    CopyCon(const CopyCon &obj) : val(obj.val) {
        std::cout << "copy construction" << std::endl;
    }

    CopyCon &operator=(const CopyCon &obj) {
        if (this == &obj) {
            return *this;
        }
        std::cout << "operator=" << std::endl;
        return *this;
    }

private:
    int val;
};

/**
 * 给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员。
 * 你的构造函数应该动态分配一个新的`string`，并将对象
 * 拷贝到`ps`所指向的位置，而不是拷贝ps本身：
 */
class HasPtr {
public:
    explicit HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}

    HasPtr &operator=(const HasPtr &rhs_hp) {
        if (this == &rhs_hp) {
            return *this;
        }
        auto *temp_ps = new std::string(*rhs_hp.ps);
        delete ps;
        ps = temp_ps;
        i = rhs_hp.i;
        return *this;
    }

    ~HasPtr() {
        delete ps;
    }

private:
    std::string *ps;
    int i;
};

/**
 * 13.1.4节练习
 * 练习13.14：假定numbered是一个类，它有一个默认构造函数，能为每
 * 个对象生成一个唯一的序号，保存在名为mysn的数据成员中。假定
 * numbered使用合成的拷贝控制成员，并给定如下函数：
 * void f (numbered s) { std::cout << s.mysn << std::endl }
 * 则下面代码输出什么内容？
 */

class numbered_14 {
public:
    friend void f(numbered_14 s);

private:
    static int startVal;
    int mysn;
};

int numbered_14::startVal = 10;

void f(numbered_14 s) {
    std::cout << s.mysn << std::endl;
}

void q_13_14() {
    numbered_14 a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}

/**
 * 练习13.15：假定numbered定义了一个拷贝构造函数，能生成一个新的
 * 序号。这会改变上一题中调用的输出结果吗？如果会改变，为什么？新
 * 的输出结果是什么？
 */
class numbered_15 {
public:
    friend void f(numbered_15 s);

    numbered_15() = default;

    numbered_15(const numbered_15 &obj) : mysn(startVal++) {}

private:
    static int startVal;
    int mysn;
};

int numbered_15::startVal = 10;

void f(numbered_15 s) {
    std::cout << s.mysn << std::endl;
}

void q_13_15() {
    numbered_15 a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}

/**
 * 练习13.16：如果f中的参数是const numbered&，将会怎样？这会改变输
 * 出结果吗？如果会改变，为什么？新的输出结果是什么？
 */
class numbered_16 {
public:
    friend void f(const numbered_16 &s);

    numbered_16() = default;

    numbered_16(const numbered_16 &obj) : mysn(startVal++) {}

private:
    static int startVal;
    int mysn;
};

int numbered_16::startVal = 10;

void f(const numbered_16 &s) {
    std::cout << s.mysn << std::endl;
}

void q_13_16() {
    numbered_16 a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}

/**
 * 13.1.6节练习
 * 练习13.18：定义一个Employee类，它包含雇员的姓名和唯一的雇员证
 * 号。为这个类定义默认构造函数，以及接受一个表示雇员姓名的string
 * 的构造函数。每个构造函数应该通过递增一个static数据成员来生成一个
 * 唯一的证号。
 */
class Employee {
public:
    Employee();

    explicit Employee(std::string &n);

    Employee(const Employee &e) = delete;

    Employee &operator=(const Employee &e) = delete;

    [[nodiscard]] int id() const {
        return _id;
    }

private:
    std::string _name;
    int _id;
    static int s_increment;
};

int Employee::s_increment = 0;

Employee::Employee() {
    _id = s_increment++;
}

Employee::Employee(std::string &n) : _name(n) {
    _id = s_increment++;
}

/**
 * 13.2节练习
 * 练习13.22：假定我们希望HasPtr的行为像一个值。即，对于对象所指向
 * 的string成员，每个对象都有一份自己的拷贝。我们将在下一节介绍拷
 * 贝控制成员的定义。但是，你已经学习了定义这些成员所需的所有知
 * 识。在继续学习下一节之前，为HasPtr编写拷贝构造函数和拷贝赋值运
 * 算符。
 */
class HasPtr_22 {
public:
    friend void swap(HasPtr_22 &lhp, HasPtr_22 &rhp);

    friend bool operator<(const HasPtr_22 &lhp, const HasPtr_22 &rhp);

    explicit HasPtr_22(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}

    HasPtr_22(const HasPtr_22 &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}

    HasPtr_22 &operator=(const HasPtr_22 &hp) {
        if (this == &hp) {
            std::cout << "operator= on same obj" << std::endl;
            return *this;
        }
        auto new_ps = new std::string(*hp.ps);
        delete ps;
        ps = new_ps;
        i = hp.i;
        return *this;
    }

//    HasPtr_22& operator=(HasPtr_22 tmp)
//    {
//        swap(*this, tmp);
//        return *this;
//    }

    ~HasPtr_22() {
        delete ps;
    }

private:
    int i;
    std::string *ps;
};

/**
 * 13.2.2节练习
 * 练习13.27：定义你自己的使用引用计数版本的HasPtr。
 */
class HasPtr_27 {
public:
    explicit HasPtr_27(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new size_t(1)) {}

    HasPtr_27(const HasPtr_27 &hp) : ps(hp.ps), i(hp.i), use(hp.use) {
        ++*use;
    }

    HasPtr_27 &operator=(const HasPtr_27 &hp) {
        if (this == &hp) {
            return *this;
        }
        ++(*hp.use);
        --*use;
        if (*use == 0) {
            delete ps;
            delete use;
        }
        ps = hp.ps;
        i = hp.i;
        use = hp.use;
        return *this;
    }

    ~HasPtr_27() {
        --*use;
        if (*use == 0) {
            delete ps;
            delete use;
            std::cout << "destroy " << this << std::endl;
        }
    }

    int i_() const {
        return i;
    }

    std::string *ps_() {
        return ps;
    }

    size_t *use_() {
        return use;
    }

private:
    int i;
    std::string *ps;
    size_t *use;
};

void q_13_27() {
    HasPtr_27 hp1("hello");
    std::cout << "hp1 " << &hp1 << std::endl;
    assert(hp1.i_() == 0);
    assert(*(hp1.use_()) == 1);
    assert(*(hp1.ps_()) == "hello");

    HasPtr_27 hp2 = hp1;
    std::cout << "hp2 " << &hp2 << std::endl;
    assert(hp2.i_() == 0);
    assert(hp2.use_() == hp1.use_());
    assert(hp2.ps_() == hp1.ps_());
    assert(*(hp1.use_()) == 2);

    HasPtr_27 hp3;
    std::cout << "hp3 " << &hp3 << std::endl;
    hp3 = hp1;
    assert(hp3.i_() == 0);
    assert(hp3.use_() == hp1.use_());
    assert(hp3.ps_() == hp1.ps_());
    assert(*(hp1.use_()) == 3);
}

/**
 * 练习13.28：给定下面的类，为其实现一个默认构造函数和必要的拷贝
 * 控制成员。
 */
class TreeNode {
public:

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
public:

private:
    TreeNode *root;
};

/**
 * 练习13.30：为你的类值版本的HasPtr编写swap函数，并测试它。为你的
 * swap函数添加一个打印语句，指出函数什么时候执行。
 */

void swap(HasPtr_22 &lhp, HasPtr_22 &rhp) {
    using std::swap;
    swap(lhp.i, rhp.i);
    swap(lhp.ps, rhp.ps);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

void q_13_30() {
    HasPtr_22 hp1, hp2;
    swap(hp1, hp2);
}

/**
 * 练习13.31：为你的HasPtr类定义一个<运算符，并定义一个HasPtr的
 * vector。为这个vector添加一些元素，并对它执行sort。注意何时会调用
 * swap。
 */
bool operator<(const HasPtr_22 &lhp, const HasPtr_22 &rhp) {
    return *lhp.ps < *rhp.ps;
}

void q_13_31() {
    std::vector<HasPtr_22> vec;
    vec.push_back(HasPtr_22("hello"));
    vec.push_back(HasPtr_22("world"));
    vec.push_back(HasPtr_22("hi"));
    vec.push_back(HasPtr_22("array"));
    std::sort(vec.begin(), vec.end());
//    std::sort(vec.begin(), vec.end(), [](const HasPtr_22 &e1, const HasPtr_22 &e2) -> bool {
//        return *e1.ps < *e2.ps;
//    });
}

/**
 * 13.5节练习
 * 练习13.39：编写你自己版本的StrVec，包括自己版本的reserve、
 * capacity（参见9.4节，第318页）和resize（参见9.3.5节，第314页）。
 */
void q_13_39() {
    StrVec strVec;
    strVec.push_back("hello");
    strVec.push_back("world");
    strVec.resize(8);
    std::cout << "capacity=" << strVec.capacity() << std::endl;
}

/**
 * 练习13.40：为你的StrVec类添加一个构造函数，它接受一个
 * initializer_list<string>参数。
 */
void q_13_40() {
    StrVec sv({"hello", "world", "!"});
    std::for_each(sv.begin(), sv.end(), [](std::string &s) {
        std::cout << s << std::endl;
    });
}

/**
 * 练习13.44：编写标准库string类的简化版本，命名为String。你的类应该
 * 至少有一个默认构造函数和一个接受C风格字符串指针参数的构造函
 * 数。使用allocator为你的String类分配所需内存。
 */

/**
 * 练习13.47：对你在练习13.44（13.5节，第470页）中定义的String类，
 * 为它的拷贝构造函数和拷贝赋值运算符添加一条语句，在每次函数执行
 * 时打印一条信息。
 */

/**
 * 练习13.48：定义一个vector<String>并在其上多次调用push_back。运行
 * 你的程序，并观察String被拷贝了多少次。
 */

int main() {
//    q_13_14();
//    q_13_15();
//    q_13_16();
//    q_13_27();
//    q_13_30();
//    q_13_31();
//    q_13_39();
    q_13_40();
}