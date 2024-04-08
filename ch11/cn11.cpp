//
// Created by 王泽鑫 on 2024/3/27.
//
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <netdb.h>
#include <vector>
#include "Sales_data.h"

/**
 * 练习11.3：编写你自己的单词计数程序。
*/
void q_11_3() {
    std::map<std::string, int> word_count;
    std::string word;
    while (std::cin >> word) {
        ++word_count[word];
    }
    for (const auto &elem: word_count) {
        std::cout << elem.first << " occur " << elem.second << (elem.second > 1 ? " times" : " time") << std::endl;
    }
}

/**
 * 练习11.4：扩展你的程序，忽略大小写和标点。例如，"example."、
 * "example，"和"Example"应该递增相同的计数器。
*/
void q_11_4() {
    std::ifstream ifs("tongue_twist.txt");
    std::map<std::string, int> word_count;
    std::string word;
    while (ifs >> word) {
        std::for_each(word.begin(), word.end(), [](char &c) {
            c = std::tolower(c);
        });

        auto end_itr = std::remove_if(word.begin(), word.end(), ispunct);
        word.erase(end_itr, word.cend());
        ++word_count[word];
    }

    std::for_each(word_count.cbegin(), word_count.cend(), [](const std::map<std::string, int>::value_type &elem) {
        std::cout << elem.first << " occur " << elem.second << (elem.second > 1 ? " times" : " time") << std::endl;
    });
}

/**
 * 练习11.7：定义一个map，关键字是家庭的姓，值是一个vector，保存家
 * 中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添
 * 加新的孩子。
 */
void q_11_7() {
    std::map<std::string, std::vector<std::string >> family;
    std::string last_name;
    std::cout << "Last name: \n";
    while (std::cin >> last_name && last_name != "@q") {
        std::string first_name;
        std::cout << "|-Children's names:\n";
        while (std::cin >> first_name && first_name != "@q") {
            family[last_name].push_back(first_name);
        }
    }

    for (const auto &elem: family) {
        std::cout << elem.first << ": ";
        for (const auto &first_name: elem.second) {
            std::cout << first_name << " ";
        }
        std::cout << std::endl;
    }

//    std::map<std::string, std::vector<std::string>> m;
//    for (std::string ln; std::cout << "Last name:\n", std::cin >> ln && ln != "@q";)
//        for (std::string cn; std::cout << "|-Children's names:\n", std::cin >> cn && cn != "@q";)
//            m[ln].push_back(cn);
//
//    for (const auto &elem: m) {
//        std::cout << elem.first << ": ";
//        for (const auto &first_name: elem.second) {
//            std::cout << first_name << " ";
//        }
//        std::cout << std::endl;
//    }
}

/**
 * 练习11.8：编写一个程序，在一个vector而不是一个set中保存不重复的
 * 单词。使用set的优点是什么？
 */
void q_11_8() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = 0;
    while (std::cin >> num) {
        auto itr = std::find(vec.cbegin(), vec.cend(), num);
        if (itr == vec.cend()) {
            vec.push_back(num);
        }
    }

    std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
}

/**
 * 11.2.2节练习
 * 练习11.9：定义一个map，将单词与一个行号的list关联，list中保存的是
 * 单词所出现的行号。
 */
void q_11_9() {
    std::map<std::string, std::list<size_t>> map;
}

/**
 * 练习11.11：不使用decltype重新定义bookstore。
 */
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

void q_11_11() {
    // 使用 decltype
//    std::multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);

    // 答案
//    using Less = bool (*)(Sales_data const&, Sales_data const&);
//    std::multiset<Sales_data, Less> bookstore(compareIsbn);

    std::multiset<Sales_data, bool (*)(const Sales_data &lhs, const Sales_data &rhs)> bookstore(compareIsbn);
}

/**
 * 11.2.3节练习
 * 练习11.12：编写程序，读入string和int的序列，将每个string和int存入一
 * 个pair中，pair保存在一个vector中。
 */
void q_11_12() {
    using std::vector, std::pair;
    using std::string;
    using std::cin;
    using std::cout;
    vector<pair<string, int>> vec;
    std::string str;
    int num;
    while (cin >> str >> num) {
        auto tmpPair = pair<string, int>(str, num);
        vec.push_back(tmpPair);
    }

    std::for_each(vec.cbegin(), vec.cend(), [](const pair<string, int> &p) {
        cout << p.first << " " << p.second << std::endl;
    });
}

/**
 * 练习11.13：在上一题的程序中，至少有三种创建pair的方法。编写此程
 * 序的三个版本，分别采用不同的方法创建pair。解释你认为哪种形式最
 * 易于编写和理解，为什么？
 */
void q_11_13() {
    using std::vector, std::pair;
    using std::string;
    using std::cin;
    using std::cout;
    vector<pair<string, int>> vec;
    std::string str;
    int num;
    while (cin >> str >> num) {
//        auto tmpPair = pair<string, int>(str, num); // 1
//        vec.push_back(tmpPair);
//        auto tmpPair = std::make_pair(str, num); // 2
//        vec.push_back(tmpPair);
        vec.emplace_back(str, num); // 3
    }

    std::for_each(vec.cbegin(), vec.cend(), [](const pair<string, int> &p) {
        cout << p.first << " " << p.second << std::endl;
    });
}

