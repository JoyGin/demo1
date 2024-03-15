//
// Created by 王泽鑫 on 2024/3/10.
//

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>

/**
 * 练习9.2：定义一个list对象，其元素类型是int的deque。
 */
void q_9_2() {
    std::list<std::deque<int>> l;
}

/**
 * 练习9.4：编写函数，接受一对指向vector<int>的迭代器和一个int值。在
 * 两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
 */
bool findValue(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int target) {
    while (begin != end) {
        if (*begin == target) {
            return true;
        }
        ++begin;
    }
    return false;
}

void q_9_4() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    std::cout << findValue(v.begin(), v.end(), 3) << std::endl;
    std::cout << findValue(v.begin(), v.end(), 7) << std::endl;
}

/**
 * 练习9.5：重写上一题的函数，返回一个迭代器指向找到的元素。注
 * 意，程序必须处理未找到给定值的情况。
 */
std::vector<int>::const_iterator
findValueItr(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int target) {
    while (begin != end) {
        if (*begin == target) {
            return begin;
        }
        ++begin;
    }
    return end;
}

void q_9_5() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    auto itr1 = findValueItr(v.begin(), v.end(), 3);
    if (itr1 != v.end()) {
        std::cout << *itr1 << std::endl;
    } else {
        std::cout << "Not found!" << std::endl;
    }

    auto itr2 = findValueItr(v.begin(), v.end(), 7);
    if (itr2 != v.end()) {
        std::cout << *itr2 << std::endl;
    } else {
        std::cout << "Not found!" << std::endl;
    }
}

class NoDefault {
public:
    friend std::ostream &operator<<(std::ostream &os, NoDefault &noDefault);

    explicit NoDefault(int a) : val(a) {}

private:
    int val;
};

std::ostream &operator<<(std::ostream &os, NoDefault &noDefault) {
    os << noDefault.val;
    return os;
}

void testNoDefault() {
    std::vector<NoDefault> v(10, NoDefault(10));
    for (auto &item: v) {
        std::cout << item << std::endl;
    }
}

/**
 * 练习9.13：如何从一个list<int>初始化一个vector<double>？从一个
 * vector<int>又该如何创建？编写代码验证你的答案。
 */
void q_9_13() {
    std::list<int> il = {1, 2, 3, 4, 5, 6};
    std::vector<int> iv = {1, 2, 3, 4, 5, 6};
    std::vector<double> dvFromList(il.begin(), il.end());
    std::vector<double> diFromVec(iv.begin(), iv.end());

    for (const auto &i: dvFromList) {
        std::cout << i << std::endl;
    }

    for (const auto &i: diFromVec) {
        std::cout << i << std::endl;
    }
}

/**
 * 9.2.5节练习
 * 练习9.14：编写程序，将一个list中的char *指针（指向C风格字符串）元
 * 素赋值给一个vector中的string。
 */
void q_9_14() {
    std::list<const char *> ls = {"Hello", "World"};
    std::vector<std::string> sv;
    sv.assign((ls.cbegin()), ls.cend());

    for (const auto &s: sv) {
        std::cout << s << std::endl;
    }
}

/**
 * 9.2.7节练习
 * 练习9.15：编写程序，判定两个vector<int>是否相等。
 */
void q_9_15() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {1, 2, 3, 4, 5, 6};
    std::cout << "v is equal to v1 ? " << (v == v1 ? "true" : "false") << std::endl;
    std::cout << "v is equal to v2 ? " << (v == v2 ? "true" : "false") << std::endl;
}

/**
 * 练习9.16：重写上一题的程序，比较一个list<int>中的元素和一个
 * vector<int>中的元素。
 */
void q_9_16() {
    std::list<int> ls = {1, 2, 3, 4, 5, 6};
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {1, 2, 3, 4, 5, 6};
    std::cout << "ls is equal to v1 ? " << (std::vector<int>(ls.cbegin(), ls.cend()) == v1 ? "true" : "false")
              << std::endl;
    std::cout << "ls is equal to v2 ? " << (std::vector<int>(ls.cbegin(), ls.cend()) == v2 ? "true" : "false")
              << std::endl;
}

/**
 * 9.3.1节练习
 * 练习9.18：编写程序，从标准输入读取string序列，存入一个deque中。
 * 编写一个循环，用迭代器打印deque中的元素。
 */
