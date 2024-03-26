//
// Created by 王泽鑫 on 2024/3/10.
//

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <fstream>

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

/**
 * 9.5.1节练习
 * 练习9.41：编写程序，从一个vector<char>初始化一个string。
 */
void q_9_41() {
    std::vector<char> cv = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    std::string str = std::string(cv.cbegin(), cv.cend());
    std::cout << str << std::endl;
}

/**
 * 练习9.42：假定你希望每次读取一个字符存入一个string中，而且知道最
 * 少需要读取100个字符，应该如何提高程序的性能？
 */
void q_9_42() {
    std::string str;
    str.resize(100);
}

/**
 * 9.5.2节练习
 * 练习9.43：编写一个函数，接受三个string参数s、oldVal和newVal。使
 * 用迭代器及insert和erase函数将s中所有oldVal替换为newVal。测试你的
 * 程序，用它替换通用的简写形式，如，将"tho"替换为"though"，
 * 将"thru"替换为"through"。
 */
void replace_with(std::string &s, const std::string &oldVal, const std::string &newVal) {
    for (auto i = s.cbegin(); i != s.cend() - oldVal.size();) {
        if (oldVal == std::string(i, i + oldVal.size())) {
            i = s.erase(i, i + oldVal.size());
            i = s.insert(i, newVal.cbegin(), newVal.cend());
            i += newVal.size();
        } else {
            ++i;
        }
    }
}

void q_9_43() {
    std::string str = "To drive straight thru is a foolish, tho courageous act.";
    replace_with(str, "tho", "though");
    replace_with(str, "thru", "through");
    std::cout << str << std::endl;
}

/**
 * 练习9.44：重写上一题的函数，这次使用一个下标和replace。
 */
void replace_with_index(std::string &s, const std::string &oldVal, const std::string &newVal) {
    for (decltype(s.size()) i = 0; i < s.size() - oldVal.size();) {
        if (s[i] == oldVal[0] && oldVal == s.substr(i, oldVal.size())) {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
        } else {
            ++i;
        }
    }
}

void q_9_44() {
    std::string str = "To drive straight thru is a foolish, tho courageous act.";
    replace_with_index(str, "tho", "though");
    replace_with_index(str, "thru", "through");
    std::cout << str << std::endl;
}

/**
 * 练习9.45：编写一个函数，接受一个表示名字的string参数和两个分别表
 * 示前缀（如"Mr."或"Ms."）和后缀（如"Jr."或"III"）的字符串。使用迭
 * 代器及insert和append函数将前缀和后缀添加到给定的名字中，将生成的
 * 新string返回。
 */
std::string &add_pre_and_suffix(std::string &name, const std::string &prefix, const std::string &suffix) {
    name.insert(0, prefix);
    name.append(suffix);
    return name;
}

void q_9_45() {
    std::string name("Wang");
    std::cout << add_pre_and_suffix(name, "Mr.", ", Jr.") << std::endl;
}

/**
 * 练习9.46：重写上一题的函数，这次使用位置和长度来管理string，并只
 * 使用insert。
 */
std::string &add_pre_and_suffix_by_index(std::string &name, const std::string &prefix, const std::string &suffix) {
    name.insert(0, prefix);
    name.insert(name.size(), suffix);
    return name;
}

void q_9_46() {
    std::string name("Wang");
    std::cout << add_pre_and_suffix_by_index(name, "Mr.", ", Jr.") << std::endl;
}

/**
 * 9.5.3节练习
 * 练习9.47：编写程序，首先查找string "ab2c3d7R4E6"中的每个数字字
 * 符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用
 * find_first_of，第二个要使用find_first_not_of。
 */
void q_9_47() {
    std::string str = "ab2c3d7R4E6";
    std::string numbers = "0123456789";
    for (size_t pos = 0; pos < str.size(); ++pos) {
        pos = str.find_first_of(numbers, pos);
        if (pos == std::string::npos) {
            break;
        }
        std::cout << str[pos] << " ";
    }

    std::cout << std::endl;

    for (size_t pos = 0; pos < str.size(); ++pos) {
        pos = str.find_first_not_of(numbers, pos);
        if (pos == std::string::npos) {
            break;
        }
        std::cout << str[pos] << " ";
    }
    std::cout << std::endl;
}

/**
 * 练习9.49：如果一个字母延伸到中线之上，如d或f，则称其有上出头部
 * 分（ascender）。如果一个字母延伸到中线之下，如p或g，则称其有下
 * 出头部分（descender）。编写程序，读入一个单词文件，输出最长的既
 * 不包含上出头部分，也不包含下出头部分的单词。
 */
void q_9_49() {
    std::string targetChar = "aceimnorsuvwxz";
    std::ifstream ifs("./data.txt");
    if (!ifs) return;
    std::string longest;

    std::string cur;
    while (ifs >> cur) {
        if (cur.find_first_not_of(targetChar) == std::string::npos) {
            if (cur.size() > longest.size()) {
                longest = cur;
            }
        }
    }
    std::cout << longest << std::endl;
}

void q_9_49_answer() {
    std::ifstream ifs("./data.txt");
    if (!ifs) return;

    std::string longest;
    auto update_with = [&longest](std::string const &curr) {
        if (std::string::npos == curr.find_first_not_of("aceimnorsuvwxz"))
            longest = longest.size() < curr.size() ? curr : longest;
    };
    for (std::string curr; ifs >> curr; update_with(curr));
    std::cout << longest << std::endl;
}

/**
 * 9.5.5节练习
 * 练习9.50：编写程序处理一个vector<string>，其元素都表示整型值。计
 * 算vector中所有元素之和。修改程序，使之计算表示浮点值的string之和。
 */

/**
 * 练习9.51：设计一个类，它有三个unsigned成员，分别表示年、月和
 * 日。为其编写构造函数，接受一个表示日期的string参数。你的构造函
 * 数应该能处理不同数据格式，如January 1，1900、1/1/1990、Jan 1 1900
 * 等。
 */

/**
 * 9.6节练习
 * 练习9.52：使用stack处理括号化的表达式。当你看到一个左括号，将其
 * 记录下来。当你在一个左括号之后看到一个右括号，从stack中pop对
 * 象，直至遇到左括号，将左括号也一起弹出栈。然后将一个值（括号内
 * 的运算结果）push到栈中，表示一个括号化的（子）表达式已经处理完
 * 毕，被其运算结果所替代。
 */
void q_9_52() {
    using std::string;
    using std::cout;
    using std::endl;
    using std::stack;
    string expression{"This is (pezy)."};

    bool hasLefBracket = false;
    stack<char> charStack;
    for (size_t pos = 0; pos < expression.size(); ++pos) {
        if (expression[pos] == '(') {
            hasLefBracket = true;
            continue;
        } else if (expression[pos] == ')') {
            hasLefBracket = false;
        }
        if (hasLefBracket) {
            charStack.push(expression[pos]);
        }
    }
    string repstr;
    while (!charStack.empty()) {
        repstr += charStack.top();
        charStack.pop();
    }
    expression.replace(expression.find("(") + 1, repstr.size(), repstr);
    cout << expression << endl;
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
//    q_9_28();
//    q_9_41();
//    q_9_43();
//    q_9_44();
//    q_9_45();
//    q_9_46();
//    q_9_47();
//    q_9_49();
//    q_9_49_answer();
    q_9_52();
}