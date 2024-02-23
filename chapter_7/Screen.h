#ifndef SCREEN_H
#define SCREEN_H
class Screen {
    typedef std::string::size_type pos; 
    // 把Window_mgr类声明为友元
    friend class Window_mgr;
private:
    std::string contents;
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    // 私有的成员函数，按照指定的行数和列数输出contents的内容
    void do_display(std::ostream &os) const 
    {
        for (std::string::size_type row = 0; row != height; ++row) {
            for (std::string::size_type col = 0; col != width; ++col) {
                os << contents[row * width + col];
            }
            os << "\n";  // 每输出完一行后换行
        }
    }

public:
    // 自定义构造函数
    Screen() = default;
    Screen(pos ht, pos wh) : height(ht), width(wh), contents(ht * wh, ' ') {}
    Screen(pos ht, pos wh, char c) : height(ht), width(wh), contents(ht * wh, c) {}
    // 定义成员函数，它是隐式的内联函数
    char get() const {
        return contents[cursor];
    }
    Screen &set(char c) {
        contents[cursor] = c;
        return *this;
    }
    // 声明成员函数
    char get(pos, pos) const;  // 获得指定位置的字符
    Screen &set(pos, pos, char); // 设置指定位置的字符
    Screen &move(pos row, pos col);  // 将光标移动的指定位置
    Screen &display(std::ostream&);  // 通过标准输出流打印contents，并返回对象的引用
    const Screen &display(std::ostream&) const;  // 重载函数，返回常量对象的引用，使display函数可适用于常量对象
    pos size() const;     // 返回屏幕的大小
};

inline char Screen::get(pos row, pos col) const {
    return contents[row * width + col];
}

inline Screen &Screen::set(pos row, pos col, char c) {
    contents[row * width + col] = c;
    return *this;   // 返回当前对象的引用
}

inline Screen &Screen::move(pos row, pos col) {
    cursor = row * width + col;
    return *this;
}

// 调用do_display，定义两个重载函数
inline const Screen &Screen::display(std::ostream& os) const {
    do_display(os);
    return *this;
}

inline Screen &Screen::display(std::ostream& os) {
    do_display(os);
    return *this;
}

// 必须指定返回类型pos是属于Screen类的，否则编译器会报错
inline Screen::pos Screen::size() const {
    return this->height * this->width; 
}
#endif