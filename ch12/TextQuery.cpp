//
// Created by 王泽鑫 on 2024/5/8.
//

#include "TextQuery.h"
#include <sstream>

TextQuery::TextQuery(std::ifstream &infile) : file(std::make_shared<std::vector<std::string>>()) {
    line_no n = 0;
    for (std::string line; getline(infile, line); ++n) {
        file->push_back(line);
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            if (!wm[word]) {
                wm[word] = std::make_shared<std::set<line_no>>();
            }
            wm[word]->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &word) const {
    static std::shared_ptr<std::set<line_no>> nodata = std::make_shared<std::set<line_no>>();
    auto found = wm.find(word);
    if (found == wm.end()) {
        return QueryResult(word, nodata, file);
    } else {
        return QueryResult(word, found->second, file);
    }
}

QueryResult::QueryResult(const std::string &s, std::shared_ptr<std::set<TextQuery::line_no>> l,
                         std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(l), file(f) {}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.sought << "occurs " << qr.lines->size() << " time" << (qr.lines->size() > 1 ? "s" : "") << std::endl;
    for (auto &n : *qr.lines) {
        os << "\t(n " << n + 1 << " )" << (*(qr.file))[n] << std::endl;
    }
    return os;
}
