//
// Created by 王泽鑫 on 2024/3/25.
//
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <numeric>
#include <sstream>
#include <fstream>
#include "Sales_data.h"
#include "Sales_item.h"

/**
 * 10.1节练习
 * 练习10.1：头文件algorithm中定义了一个名为count的函数，它类似
 * find，接受一对迭代器和一个值作为参数。count返回给定值在序列中出
 * 现的次数。编写程序，读取int序列存入vector中，打印有多少个元素的
 * 值等于给定值。
 */
void q_10_1() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 6, 5, 4, 4};
    auto times = std::count(vec.cbegin(), vec.cend(), 4);
    std::cout << times << std::endl;
}

/**
 * 练习10.2：重做上一题，但读取string序列存入list中。
 */
void q_10_2() {
    std::list<std::string> l = {"aa", "aaa", "aa", "cc"};
    auto times = std::count(l.cbegin(), l.cend(), "aa");
    std::cout << times << std::endl;
}

/**
 * 10.2.1节练习
 * 练习10.3：用accumulate求一个vector<int>中的元素之和。
 */
void q_10_3() {
    std::vector<int> vec = {1, 2, 3, 4};
    auto res = std::accumulate(vec.cbegin(), vec.cend(), 0);
    std::cout << res << std::endl;
}

/**
 * 10.2.2节练习
 * 练习10.6：编写程序，使用fill_n将一个序列中的int值都设置为0。
 */
void q_10_6() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::fill_n(vec.begin(), vec.size(), 0);
    for (auto i: vec) {
        std::cout << i << std::endl;
    }
}

/**
 * 10.2.3节练习
 * 练习10.9：实现你自己的elimDups。测试你的程序，分别在读取输入
 * 后、调用unique后以及调用erase后打印vector的内容。
 */
void print(std::vector<std::string>::const_iterator begin, std::vector<std::string>::const_iterator end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

void q_10_9() {
    std::string str = "the quick red fox jumps over the slow red turtle";
    std::stringstream ss(str);
    std::vector<std::string> vec;
    std::string tmp;
    while (ss >> tmp) {
        vec.push_back(tmp);
    }
    print(vec.cbegin(), vec.cend());

    std::sort(vec.begin(), vec.end());
    auto unique_end = std::unique(vec.begin(), vec.end());
    print(vec.cbegin(), vec.cend());

    vec.erase(unique_end, vec.cend());
    print(vec.cbegin(), vec.cend());
}

/**
 * 10.3.1节练习
 * 练习10.11：编写程序，使用stable_sort和isShorter将传递给你的elimDups
 * 版本的vector排序。打印vector的内容，验证你的程序的正确性。
 */
void elimDups(std::vector<std::string> &vec) {
    std::sort(vec.begin(), vec.end());
    auto unique_end = std::unique(vec.begin(), vec.end());
    vec.erase(unique_end, vec.cend());
}

inline bool isShorter(const std::string &ls, const std::string &rs) {
    return ls.size() < rs.size();
}

void q_10_11() {
    std::string str = "the quick red fox jumps over the slow red turtle";
    std::stringstream ss(str);
    std::vector<std::string> words;
    std::string tmp;
    while (ss >> tmp) {
        words.push_back(tmp);
    }

    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);

    print(words.cbegin(), words.cend());
}

/**
 * 练习10.12：编写名为compareIsbn的函数，比较两个Sales_data对象的
 * isbn（）成员。使用这个函数排序一个保存Sales_data对象的vector。
 */
inline bool compareIsbn_10_12(const Sales_data &lsd, const Sales_data &rsd) {
    return lsd.isbn().size() < rsd.isbn().size();
}

void q_10_12() {
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    std::vector<Sales_data> v{d1, d2, d3, d4, d5};

    std::sort(v.begin(), v.end(), compareIsbn_10_12);

    for (auto &data: v) {
        std::cout << data.isbn() << std::endl;
    }
}

