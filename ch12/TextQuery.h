//
// Created by 王泽鑫 on 2024/5/7.
//

#ifndef DEMO1_TEXTQUERY_H
#define DEMO1_TEXTQUERY_H

#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <map>
#include <set>

class QueryResult;

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;

    explicit TextQuery(std::ifstream &infile);

    QueryResult query(const std::string &word) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
public:
    friend std::ostream &print(std::ostream &os, const QueryResult &qr);

    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> l,
                std::shared_ptr<std::vector<std::string>> f);

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif //DEMO1_TEXTQUERY_H
