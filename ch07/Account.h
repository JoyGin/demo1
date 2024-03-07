//
// Created by 王泽鑫 on 2024/3/6.
//

#ifndef DEMO1_ACCOUNT_H
#define DEMO1_ACCOUNT_H

#include <string>

class Account {
public:
    [[nodiscard]] double calculate() const {
        return amount * interestRate;
    }

    static double rate() {
        return interestRate;
    }

    static void rate(double r) {
        interestRate = r;
    }
private:
    std::string owner;
    double amount = 0;

    static double interestRate;
    static constexpr double todayRate = 42.42;
    static double initRate() {
        return todayRate;
    }
};


#endif //DEMO1_ACCOUNT_H
