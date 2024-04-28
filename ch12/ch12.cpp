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

int main() {
//    q_12_6();
    q_12_7();
}