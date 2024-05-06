//
// Created by 王泽鑫 on 2024/4/9.
//

#ifndef DEMO1_STRBLOB_H
#define DEMO1_STRBLOB_H

#include <string>
#include <memory>
#include <vector>

class StrBlobPtr;

class StrBlob {
public:
    using size_type = std::vector<std::string>::size_type;

    friend class StrBlobPtr;

    StrBlobPtr begin() const;

    StrBlobPtr end() const;

    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

    [[nodiscard]] inline size_type size() const {
        return data->size();
    }

    [[nodiscard]] inline bool empty() const {
        return data->empty();
    }

    void push_back(const std::string &str) const;

    void pop_back();

    std::string &front();

    std::string &back();

    [[nodiscard]] const std::string &front() const;

    [[nodiscard]] const std::string &back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;

    void check(size_t index, const std::string &msg) const {
        if (index >= data->size()) {
            throw std::out_of_range(msg);
        }
    }
};

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);

    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

private:
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;

    std::shared_ptr<std::vector<std::string>> check(size_t i, const std::string &msg) const {
        auto ret = wptr.lock();
        if (!ret) {
            throw std::runtime_error("unbound StrBlobPtr");
        }
        if (i >= ret->size()) {
            throw std::out_of_range(msg);
        }
        return ret;
    }

public:
    StrBlobPtr() : curr(0) {}

    explicit StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}

//    bool operator!=(const StrBlobPtr &p) const {
//        return p.curr != curr;
//    }

    [[nodiscard]] std::string &deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    StrBlobPtr &incr() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
};

#endif //DEMO1_STRBLOB_H
