//
// Created by 王泽鑫 on 2024/2/25.
//
#include <vector>
#include <iostream>

/**
 * 练习4.21：编写一段程序，使用条件运算符从vector<int>中找到哪些元
 * 素的值是奇数，然后将这些奇数值翻倍。
 */
void q_4_21() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i: vec) {
        std::cout << ((i % 2 == 1) ? i * 2 : i) << std::endl;
    }
}

/**
 * 练习4.22：本节的示例程序将成绩划分成high pass、pass和fail三种，扩
 * 展该程序使其进一步将60分到75分之间的成绩设定为low pass。要求程
 * 序包含两个版本：一个版本只使用条件运算符；另外一个版本使用1个
 * 或多个if语句。哪个版本的程序更容易理解呢？为什么？
 */
void q_4_22() {
    // 关系表达式
    unsigned grade = 74;

    std::string result = grade > 90 ? "high pass" : (grade < 60) ? "fail" : (grade < 75) ? "low pass" : "pass";
    std::cout << result << std::endl;

    // if else
    if (grade > 90) {
        std::cout << "high pass" << std::endl;
    } else if (grade < 60) {
        std::cout << "fail" << std::endl;
    } else if (grade < 75) {
        std::cout << "low pass" << std::endl;
    }
}

int main() {
//    q_4_21();
//    q_4_22();
    return 0;
}