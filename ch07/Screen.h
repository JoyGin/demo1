//
// Created by 王泽鑫 on 2024/3/4.
//

#ifndef DEMO1_SCREEN_H
#define DEMO1_SCREEN_H

#include <string>

class Screen;

class Window_mgr {
public:
    typedef std::vector<Screen>::size_type ScreenIndex;

    Window_mgr() = default;

    Window_mgr &clear(ScreenIndex pos);

private:
    std::vector<Screen> screens; // 初始化为默认值
};

class Screen {
    friend Window_mgr &Window_mgr::clear(ScreenIndex);

public:
    typedef std::string::size_type pos;

    Screen() = default;

    Screen(pos ht, pos wd) : cursor(0), height(ht), width(wd), contents(ht * wd, ' ') {}

    Screen(pos ht, pos wd, char c) : cursor(0), height(ht), width(wd), contents(ht * wd, c) {}

    [[nodiscard]] char get() const {
        return contents.at(cursor);
    }

    [[nodiscard]] char get(pos r, pos c) const {
        return contents.at(r * width + c);
    }

    Screen &move(pos r, pos c) {
        cursor = r * width + c;
        return *this;
    }

    Screen &set(char c) {
        contents[cursor] = c;
        return *this;
    }

    Screen &set(pos r, pos c, char ch) {
        contents[r * width + c] = ch;
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    void do_display(std::ostream &os) const {
        os << contents;
    }

    pos size() const {
        return height * width;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

#endif //DEMO1_SCREEN_H
