//
// Created by 王泽鑫 on 2024/5/20.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <limits>
#include <functional>

/**
 * 练习14.34：定义一个函数对象类，令其执行if-then-else的操作：该类的
 * 调用运算符接受三个形参，它首先检查第一个形参，如果成功返回第二
 * 个形参的值；如果不成功返回第三个形参的值。
 */
class IfThenElse {
public:
    int operator()(bool b, int iA, int iB) {
        return b ? iA : iB;
    }
};

void q_14_34() {
    IfThenElse ifThenElse;
    std::cout << ifThenElse(true, 1, 2) << std::endl;
    std::cout << ifThenElse(false, 1, 2) << std::endl;
}

/**
 * 练习14.35：编写一个类似于PrintString的类，令其从istream中读取一行
 * 输入，然后返回一个表示我们所读内容的string。如果读取失败，返回
 * 空string。
 */
class GetString {
public:
    GetString(std::istream &i = std::cin) : is(i) {}

    std::string operator()() {
        std::string tmp;
        getline(is, tmp);
        return is ? tmp : std::string();
    }

private:
    std::istream &is;
};

void q_14_35() {
    GetString getString;
    auto str = getString();
    std::cout << str << std::endl;
}

/**
 * 练习14.36：使用前一个练习定义的类读取标准输入，将每一行保存为
 * vector的一个元素。
 */
void q_14_36() {
    GetString getString;
    std::vector<std::string> vec;
    for (std::string str; !(str = getString()).empty(); vec.push_back(str)) {

    }
    for (auto &elem: vec) {
        std::cout << elem << std::endl;
    }
}

/**
 * 练习14.37：编写一个类令其检查两个值是否相等。使用该对象及标准
 * 库算法编写程序，令其替换某个序列中具有给定值的所有实例。
 */
class IsEqual {
public:
    explicit IsEqual(int v) : val(v) {}

    bool operator()(int v) const {
        return v == val;
    }

private:
    int val;
};

void q_14_37() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6};

    std::cout << "Before: " << std::endl;
    std::for_each(vec.begin(), vec.end(), [](int val) {
        std::cout << val << " ";
    });

    IsEqual isEqual(3);
    std::replace_if(vec.begin(), vec.end(), isEqual, 8);

    std::cout << std::endl << "After: " << std::endl;
    std::for_each(vec.begin(), vec.end(), [](int val) {
        std::cout << val << " ";
    });
}

/**
 * 14.8.1节练习
 * 练习14.38：编写一个类令其检查某个给定的string对象的长度是否与一
 * 个阈值相等。使用该对象编写程序，统计并报告在输入的文件中长度为
 * 1的单词有多少个、长度为2的单词有多少个、……、长度为10的单词又
 * 有多少个。
 */
class IsInRange {
public:

    IsInRange(size_t l, size_t u) : _lower(l), _upper(u) {}

    [[nodiscard]] size_t lower_limit() const {
        return _lower;
    }

    [[nodiscard]] size_t upper_limit() const {
        return _upper;
    }

    bool operator()(const std::string &str) {
        return str.size() >= _lower && str.size() <= _upper;
    }

private:
    size_t _lower;
    size_t _upper;
};

/**
 * 练习14.39：修改上一题的程序令其报告长度在1至9之间的单词有多少
 * 个、长度在10以上的单词又有多少个。
 */
void q_14_39() {
    IsInRange range1To9(1, 9);
    size_t max = std::numeric_limits<size_t>::max();
    IsInRange rangeOver10(10, max);
    int res1To9 = 0, resOver10 = 0;
    std::fstream fs("./data.txt");
    for (std::string word; fs >> word;) {
        if (range1To9(word)) {
            ++res1To9;
        } else if (rangeOver10(word)) {
            ++resOver10;
        }
    }
    std::cout << "word size in range(1, 9): " << res1To9 << std::endl;
    std::cout << "word size over 10: " << resOver10 << std::endl;
}

/**

 * 练习14.40：重新编写10.3.2节（第349页）的biggies函数，使用函数对象
 * 类替换其中的lambda表达式。
 */

/**
 * 14.8.2节练习
 * 练习14.42：使用标准库函数对象及适配器定义一条表达式，令其
 * （a） 统计大于1024的值有多少个。
 * （b） 找到第一个不等于pooh的字符串。
 * （c） 将所有的值乘以2。
 */
void q_14_42() {
    std::vector<int> ivec = {1, 2, 1024, 1025, 1026};
    std::vector<std::string> svec = {"pooh", "world", "pooh", "hello"};

    auto count = std::count_if(ivec.cbegin(), ivec.cend(), std::bind(std::greater<int>(), std::placeholders::_1, 1024));
    std::cout << "count: " << count << std::endl;

    auto find = std::find_if(svec.cbegin(), svec.cend(),
                             std::bind(std::not_equal_to<std::string>(), std::placeholders::_1, "pooh"));
    std::cout << "find: " << *find << std::endl;

    std::transform(ivec.begin(), ivec.end(), ivec.begin(), std::bind(std::multiplies<int>(), std::placeholders::_1, 2));

    std::for_each(ivec.cbegin(), ivec.cend(), [](auto &elem) {
        std::cout << elem << " ";
    });
}

/**
 * 练习14.43：使用标准库函数对象判断一个给定的int值是否能被int容器
 * 中的所有元素整除。
 */
void q_14_43() {
    std::vector<int> ivec = {2, 4, 6, 5, 54};
    int val = 24;
    std::modulus<int> mod;
    auto res = std::all_of(ivec.cbegin(), ivec.cend(), [&val, &mod](auto &elem) -> bool {
        return mod(val, elem) == 0;
    });
    std::cout << res << std::endl;
}

/**
 * 14.8.3节练习
 * 练习14.44：编写一个简单的桌面计算器使其能处理二元运算。
 */
int add(int a, int b) {
    return a + b;
}

auto mod = [](int a, int b) -> int { return a % b; };

class Div {
public:
    int operator()(int a, int b) {
        return a / b;
    };
};

void q_14_44() {
    std::map<std::string, std::function<int(int, int)>> binops {
            {"+", add},
            {"-", std::minus<int>()},
            {"/", Div()},
            {"*", [](int a, int b) { return a * b;}},
            {"%", mod}
    };
    while (std::cout << "Pls enter as: num operator num :\n", true)
    {
        int lhs, rhs; std::string op;
        std::cin >> lhs >> op >> rhs;
        std::cout << binops[op](lhs, rhs) << std::endl;
    }
}

int main() {
//    q_14_34();
//    q_14_35();
//    q_14_36();
//    q_14_37();
//    q_14_39();
//    q_14_42();
//    q_14_43();
    q_14_44();
    return 0;
}