/**
 * 练习11.14：扩展你在11.2.1节练习（第378页）中编写的孩子姓到名的
 * map，添加一个pair的vector，保存孩子的名和生日。
 */
class Families {
public:
    using Child = std::pair<std::string, std::string>;
    using Children = std::vector<Child>;
    using Data = std::map<std::string, Children>;

    void add(const std::string &last, const std::string &first_name, const std::string &birthday) {
        auto child = std::make_pair(first_name, birthday);
        _data[last].push_back(child);
    }

    void print() {
        std::for_each(_data.cbegin(), _data.cend(), [](const Data::value_type &p) {
            std::cout << p.first << ":" << std::endl;
            for (const auto &child: p.second) {
                std::cout << child.first << " " << child.second << std::endl;
            }
        });
    }

private:
    Data _data;
};

void q_11_14() {
    Families families;
    auto msg = "Please enter last name, first name and birthday:\n";
    for (std::string last_name, first_name, birthday;
         std::cout << msg, std::cin >> last_name >> first_name >> birthday;) {
        families.add(last_name, first_name, birthday);
    }
    families.print();
}

/**
 * 练习11.19：定义一个变量，通过对11.2.2节（第378页）中的名为
 * bookstore的multiset调用begin（）来初始化这个变量。写出变量的类
 * 型，不要使用auto或decltype。
 */
void q_11_19() {
    using compareType = bool (*)(Sales_data &ls, Sales_data &rs);
    std::map<Sales_data, compareType> bookstore;
    std::map<Sales_data, compareType>::iterator it = bookstore.begin();
}

/**
 * 11.3.2节练习
 * 练习11.20：重写11.1节练习（第376页）的单词计数程序，使用insert代
 * 替下标操作。你认为哪个程序更容易编写和阅读？解释原因。
 */
void q_11_20() {
    std::map<std::string, int> word_count;
    std::string word;
    while (std::cin >> word) {
        auto ret = word_count.insert({word, 1});
        if (!ret.second) {
            ++ret.first->second;
        }
    }
    for (const auto &elem: word_count) {
        std::cout << elem.first << " occur " << elem.second << (elem.second > 1 ? " times" : " time") << std::endl;
    }
}

/**
 * 练习11.22：给定一个map<string，vector<int>>，对此容器的插入一个元
 * 素的insert版本，写出其参数类型和返回类型。
 */
void q_11_22() {
    using std::map, std::string, std::vector, std::pair;
    map<string, vector<int>> m;

    pair<string, vector<int>> item = std::make_pair("hello", vector<int>());
    pair<map<string, vector<int>>::iterator, bool> ret = m.insert(item);
}

/**
 * 练习11.23：11.2.1节练习（第378页）中的map以孩子的姓为关键字，保
 * 存他们的名的vector，用multimap重写此map。
 */
void q_11_23() {
    using std::string;
    using std::multimap;
    using std::cin;
    using std::cout;
    using std::endl;
    multimap<string, string> families;
    for (string lastname, firstname; cin >> firstname >> lastname;) {
        families.emplace(lastname, firstname);
    }
    for (auto &family: families) {
        cout << family.second << " " << family.first << endl;
    }
}

/**
 * 练习11.28：对一个string到int的vector的map，定义并初始化一个变量来
 * 保存在其上调用find所返回的结果。
 */
void q_11_28() {
    std::map<std::string, std::vector<int>> m;
    std::map<std::string, std::vector<int>>::iterator it = m.find("key");
}

/**
 * 练习11.31
 * 编写程序，定义一个作者及其作品的multimap。使用find在multimap中查找一个元素并用erase删除它。确保你的程序在元素不在map 中时也能正常运行。
 */
void q_11_31() {
    std::multimap<std::string, std::string> authors{
            {"alan", "DMA"},
            {"pezy", "LeetCode"},
            {"alan", "CLRS"},
            {"wang", "FTP"},
            {"pezy", "CP5"},
            {"wang", "CPP-Concurrency"}};

    std::string author = "pezy";
    std::string work = "CP5";

    auto count = authors.count(author);
    auto cur = authors.find(author);
    while (count) {
        if (cur->second == work) {
            authors.erase(cur);
            break;
        } else {
            --count;
            ++cur;
        }
    }

    for (auto item: authors) {
        std::cout << item.first << ": " << item.second << std::endl;
    }
}

/**
 * 练习11.32
 * 使用上一题定义的multimap编写一个程序，按字典序打印作者列表和他们的作品。
 */
void q_11_32() {
    std::multimap<std::string, std::string> authors{
            {"alan", "DMA"},
            {"pezy", "LeetCode"},
            {"alan", "CLRS"},
            {"wang", "FTP"},
            {"pezy", "CP5"},
            {"wang", "CPP-Concurrency"}};

    std::map<std::string, std::multiset<std::string>> order_authors;

    for (const auto &author: authors) {
        order_authors[author.first].insert(author.second);
    }

    for (const auto &author: order_authors) {
        std::cout << author.first << ": ";
        for (const auto &book: author.second) {
            std::cout << book << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
//    q_11_3();
//    q_11_4();
//    q_11_7();
//    q_11_8();
//    q_11_12();
//    q_11_13();
//    q_11_14();
//    q_11_20();
//    q_11_23();
//    q_11_31();
    q_11_32();
    return 0;
}