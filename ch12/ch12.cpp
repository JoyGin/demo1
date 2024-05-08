//
// Created by 王泽鑫 on 2024/4/9.
//

#include <vector>
#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include "StrBlob.h"
#include "TextQuery.h"

/**
 * 12.1.2节练习
 * 练习12.6：编写函数，返回一个动态分配的int的vector。将此vector传递
 * 给另一个函数，这个函数读取标准输入，将读入的值保存在vector元素
 * 中。再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻
 * delete vector。
*/
std::vector<int> *get_int_vector() {
    std::vector<int> *vec = new std::vector<int>;
    return vec;
}

void fillIntVector(std::vector<int> &vec) {
    int v = 0;
    while (std::cin >> v) {
        vec.push_back(v);
    }
}

void printVector(const std::vector<int> &vec) {
    std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
}

void q_12_6() {
    std::vector<int> *vec = get_int_vector();
    fillIntVector(*vec);
    printVector(*vec);
    delete vec;
}

/**
 * 练习12.7：重做上一题，这次使用shared_ptr而不是内置指针。
*/
std::shared_ptr<std::vector<int>> alloc_vector() {
    return std::make_shared<std::vector<int>>();
}

void assign_vector(std::vector<int> &vec) {
    int v = 0;
    while (std::cin >> v) {
        vec.push_back(v);
    }
}

void print_vector(const std::vector<int> &vec) {
    std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<int>(std::cout, " "));
}

void q_12_7() {
    auto vec = alloc_vector();
    assign_vector(*vec);
    print_vector(*vec);
}

/**
 * 12.1.4节练习
 * 练习12.14：编写你自己版本的用shared_ptr管理connection的函数。
 */
struct connection {
    std::string ip;
    int port;

    connection(std::string i, int p) : ip(i), port(p) {
        std::cout << "constructor" << std::endl;
    }

    connection(connection &conn) : connection(conn.ip, conn.port) {
        std::cout << "constructor dup" << std::endl;
    }
};

struct destination {
    std::string ip;
    int port;

    destination(std::string i, int p) : ip(i), port(p) {}
};

