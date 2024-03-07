//
// Created by 王泽鑫 on 2024/3/3.
//

#include "Sales_data.h"

//Sales_data::Sales_data(std::istream &is) {
//    read(is, *this);
//}

Sales_data &Sales_data::combine(Sales_data &rhs) {
    if (bookNo == rhs.bookNo) {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
    }
    return *this;
}

/**
 * 练习7.6：对于函数add、read和print，定义你自己的版本。
 */

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data result;
    if (lhs.bookNo != rhs.bookNo) {
        std::cerr << "bookNo is not same!" << std::endl;
    } else {
        result.revenue = lhs.revenue + rhs.revenue;
        result.units_sold = lhs.units_sold + rhs.units_sold;
    }
    return result;
}

std::istream &read(std::istream &is, Sales_data &data) {
    unsigned price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = data.units_sold * price;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &data) {
    os << "bookNo: " << data.bookNo << ", units_sold: " << data.units_sold << ", revenue: " << data.revenue;
    return os;
}