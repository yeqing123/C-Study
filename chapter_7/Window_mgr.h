#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include <vector>
#include <string>
#include "Screen.h"
class Window_mgr {
private:
    std::vector<Screen> screens{Screen(5, 5, 'X')};
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);   // 将指定的Screen对象中的contents设置为相同数量的空白字符
    std::vector<Screen> &get_screens() {  
        return screens;
    }
};

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}
#endif