//
// Created by 王泽鑫 on 2024/3/4.
//

#include "Screen.h"

Window_mgr &Window_mgr::clear(Window_mgr::ScreenIndex pos) {
    if (pos < screens.size()) {
        Screen screen = screens[pos];
        screen.contents = std::string(screen.height * screen.width, ' ');
    }
    return *this;
}
