//
// Created by 王泽鑫 on 2024/5/11.
//

#include "Message.h"

Message::Message(const Message &msg) : contents(msg.contents), folders(msg.folders) {
    add_to_Folders(*this);
}

Message &Message::operator=(const Message &msg) {
    if (this != &msg) {
        remove_from_Folders();
        contents = msg.contents;
        folders = msg.folders;
        add_to_Folders(*this);
    }
    return *this;
}

Message::~Message() {
    remove_from_Folders();
}

void Message::save(Folder &folder) {
    folders.insert(&folder);
    folder.addMsg(this);
}

void Message::remove(Folder &folder) {
    folders.erase(&folder);
    folder.remMsg(this);
}

void Message::add_to_Folders(const Message &msg) {
    for (Folder *folder: msg.folders) {
        folder->addMsg(this);
    }
}

void Message::remove_from_Folders() {
    for (Folder *folder: folders) {
        folder->remMsg(this);
    }
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (Folder *folder: lhs.folders) {
        folder->remMsg(&lhs);
    }
    for (Folder *folder: rhs.folders) {
        folder->remMsg(&rhs);
    }

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    for (Folder *folder: lhs.folders) {
        folder->addMsg(&lhs);
    }
    for (Folder *folder: rhs.folders) {
        folder->addMsg(&rhs);
    }
}

void Message::addFolder(Folder &folder) {
    folders.insert(&folder);
}

void Message::remFolder(Folder &folder) {
    folders.erase(&folder);
}

void Folder::addMsg(Message *msg) {
    msgs.insert(msg);
}

void Folder::remMsg(Message *msg) {
    msgs.erase(msg);
}