connection connect(destination &pDest) {
    std::shared_ptr<connection> pConn(new connection(pDest.ip, pDest.port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

void disconnect(connection &voi) {
    std::cout << "connection close(" << voi.ip << ":" << voi.port << ")" << std::endl;
}

void end_connection(connection *pConn) {
    disconnect(*pConn);
}

void f(destination &d) {
    connection conn = connect(d);
    std::shared_ptr<connection> pConn(&conn, end_connection);
    std::cout << "connecting now(" << pConn.use_count() << ")" << std::endl;
}

void q_12_14() {
    destination dest("127.0.0.1", 8888);
    f(dest);
}

/**
 * 练习12.15：重写第一题的程序，用lambd（a参见10.3.2节，第346页）
 * 代替end_connection函数。
 */
void f2(destination &d) {
    connection conn = connect(d);
    std::shared_ptr<connection> pConn(&conn, [](connection *pConn) {
        disconnect(*pConn);
    });
    std::cout << "connecting now(" << pConn.use_count() << ")" << std::endl;
}

void q_12_15() {
    destination dest("127.0.0.1", 8888);
    f2(dest);
}

/**
 * 练习12.15：重写第一题的程序，用lambd（a参见10.3.2节，第346页）
 * 代替end_connection函数。
 */
void f3(destination &d) {
    connection conn = connect(d);
    std::unique_ptr<connection, decltype(end_connection) *> pConn(&conn, end_connection);
}

void test_uniqueptr() {
    destination dest("127.0.0.1", 8888);
    f3(dest);
}

void test_share_ptr_when_null() {
    std::shared_ptr<int> sp1;
//    std::shared_ptr<int> sp1(new int(1));
    if (sp1) {
        std::cout << "sp1 is not null" << std::endl;
    } else {
        std::cout << "sp1 is null" << std::endl;
    }
}

void test_share_ptr_equal() {
    std::shared_ptr<int> sp1(new int(1));
    const std::shared_ptr<int> &sp2(sp1);
    if (sp1 == sp2) {
        std::cout << "sp1 equal to sp2" << std::endl;
    } else {
        std::cout << "sp1 doesn't equal to sp2" << std::endl;
    }
}

/**
 * 练习12.20：编写程序，逐行读入一个输入文件，将内容存入一个
 * StrBlob中，用一个StrBlobPtr打印出StrBlob中的每个元素。
 */
void q_12_20() {
    StrBlob strBlob = StrBlob();
    std::ifstream ifs("data.txt");
    std::string line;
    while (getline(ifs, line)) {
        strBlob.push_back(line);
    }
    for (StrBlobPtr begin = strBlob.begin(); begin != strBlob.end(); begin.incr()) {
        std::cout << begin.deref() << std::endl;
    }
}

/**
 * 练习12.22：为了能让StrBlobPtr使用const StrBlob，你觉得应该如何修
 * 改？定义一个名为ConstStrBlobPtr的类，使其能够指向const StrBlob。
 */
void q_12_22() {
    const StrBlob strBlob = StrBlob();
    std::ifstream ifs("data.txt");
    std::string line;
    while (getline(ifs, line)) {
        strBlob.push_back(line);
    }
    for (StrBlobPtr begin = strBlob.begin(); begin != strBlob.end(); begin.incr()) {
        std::cout << begin.deref() << std::endl;
    }
}

class ClassA {
    friend bool operator==(const ClassA &l, const ClassA &r);

public:
    explicit ClassA(int v) : val(v) {}

//    bool operator==(const ClassA &a) const {
//        std::cout << "member function" << std::endl;
//        return val == a.val;
//    }

private:
    int val;
};

bool operator==(const ClassA &l, const ClassA &r) {
    std::cout << "friend function" << std::endl;
    return l.val == r.val;
}

void testFriendAndMemberFunc() {
    ClassA a(1);
    const ClassA b(1);
    if (a == b) {

    } else {

    }
}

/**
 * 练习12.23：编写一个程序，连接两个字符串字面常量，将结果保存在
 * 一个动态分配的char数组中。重写这个程序，连接两个标准库string对
 * 象。
 */
void q_12_23() {
    char *c1 = "Hello ";
    char *c2 = "World";
    size_t clen = strlen(c1) + strlen(c2) + 1;
    char *cr = new char[clen];
    strcat(cr, c1);
    strcat(cr, c2);
    std::cout << cr << std::endl;

    std::string s1 = "Hello ";
    std::string s2 = "World";
    strcpy(cr, (s1 + s2).c_str());
    std::cout << cr << std::endl;

    delete[] cr;
}

/**
 * 练习12.24：编写一个程序，从标准输入读取一个字符串，存入一个动
 * 态分配的字符数组中。描述你的程序如何处理变长输入。测试你的程
 * 序，输入一个超出你分配的数组长度的字符串。
 */
void q_12_24() {
    std::cout << "How long do you want the string? ";
    int size{0};
    std::cin >> size;
    char *input = new char[size + 1]();
    std::cin.ignore();
    std::cout << "input the string: ";
    std::cin.get(input, size + 1);
    std::cout << input;
    delete[] input;
}

class NoDefaultConClass {
public:
    explicit NoDefaultConClass(int v) : val(v) {}

private:
    int val;
};

void testNewNoDefault() {
//    NoDefaultConClass *pa = new NoDefaultConClass[5]();
}

/**
 * 12.2.2节练习
 * 练习12.26：用allocator重写第427页中的程序。
 */
void q_12_26() {
    int n = 5;
    std::allocator<std::string> alloc;
    std::string *p = alloc.allocate(n);
    std::string string;
    std::string *q = p;
    while (q != p + n && std::cin >> string) {
        alloc.construct(q++, "hello");
    }

    q = p;
    while (q != p + n) {
        std::cout << *q++ << std::endl;
    }

    q = p;
    while (q != p + n) {
        alloc.destroy(q++);
    }

    alloc.deallocate(p, n);
}

/**
 * 12.3.1节练习
 * 练习12.27：TextQuery和QueryResult类只使用了我们已经介绍过的语言
 * 和标准库特性。不要提前看后续章节内容，只用已经学到的知识对这两
 * 个类编写你自己的版本。
 */
void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        print(std::cout, tq.query(s));
    }
}

void q_12_27() {
    std::ifstream ifs("data.txt");
    runQueries(ifs);
}

/**
 * 练习12.28：编写程序实现文本查询，不要定义类来管理数据。你的程
 * 序应该接受一个文件，并与用户交互来查询单词。使用vector、map和
 * set容器来保存来自文件的数据并生成查询结果。
 */
void q_12_28() {
    std::ifstream ifs("data.txt");
    std::vector<std::string> file;
    std::string line;
    std::map<std::string, std::set<decltype(file.size())>> wm;
    while (getline(ifs, line)) {
        file.push_back(line);
        decltype(file.size()) n = file.size() - 1;
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            wm[word].insert(n);
        }
    }
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        auto found = wm.find(s);
        if (found == wm.end()) {
            std::cout << s << " occurs 0 time" << std::endl;
        } else {
            std::cout << s << " occurs " << found->second.size() << (found->second.size() > 1 ? " times" : " time")
                      << std::endl;
            for (auto &i: found->second) {
                std::cout << "\t(line " << i + 1 << " )" << file[i] << std::endl;
            }
        }
    }
}

int main() {
//    q_12_6();
//    q_12_7();
//    q_12_14();
//    q_12_15();
//    test_uniqueptr();
//    test_share_ptr_when_null();
//    test_share_ptr_equal();
//    q_12_20();
//    q_12_22();
//    testFriendAndMemberFunc();
//    q_12_23();
//    q_12_24();
//    q_12_26();
//    q_12_27();
    q_12_28();
}