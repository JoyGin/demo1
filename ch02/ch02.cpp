//
// Created by 王泽鑫 on 2024/2/19.
//

#include <iostream>

void q_2_3() {
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
}

int main() {
    q_2_3();
    return 0;
}