void q_9_18() {
    std::deque<std::string> strDeq;
    std::string str;
    while (std::cin >> str) {
        strDeq.push_back(str);
    }

    for (const auto &s: strDeq) {
        std::cout << s << std::endl;
    }
}

/**
 * 练习9.19：重写上题的程序，用list替代deque。列出程序要做出哪些改变。
 */
void q_9_19() {
    std::list<std::string> strDeq;
    std::string str;
    while (std::cin >> str) {
        strDeq.push_back(str);
    }

    for (const auto &s: strDeq) {
        std::cout << s << std::endl;
    }
}

/**
 * 练习9.20：编写程序，从一个list<int>拷贝元素到两个deque中。值为偶
 * 数的所有元素都拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。
 */
void q_9_20() {
    std::list<int> ilist = {1, 2, 3, 4, 5, 6};
    std::deque<int> evenDeq;
    std::deque<int> oddDeq;

    for (const auto &i: ilist) {
        if (i % 2 == 0) {
            evenDeq.push_back(i);
        } else {
            oddDeq.push_back(i);
        }
    }

    std::cout << "evenDeq: ";
    for (const auto &i: evenDeq) {
        std::cout << i << " ";
    }

    std::cout << std::endl << "oddDeq: ";
    for (const auto &i: oddDeq) {
        std::cout << i << " ";
    }
}

/**
 * 9.3.2节练习
 * 练习9.24：编写程序，分别使用at、下标运算符、front和begin提取一个
 * vector中的第一个元素。在一个空vector上测试你的程序。
 */
void q_9_24() {
    std::vector<int> emptyV;
    auto i1 = emptyV.at(0);
    auto i2 = emptyV[0];
    auto i3 = emptyV.front();
    auto i4 = emptyV.begin();
}

/**
 * 练习9.26：使用下面代码定义的ia，将ia拷贝到一个vector和一个list中。
 * 使用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元
 * 素。
 */
void q_9_26() {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 31, 55, 89};
    std::vector<int> iv = std::vector<int>(std::begin(ia), std::end(ia));
    std::list<int> il = std::list<int>(std::begin(ia), std::end(ia));
    for (auto i = iv.begin(); i != iv.end();) {
        if (*i % 2 == 0) {
            i = iv.erase(i);
        } else {
            ++i;
        }
    }

    for (auto i = il.begin(); i != il.end();) {
        if (*i % 2 == 1) {
            i = il.erase(i);
        } else {
            ++i;
        }
    }

    for (auto i: iv) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (auto i: il) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/**
 * 9.3.4节练习
 * 练习9.27：编写程序，查找并删除forward_list<int>中的奇数元素。
 */
void q_9_27() {
    std::forward_list<int> fl = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::forward_list<int>::const_iterator pre = fl.before_begin();
    std::forward_list<int>::const_iterator current = fl.cbegin();
    while (current != fl.cend()) {
        if (*current % 2 == 1) {
            current = fl.erase_after(pre);
        } else {
            pre++;
            current++;
        }
    }

    for (const auto i: fl) {
        std::cout << i << " ";
    }
}

void q_9_27_new() {
    std::forward_list<int> fl = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto isOdd = [](int i) { return i & 0x1; };
    fl.remove_if(isOdd);

    for (const auto i: fl) {
        std::cout << i << " ";
    }
}

/**
 * 练习9.28：编写函数，接受一个forward_list<string>和两个string共三个
 * 参数。函数应在链表中查找第一个string，并将第二个string插入到紧接
 * 着第一个string之后的位置。若第一个string未在链表中，则将第二个
 * string插入到链表末尾。
 */
void insertIfContain(std::forward_list<std::string> &fl, const std::string &str1, const std::string &str2) {
    auto current = fl.cbegin();
    while (current != fl.cend()) {
        if (*current == str1) {
            current = fl.insert_after(current, str2);
        } else {
            current++;
        }
    }
}

void q_9_28() {
    std::forward_list<std::string> fl = {"hello", "world", "nice", "world", "to", "meet", "you", "world"};

    insertIfContain(fl, "world", "test");

    for (auto &s: fl) {
        std::cout << s << std::endl;
    }
}

int main(int argc, char **argv) {
//    q_9_4();
//    q_9_5();
//    q_9_13();
//    q_9_14();
//    q_9_15();
//    q_9_16();
//    q_9_18();
//    q_9_19();
//    q_9_20();
//    q_9_24();
//    q_9_26();
//    q_9_27();
//    q_9_27_new();
    q_9_28();
}