//
// Created by 王泽鑫 on 2024/2/6.
//
#include <iostream>
#include "Sales_item.h"

void inputOne() {
    Sales_item item;
    std::cin >> item;
    std::cout << item;
}

void inputMore() {
    Sales_item total;
    if (std::cin >> total) {
        Sales_item item;
        while (std::cin >> item) {
            if (total.isbn() == item.isbn()) {
                total += item;
            } else {
                break;
            }
        }
    }
    std::cout << total << std::endl;
}

void inputTwo() {
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    if (item1.isbn() == item2.isbn()) {
        std::cout << item1 + item2 << std::endl;
    } else {
        std::cerr << "Data must refer to same ISBN" << std::endl;
    }
}

int main() {
    inputOne();
//    inputTwo();
//    inputMore();
    return 0;
}