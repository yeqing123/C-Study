#include <iostream>
using namespace std;
// 根据书中268页的示例，定义自己的Debug类
class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {};
    void set_hw(bool b) {
        hw = b;
    }
    void set_io(bool b) {
        io = b;
    }
    void set_other(bool b) {
        other = b;
    }
    constexpr ostream &print_msg(ostream&);
private:
    bool hw;
    bool io;
    bool other;
};
constexpr ostream &Debug::print_msg(ostream &os) {
    if (hw) {
        os << "\tprint hardware error messages.\n";
    }
    if (io) {
        os << "\tprint aperation error messages.\n";
    }
    if (other) {
        os << "\tprint other error messages.\n";
    }
    return os;
}

int main()
{
    // 使用不同的构造函数创建Debug对象
    Debug all_err;
    Debug no_err(false);
    Debug io_err(false, true, false);
    Debug other_err(false, false, true);
    // 打印错误信息
    cout << "debug all_err: " << endl;
    all_err.print_msg(cout) << endl;
    cout << "debug no_err: " << endl;
    no_err.print_msg(cout) << endl;
    cout << "debug io_err: " << endl;
    io_err.print_msg(cout) << endl;
    cout << "debug other_err: " << endl;
    other_err.print_msg(cout) << endl;

    cout << "all corrections..." << endl;
    // 修复所有的错误
    all_err.set_hw(false);
    all_err.set_io(false);
    all_err.set_other(false);
    io_err.set_io(false);
    other_err.set_other(false);
    // 再次打印结果（应该没有任何错误信息）
    cout << "debug all_err: " << endl;
    all_err.print_msg(cout) << endl;
    cout << "debug no_err: " << endl;
    no_err.print_msg(cout) << endl;
    cout << "debug io_err: " << endl;
    io_err.print_msg(cout) << endl;
    cout << "debug other_err: " << endl;
    other_err.print_msg(cout) << endl;

    return 0;
}