/**
 * 练习10.13：标准库定义了名为partition的算法，它接受一个谓词，对容
 * 器内容进行划分，使得谓词为true的值会排在容器的前半部分，而使谓
 * 词为false的值会排在后半部分。算法返回一个迭代器，指向最后一个使
 * 谓词为true的元素之后的位置。编写函数，接受一个string，返回一个
 * bool值，指出string是否有5个或更多字符。使用此函数划分words。打印
 * 出长度大于等于5的元素。
 */
inline bool predicate(const std::string &str) {
    return str.size() >= 5;
}

void q_10_13() {
    auto v = std::vector<std::string>{"a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa"};
    auto satisfy_end = std::partition(v.begin(), v.end(), predicate);
    for (auto iter = v.cbegin(); iter != satisfy_end; ++iter) {
        std::cout << *iter << std::endl;
    }
}

/**
 * 10.3.2节练习
 * 练习10.14：编写一个lambda，接受两个int，返回它们的和。
 */
void q_10_14() {
    auto f = [](int a, int b) -> int { return a + b; };

    std::cout << f(10, 5) << std::endl;
}

/**
 * 练习10.15：编写一个lambda，捕获它所在函数的int，并接受一个int参
 * 数。lambda应该返回捕获的int和int参数的和。
 */
void q_10_15() {
    int a = 10;
    auto f = [a](int b) -> int { return a + b; };

    std::cout << f(5) << std::endl;
}

/**
 * 练习10.16：使用lambda编写你自己版本的biggies。
 */
void q_10_16() {
    std::string str = "the quick red fox jumps over the slow red turtle";
    std::stringstream ss(str);
    std::vector<std::string> words;
    std::string tmp;
    while (ss >> tmp) {
        words.push_back(tmp);
    }
    print(words.cbegin(), words.cend());

    // 按字典排序
    std::sort(words.begin(), words.end());
    // 去重
    auto unique_end = std::unique(words.begin(), words.end());
    // 删除多余
    words.erase(unique_end, words.cend());
    // 按长度排序，并保留字典序
    std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) -> bool {
        return a.size() < b.size();
    });
    // 计算满足大于 sz 的数目
    int sz = 5;
    auto begin_large_sz = std::find_if(words.begin(), words.end(), [sz](const std::string &s) -> bool {
        return s.size() >= sz;
    });
    auto count = words.end() - begin_large_sz;
    std::cout << "count = " << count << std::endl;
    // 输出长度大于给定值的字符串
    while (begin_large_sz != words.end()) {
        std::cout << *begin_large_sz << " ";
        ++begin_large_sz;
    }
    std::cout << std::endl;
}

/**
 * 练习10.17：重写10.3.1节练习10.12（第345页）的程序，在对sort的调用
 * 中使用lambda来代替函数compareIsbn。
 */
void q_10_17() {
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    std::vector<Sales_data> v{d1, d2, d3, d4, d5};

    std::sort(v.begin(), v.end(), [](const Sales_data &a, const Sales_data &b) -> bool {
        return a.isbn().size() < b.isbn().size();
    });

    for (auto &data: v) {
        std::cout << data.isbn() << std::endl;
    }
}

/**
 * 练习10.18：重写biggies，用partition代替find_if。我们在10.3.1节练习
 * 10.13（第345页）中介绍了partition算法。
 */
void q_10_18() {
    std::string str = "the quick red fox jumps over the slow red turtle";
    std::stringstream ss(str);
    std::vector<std::string> words;
    std::string tmp;
    while (ss >> tmp) {
        words.push_back(tmp);
    }
    print(words.cbegin(), words.cend());

    // 按字典排序
    std::sort(words.begin(), words.end());
    // 去重
    auto unique_end = std::unique(words.begin(), words.end());
    // 删除多余
    words.erase(unique_end, words.cend());
    // 按长度排序，并保留字典序
    std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) -> bool {
        return a.size() < b.size();
    });
    // 计算满足大于 sz 的数目
    int sz = 5;
    auto begin_large_sz = std::partition(words.begin(), words.end(), [sz](const std::string &s) -> bool {
        return s.size() < sz;
    });
    auto count = words.end() - begin_large_sz;
    std::cout << "count = " << count << std::endl;
    // 输出长度大于给定值的字符串
    while (begin_large_sz != words.end()) {
        std::cout << *begin_large_sz << " ";
        ++begin_large_sz;
    }
    std::cout << std::endl;
}

