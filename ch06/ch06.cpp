//
// Created by 王泽鑫 on 2024/2/26.
//
#include <iostream>

/**
 * 练习6.10：编写一个函数，使用指针形参交换两个整数的值。在代码中
 * 调用该函数并输出交换后的结果，以此验证函数的正确性。
 * @param p
 * @param q
 */
void swap(int *p, int *q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void q_6_10() {
    int a = 1, b = 2;
    std::cout << "a=" << a << ", b=" << b << std::endl;
    swap(&a, &b);
    std::cout << "a=" << a << ", b=" << b << std::endl;
}

/**
 * 练习6.12：改写6.2.1节中练习6.10（第188页）的程序，使用引用而非指
 * 针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？
 * @param p
 * @param q
 */
void swap(int &p, int &q) {
    int tmp = p;
    p = q;
    q = tmp;
}

void q_6_12() {
    int a = 1, b = 2;
    std::cout << "a=" << a << ", b=" << b << std::endl;
    swap(a, b);
    std::cout << "a=" << a << ", b=" << b << std::endl;
}

/**
 * 练习6.17：编写一个函数，判断string对象中是否含有大写字母。编写另
 * 一个函数，把string对象全都改成小写形式。在这两个函数中你使用的
 * 形参类型相同吗？为什么？
 * @return
 */

void toLowerCase(std::string &str) {
    for (auto &c: str) {
        c = tolower(c);
    }
}

bool containBig(const std::string &str) {
    for (auto c: str) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

void q_6_17() {
    std::string str1 = "Hello World!";
    std::cout << containBig(str1) << std::endl;

    toLowerCase(str1);
    std::cout << str1 << std::endl;

    std::cout << containBig(str1) << std::endl;
}

int sum(std::initializer_list<int> const &il) {
    int sum = 0;
    for (auto i: il) sum += i;
    return sum;
}

/**
 * 练习6.33：编写一个递归函数，输出vector对象的内容。
 */
void printVector(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin != end) {
        std::cout << *begin << std::endl;
        printVector(++begin, end);
    }
}

void q_6_33() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printVector(vec.begin(), vec.end());
}

/**
 * 练习6.54：编写函数的声明，令其接受两个int形参并且返回类型也是
int；然后声明一个vector对象，令其元素是指向该函数的指针。
 */
int function(int a, int b);

void q_6_54() {
    std::vector<decltype(function) *> vec;
}

/**
 * 练习6.55：编写4个函数，分别对两个int值执行加、减、乘、除运算；
 * 在上一题创建的vector对象中保存指向这些函数的指针。
 */
int sum(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

void q_6_55() {
    std::vector<decltype(function) *> vec = {sum, minus, multiply, divide};
}

/**
 * 练习6.56：调用上述vector对象中的每个元素并输出其结果。
 */
void q_6_56() {
    std::vector<decltype(function) *> vec = {sum, minus, multiply, divide};
    int a = 6, b = 3;
    for (auto func: vec) {
        std::cout << func(a, b) << std::endl;
    }
}

int main() {
//    q_6_10();
//    q_6_12();
//    q_6_17();
//    q_6_33();
    q_6_56();
    return 0;
}