//
// Created by 王泽鑫 on 2024/5/7.
//

#include "TextQuery.h"
#include <memory>
#include <sstream>

TextQuery::TextQuery(std::ifstream &infile) : file(new std::vector<std::string>) {
    std::string line;
    while (getline(infile, line)) {
        file->push_back(line);
        int n = file->size() - 1;
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            if (!wm[word]) {
                wm[word] = std::make_shared<std::set<line_no>>();
            }
            (*wm[word]).insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &word) const {
    static auto nodata = std::make_shared<std::set<line_no>>();
    auto loc = wm.find(word);
    if (loc == wm.end()) {
        return QueryResult(word, nodata, file);
    } else {
        return QueryResult(word, loc->second, file);
    }
}

QueryResult::QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> l,
                         std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(l), file(f) {}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.sought << "occur " << qr.lines->size() << " time" << (!qr.lines->empty() ? "s" : "") << std::endl;
    for (auto &num: *qr.lines) {
        os << "\t(line " << num + 1 << " )" << *(qr.file->begin() + num) << std::endl;
    }
    return os;
}