//
// Created by 王泽鑫 on 2024/5/16.
//

#ifndef DEMO1_FOO_H
#define DEMO1_FOO_H

#include <vector>

class Foo {
public:
    Foo sorted() const &;
    Foo sorted() &&;
private:
    std::vector<int> data;
};


#endif //DEMO1_FOO_H
