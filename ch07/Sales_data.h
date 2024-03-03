//
// Created by 王泽鑫 on 2024/3/3.
//

#ifndef DEMO1_SALES_DATA_H
#define DEMO1_SALES_DATA_H

#include <string>
#include <iostream>

struct Sales_data;

std::istream &read(std::istream &is, Sales_data &data);

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

//    Sales_data() = default;

    explicit Sales_data(const std::string &s) : bookNo(s) {}

    Sales_data(const std::string &s, unsigned n, double price) : bookNo(s), units_sold(n), revenue(price * n) {}

//    explicit Sales_data(std::istream &is);
    /** 练习7.12：把只接受一个istream作为参数的构造函数定义移到类的内部。*/
    explicit Sales_data(std::istream &is) {
        read(std::cin, *this);
    }

    /**
     * 练习7.14：编写一个构造函数，令其用我们提供的类内初始值显式地初
     * 始化成员。
     */
    Sales_data() : bookNo(), units_sold(0), revenue(0) {}

    Sales_data &combine(const Sales_data &rhs);

    [[nodiscard]] std::string isbn() const {
        return bookNo;
    }
};

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

std::ostream &print(std::ostream &os, const Sales_data &data);

#endif //DEMO1_SALES_DATA_H