/**
 * 练习10.19：用stable_partition重写前一题的程序，与stable_sort类似，在
 * 划分后的序列中维持原有元素的顺序。
 */
void q_10_19() {
    std::string str = "the quick red fox jumps over the slow red turtle";
    std::stringstream ss(str);
    std::vector<std::string> words;
    std::string tmp;
    while (ss >> tmp) {
        words.push_back(tmp);
    }
    print(words.cbegin(), words.cend());

    // 按字典排序
    std::sort(words.begin(), words.end());
    // 去重
    auto unique_end = std::unique(words.begin(), words.end());
    // 删除多余
    words.erase(unique_end, words.cend());
    // 按长度排序，并保留字典序
    std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) -> bool {
        return a.size() < b.size();
    });
    // 计算满足大于 sz 的数目
    int sz = 5;
    auto begin_large_sz = std::stable_partition(words.begin(), words.end(), [sz](const std::string &s) -> bool {
        return s.size() < sz;
    });
    auto count = words.end() - begin_large_sz;
    std::cout << "count = " << count << std::endl;
    // 输出长度大于给定值的字符串
    while (begin_large_sz != words.end()) {
        std::cout << *begin_large_sz << " ";
        ++begin_large_sz;
    }
    std::cout << std::endl;
}

/**
 * 10.3.3节练习
 * 练习10.20：标准库定义了一个名为count_if的算法。类似find_if，此函
 * 数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范
 * 围中每个元素执行。count_if返回一个计数值，表示谓词有多少次为
 * 真。使用count_if重写我们程序中统计有多少单词长度超过6的部分。
 */
size_t bigerThan6(const std::vector<std::string> &v) {
    int sz = 6;
    return std::count_if(v.cbegin(), v.cend(), [sz](const std::string &s) -> bool {
        return s.size() > 6;
    });
}

void q_10_20() {
    std::vector<std::string> v{
            "alan", "moophy", "1234567", "1234567", "1234567", "1234567"
    };
    std::cout << "size bigger than 6: " << bigerThan6(v) << std::endl;
}

/**
 * 练习10.21：编写一个lambda，捕获一个局部int变量，并递减变量值，
 * 直至它变为0。一旦变量变为0，再调用lambda应该不再递减变量。
 * lambda应该返回一个bool值，指出捕获的变量是否为0。
 */
void q_10_21() {
    int val = 6;
    auto lmb = [&val]() -> bool {
        if (val <= 0) {
            std::cout << "stop" << std::endl;
            return true;
        } else {
            std::cout << "count down, from " << val << " to " << val - 1 << std::endl;
            --val;
            return false;
        }
    };
    while (!lmb());
}

/**
 * 10.3.4节练习
 * 练习10.22：重写统计长度小于等于6的单词数量的程序，使用函数代替
 * lambda。
 */
inline bool isLesserThanOrEqualTo6(const std::string &s, int sz) {
    return s.size() <= sz;
}

void q_10_22() {
    std::vector<std::string> authors{"Mooophy", "pezy", "Queequeg90", "shbling", "evan617"};
    auto count = std::count_if(authors.cbegin(), authors.cend(),
                               std::bind(isLesserThanOrEqualTo6, std::placeholders::_1, 6));
    std::cout << count << std::endl;
}

/**
 * 练习10.24：给定一个string，使用bind和check_size在一个int的vector中
 * 查找第一个大于string长度的值。
 */
inline bool check_size(const std::string &s, const std::string::size_type sz) {
    return s.size() < sz;
}

void q_10_24() {
    std::string s = "hello";
    std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto itr = std::find_if(iv.cbegin(), iv.cend(), std::bind(check_size, std::ref(s), std::placeholders::_1));
    std::cout << *itr << std::endl;
}

