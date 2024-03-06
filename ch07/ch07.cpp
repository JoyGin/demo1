//
// Created by 王泽鑫 on 2024/3/3.
//

#include <string>
#include <iostream>
#include "Sales_data.h"
#include "Screen.h"

/**
* 练习7.1：使用2.6.1节练习定义的Sales_data类为1.6节（第21页）的交易
 * 处理程序编写一个新版本。
*/

void q_7_1() {
    Sales_data total;
    if (std::cin >> total.isbn() >> total.getUnitsSold() >> total.getRevenue()) {
        Sales_data trans;
        while (std::cin >> trans.isbn() >> trans.getUnitsSold() >> trans.getRevenue()) {
            if (total.isbn() == trans.isbn()) {
                total.getUnitsSold() += trans.getUnitsSold();
                total.getRevenue() += trans.getRevenue();
            } else {
                std::cout << total.isbn() << " " << total.getUnitsSold() << " " << total.getRevenue() << std::endl;
                total = trans;
            }
        }
    } else {
        std::cerr << "No data?!" << std::endl;
    }
}

/**
 * 练习7.2：曾在2.6.2节的练习（第67页）中编写了一个Sales_data类，请
 * 向这个类添加combine和isbn成员。
 */

/**
 * 练习7.3：修改7.1.1节（第229页）的交易处理程序，令其使用这些成员。
 */
void q_7_3() {
    Sales_data total;
    if (std::cin >> total.isbn() >> total.getUnitsSold() >> total.getRevenue()) {
        Sales_data trans;
        while (std::cin >> trans.isbn() >> trans.getUnitsSold() >> trans.getRevenue()) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                std::cout << total.isbn() << " " << total.getUnitsSold() << " " << total.getRevenue() << std::endl;
                total = trans;
            }
        }
        std::cout << total.isbn() << " " << total.getUnitsSold() << " " << total.getRevenue() << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
    }
}

/**
 * 练习7.4：编写一个名为Person的类，使其表示人员的姓名和住址。使用
 * string对象存放这些元素，接下来的练习将不断充实这个类的其他特
 * 征。
 */

/**
 * 练习7.5：在你的Person类中提供一些操作使其能够返回姓名和住址。这
 * 些函数是否应该是const的呢？解释原因。
 */

/**
 * 练习7.7：使用这些新函数重写7.1.2节（第233页）练习中的交易处理程序。
 */
void q_7_7() {
    Sales_data total;
    if (read(std::cin, total)) {
        Sales_data trans;
        while (read(std::cin, trans)) {
            if (total.isbn() == trans.isbn()) {
                total = add(total, trans);
            } else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
    }
}

/**
 * 练习7.11：在你的Sales_data类中添加构造函数，然后编写一段程序令其
 * 用到每个构造函数。
 */
void q_7_11() {
    Sales_data data1;
    print(std::cout, data1) << std::endl;

    Sales_data data2("0-201-78345-X");
    print(std::cout, data2) << std::endl;

    Sales_data data3("0-201-78345-X", 3, 20);
    print(std::cout, data3) << std::endl;

    Sales_data data4(std::cin);
    print(std::cout, data4) << std::endl;
}

/**
 * 练习7.13：使用istream构造函数重写第229页的程序。
 */
void q_7_13() {
    Sales_data total(std::cin);
    if (!total.isbn().empty()) {
        while (std::cin) {
            Sales_data trans(std::cin);
            if (std::cin) {
                if (total.isbn() == trans.isbn()) {
                    total.combine(trans);
                } else {
                    print(std::cout, total) << std::endl;
                    total = trans;
                }
            } else {
                break;
            }
        }
        print(std::cout, total) << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
    }
}

/**
 * 练习7.27
 * 给你自己的`Screen`类添加`move`、`set` 和`display`函数，通过执行下面的代码检验你的类是否正确。
 */
void q_7_27() {
    using std::cout;
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
}

/**
 * 练习7.31：定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含
 * 一个类型为X的对象。
 */
class Y;

class X {
    Y *pY = nullptr;
};

class Y {
    X x;
};

class NoDefault {
public:
    explicit NoDefault(int i) : val(i) {};
private:
    int val = 0;
};

class C {
public:
    C() : val(0) {};
private:
    NoDefault val;
};

int main() {
//    q_7_1();
//    q_7_3();
//    q_7_7();
//    q_7_11();
//    q_7_13();
    q_7_27();
    return 0;
}