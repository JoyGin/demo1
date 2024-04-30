//
// Created by 王泽鑫 on 2024/4/9.
//

#include <vector>
#include <iostream>
#include <memory>

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

int main() {
//    q_12_6();
//    q_12_7();
//    q_12_14();
    q_12_15();
}