/**
 * 练习10.25：在10.3.2节（第349页）的练习中，编写了一个使用partition
 * 的biggies版本。使用check_size和bind重写此函数。
 */
void elimdups(std::vector<std::string> &vs) {
    std::sort(vs.begin(), vs.end());
    auto unique_end = std::unique(vs.begin(), vs.end());
    vs.erase(unique_end, vs.cend());
}

bool check_size_10_25(const std::string &s, std::string::size_type sz) {
    return s.size() >= sz;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    elimDups(words);
    auto iter = std::stable_partition(words.begin(), words.end(),
                                      std::bind(check_size_10_25, std::placeholders::_1, sz));
    std::for_each(words.begin(), iter, [](const std::string s) {
        std::cout << s << " ";
    });
}

void q_10_25() {
    std::vector<std::string> v{
            "the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"
    };
    biggies(v, 4);
}

/**
 * 练习10.27：除了unique（参见10.2.3节，第343页）之外，标准库还定义
 * 了名为unique_copy的函数，它接受第三个迭代器，表示拷贝不重复元素
 * 的目的位置。编写一个程序，使用unique_copy将一个vector中不重复的
 * 元素拷贝到一个初始为空的list中。
 */
void q_10_27() {
    std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> il;
    std::unique_copy(iv.cbegin(), iv.cend(), std::back_inserter(il));

    for (auto i: il) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/**
 * 练习10.28：一个vector中保存1到9，将其拷贝到三个其他容器中。分别
 * 使用inserter、back_inserter和front_inserter将元素添加到三个容器中。对
 * 每种inserter，估计输出序列是怎样的，运行程序验证你的估计是否正确。
 */
void q_10_28() {
    std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> il1;
    std::list<int> il2;
    std::list<int> il3;

    std::copy(iv.cbegin(), iv.cend(), std::inserter(il1, il1.begin()));
    std::copy(iv.cbegin(), iv.cend(), std::back_inserter(il2));
    std::copy(iv.cbegin(), iv.cend(), std::front_inserter(il3));

    std::cout << "insert list: ";
    for (auto i: il1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "back_inserter list: ";
    for (auto i: il2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "front_inserter list: ";
    for (auto i: il3) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/**
 * 10.4.2节练习
 * 练习10.29：编写程序，使用流迭代器读取一个文本文件，存入一个
 * vector中的string里。
 */
void q_10_29() {
    std::ifstream ifs("./data.txt");
    std::istream_iterator<std::string> is_itr(ifs);
    std::istream_iterator<std::string> eof;
    std::vector<std::string> sv;
    std::copy(is_itr, eof, std::back_inserter(sv));

    std::copy(sv.cbegin(), sv.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

/**
 * 练习10.30：使用流迭代器、sort和copy从标准输入读取一个整数序列，
 * 将其排序，并将结果写到标准输出。
 */
void q_10_30() {
    std::vector<int> iv;
    std::istream_iterator<int> is_itr(std::cin);
    std::copy(is_itr, std::istream_iterator<int>(), std::back_inserter(iv));
    std::sort(iv.begin(), iv.end());
    std::copy(iv.cbegin(), iv.cend(), std::ostream_iterator<int>(std::cout, " "));
}

/**
 * 练习10.31：修改前一题的程序，使其只打印不重复的元素。你的程序
 * 应使用unique_copy（参见10.4.1节，第359页）。
 */
void q_10_31() {
    std::vector<int> iv;
    std::istream_iterator<int> is_itr(std::cin);
    std::copy(is_itr, std::istream_iterator<int>(), std::back_inserter(iv));
    std::sort(iv.begin(), iv.end());
    std::unique_copy(iv.cbegin(), iv.cend(), std::ostream_iterator<int>(std::cout, " "));
}

/**
 * 练习10.32：重写1.6节（第21页）中的书店程序，使用一个vector保存交
 * 易记录，使用不同算法完成处理。使用sort和10.3.1节（第345页）中的
 * compareIsbn函数来排序交易记录，然后使用find和accumulate求和。
 */
inline bool compareIsbn_10_32(const Sales_item &lsd, const Sales_item &rsd) {
    return lsd.isbn().size() < rsd.isbn().size();
}

void q_10_32() {
    std::istream_iterator<Sales_item> in_iter(std::cin), in_eof;
    std::vector<Sales_item> vec;

    while (in_iter != in_eof) {
        vec.push_back(*in_iter++);
    }

    std::sort(vec.begin(), vec.end(), compareIsbn_10_32);

    for (auto beg = vec.begin(), end = vec.begin(); beg != vec.end(); beg = end) {
        end = std::find_if(beg, vec.end(), [&beg](const Sales_item &item) -> bool {
            return item.isbn() != beg->isbn();
        });
        std::cout << std::accumulate(beg, end, Sales_item(beg->isbn())) << std::endl;
    }
}

/**
 * 练习10.33：编写程序，接受三个参数：一个输入文件和两个输出文件
 * 的文件名。输入文件保存的应该是整数。使用istream_iterator读取输入
 * 文件。使用ostream_iterator将奇数写入第一个输出文件，每个值之后都
 * 跟一个空格。将偶数写入第二个输出文件，每个值都独占一行。
 */
void q_10_33(int argc, char **argv) {
//    if (argc != 4) return;
    std::string origin_file = "origin.txt";
    std::string even_file = "even.txt";
    std::string odd_file = "odd.txt";

    std::ifstream origin_ifs(origin_file);
    std::ofstream even_ofs(even_file), odd_ofs(odd_file);
    if (!origin_ifs || !even_ofs || !odd_ofs) {
        return;
    }

    std::istream_iterator<int> is_itr(origin_ifs), eof;
    std::ostream_iterator<int> even_os_itr(even_ofs, " "), odd_os_itr(odd_ofs, " ");

    std::for_each(is_itr, eof, [&odd_os_itr, &even_os_itr](int v) {
        if (v % 2 == 0) {
            *even_os_itr++ = v;
        } else {
            *odd_os_itr++ = v;
        }
    });
}

/**
 * 10.4.3节练习
 * 练习10.34：使用reverse_iterator逆序打印一个vector。
 */
void q_10_34() {
    std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::copy(iv.rbegin(), iv.rend(), std::ostream_iterator<int>(std::cout, " "));
}

/**
 * 练习10.35：使用普通迭代器逆序打印一个vector。
 */
void q_10_35() {
    std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto itr = iv.cend() - 1; itr != iv.begin() - 1; --itr) {
        std::cout << *itr << " ";
    }
}

/**
 * 练习10.36：使用find在一个int的list中查找最后一个值为0的元素。
 */
void q_10_36() {
    std::list<int> il = {0, 1, 2, 3, 0, 4, 5, 6, 0, 7, 8, 9};
    auto itr = std::find(il.crbegin(), il.crend(), 0);
    std::cout << std::distance(itr, il.crend()) << std::endl;
}

/**
 * 练习10.37：给定一个包含10个元素的vector，将位置3到7之间的元素按逆序拷贝
 * 到一个list中。
 */
void q_10_37() {
    std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> il;
    std::copy(iv.rend() - 7, iv.rend() - 2, std::back_inserter(il));
    std::copy(il.cbegin(), il.cend(), std::ostream_iterator<int>(std::cout, " "));
}

int main(int args, char **argv) {
//    q_10_1();
//    q_10_2();
//    q_10_3();
//    q_10_6();
//    q_10_9();
//    q_10_11();
//    q_10_12();
//    q_10_13();
//    q_10_14();
//    q_10_15();
//    q_10_16();
//    q_10_17();
//    q_10_18();
//    q_10_19();
//    q_10_20();
//    q_10_21();
//    q_10_22();
//    q_10_24();
//    q_10_25();
//    q_10_27();
//    q_10_28();
//    q_10_29();
//    q_10_30();
//    q_10_31();
//    q_10_32();
//    q_10_33(args, argv);
//    q_10_34();
//    q_10_35();
//    q_10_36();
    q_10_37();
    return 0;
}