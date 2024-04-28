//
// Created by 王泽鑫 on 2024/4/22.
//
#include <iostream>

int main() {
    std::cout << "main" << std::endl;
    return 0;
}

__attribute__((constructor())) void initFunc() {
    std::cout << __FUNCTION__ << std::endl;
}