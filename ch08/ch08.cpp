//
// Created by 王泽鑫 on 2024/3/7.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "../ch07/Sales_data.h"

/**
 * 练习8.1：编写函数，接受一个istream&参数，返回值类型也是
 * istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停
 * 止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之
 * 前，对流进行复位，使其处于有效状态。
*/
std::istream &func(std::istream &is) {
    std::string buf;
    while (is >> buf) {
        std::cout << buf << std::endl;
    }
    is.clear();
    return is;
}

/**
 * 练习8.2：测试函数，调用参数为cin。
*/
void q_8_2() {
    func(std::cin);
    std::cout << std::cin.rdstate() << std::endl;
}

/**
 * 练习8.4：编写函数，以读模式打开一个文件，将其内容读入到一个
 * string的vector中，将每一行作为一个独立的元素存于vector中。
 */
void q_8_4() {
    std::ifstream fs("data.txt");

    std::vector<std::string> strings;
    std::string line;
    while (getline(fs, line)) {
        strings.push_back(line);
    }

    for (const std::string &s: strings) {
        std::cout << s << std::endl;
    }
}

/**
 * 练习8.5：重写上面的程序，将每个单词作为一个独立的元素进行存储。
 */
void q_8_5() {
    std::ifstream fs("data.txt");
    std::vector<std::string> words;
    std::string word;
    while (fs >> word) {
        words.push_back(word);
    }

    for (const std::string &w: words) {
        std::cout << w << std::endl;
    }
}

/**
 * 练习8.6：重写7.1.1节的书店程序（第229页），从一个文件中读取交易
 * 记录。将文件名作为一个参数传递给main（参见6.2.5节，第196页）。
 */
void q_8_6(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "please enter right filename!" << std::endl;
        return;
    }
    char *filename = argv[1];
    std::ifstream fs(filename);

    Sales_data total;
    if (read(fs, total)) {
        Sales_data trans;
        while (read(fs, trans)) {
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
 * 练习8.7：修改上一节的书店程序，将结果保存到一个文件中。将输出
 * 文件名作为第二个参数传递给main函数。
 */
void q_8_7(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "please enter right file!" << std::endl;
        return;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];
    std::ifstream ifs(inputFile);
    std::ofstream ofs(outputFile);

    Sales_data total;
    if (read(ifs, total)) {
        Sales_data trans;
        while (read(ifs, trans)) {
            if (total.isbn() == trans.isbn()) {
                total = add(total, trans);
            } else {
                print(ofs, total) << std::endl;
                total = trans;
            }
        }
        print(ofs, total) << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
    }
}

/**
 * 练习8.8：修改上一题的程序，将结果追加到给定的文件末尾。对同一
 * 个输出文件，运行程序至少两次，检验数据是否得以保留。
 */
void q_8_8(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "please enter right file!" << std::endl;
        return;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];
    std::ifstream ifs(inputFile);
    std::ofstream ofs(outputFile, std::ofstream::app);

    Sales_data total;
    if (read(ifs, total)) {
        Sales_data trans;
        while (read(ifs, trans)) {
            if (total.isbn() == trans.isbn()) {
                total = add(total, trans);
            } else {
                print(ofs, total) << std::endl;
                total = trans;
            }
        }
        print(ofs, total) << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
    }
}

/**
 * 练习8.9：使用你为8.1.2节（第281页）第一个练习所编写的函数打印一
 * 个istringstream对象的内容。
 */
void q_8_9() {
    std::istringstream iss("hello world");
    func(iss);
}

/**
 * 练习8.10：编写程序，将来自一个文件中的行保存在一个vector<string>
 * 中。然后使用一个istringstream从vector读取数据元素，每次读取一个单
 * 词。
 */
void q_8_10() {
    std::fstream fs("data.txt");
    std::vector<std::string> strs;
    std::string line;
    while (getline(fs, line)) {
        strs.push_back(line);
    }

    std::istringstream iss;
    for (const std::string &str: strs) {
        iss.str(str);
        std::string word;
        while (iss >> word) {
            std::cout << word << std::endl;
        }
        iss.clear();
    }
}

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

/**
 * 练习8.11：本节的程序在外层while循环中定义了istringstream对象。如
 * 果record对象定义在循环之外，你需要对程序进行怎样的修改？重写程
 * 序，将record的定义移到while循环之外，验证你设想的修改方法是否正
 * 确。
 */
void q_8_11() {
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    while (getline(std::cin, line)) {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
        record.clear();
    }
}

/**
 * 练习8.13：重写本节的电话号码程序，从一个命名文件而非cin读取数
 * 据。
 */
void q_8_13() {
    std::ifstream ifs("people.txt");
    std::string line, word;
    std::vector<PersonInfo> people;

    std::istringstream iss;
    while (getline(ifs, line)) {
        iss.str(line);
        PersonInfo info;
        if (iss >> info.name) {
            while (iss >> word) {
                info.phones.push_back(word);
            }
            people.push_back(info);
        }
        iss.clear();
    }

    for (const PersonInfo &info: people) {
        std::cout << info.name << " ";
//        for (auto index = info.phones.begin(); index != info.phones.end(); ++index) {
//            std::cout << *index;
//            if (index == info.phones.end() - 1) {
//                std::cout << std::endl;
//            } else {
//                std::cout << " ";
//            }
//        }

        for (decltype(info.phones.size()) index = 0; index != info.phones.size(); ++index) {
            std::cout << info.phones[index];
            if (index < info.phones.size() - 1) {
                std::cout << " ";
            } else {
                std::cout << std::endl;
            }
        }
    }
}

int main(int argc, char **argv) {
//    q_8_2();
//    q_8_4();
//    q_8_5();
//    q_8_6(argc, argv);
//    q_8_7(argc, argv);
//    q_8_8(argc, argv);
//    q_8_9();
//    q_8_10();
//    q_8_11();
    q_8_13();
    return 0;
}