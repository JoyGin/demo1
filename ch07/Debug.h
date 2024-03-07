//
// Created by 王泽鑫 on 2024/3/6.
//

#ifndef DEMO1_DEBUG_H
#define DEMO1_DEBUG_H

#include <iostream>

class Debug {
public:
    explicit constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}

    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

    void set_hw(bool b) {
        hw = b;
    }

    void set_io(bool b) {
        io = b;
    }

    void set_other(bool b) {
        other = b;
    }

    std::ostream &print(std::ostream &os) const {
        os << "hw=" << hw << ", io=" << io << ", other=" << other;
        return os;
    }

private:
    bool hw;
    bool io;
    bool other;
};

#endif //DEMO1_DEBUG_H
