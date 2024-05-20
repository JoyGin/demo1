//
// Created by 王泽鑫 on 2024/5/16.
//

#include "Foo.h"

#include <iostream>

Foo Foo::sorted() const &{
//    Foo ret(*this);
//    sort(ret.data.begin(), ret.data.end());
//    return ret;

    std::cout << "const &" << std::endl; // debug

//    Foo ret(*this);
//    ret.sorted();     // Exercise 13.56
//    return ret;

    return Foo(*this).sorted(); // Exercise 13.57
}

Foo Foo::sorted() &&{
    std::sort(data.begin(), data.end());
    return *this;
}
