//
// Created by 王泽鑫 on 2024/5/11.
//

#ifndef DEMO1_MESSAGE_H
#define DEMO1_MESSAGE_H

#include <string>
#include <set>

/**
 * 练习13.34：编写本节所描述的Message。
 */

/**
 * 练习13.36：设计并实现对应的Folder类。此类应该保存一个指向Folder
 * 中包含的Message的set。
 */

class Folder;

class Message {
public:
    friend void swap(Message &lhs, Message &rhs);

    explicit Message(const std::string &str = "") : contents(str) {}

    Message(const Message &msg);

    Message &operator=(const Message &msg);

    ~Message();

    void save(Folder &folder);

    void remove(Folder &folder);

    void addFolder(Folder &folder);

    void remFolder(Folder &folder);

private:
    std::string contents; // 实际消息文本
    std::set<Folder *> folders;

    void add_to_Folders(const Message &msg);

    void remove_from_Folders();
};

class Folder {
public:
    void addMsg(Message *msg);

    void remMsg(Message *msg);
private:
    std::set<Message*> msgs;
};

#endif //DEMO1_MESSAGE_H
