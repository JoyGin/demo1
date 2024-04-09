//
// Created by 王泽鑫 on 2024/4/9.
//

#ifndef DEMO1_STRBLOB_H
#define DEMO1_STRBLOB_H

#include <string>
#include <memory>
#include <vector>

class StrBlob {
public:
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

    void push_back(const std::string &str);

    void pop_back();

    std::string &front();

    std::string &back();

    const std::string &front() const;
    const std::string &back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_t index, const std::string &msg) const {
        if (index >= data->size()) {
            throw std::out_of_range(msg);
        }
    }
};


#endif //DEMO1_STRBLOB_H
