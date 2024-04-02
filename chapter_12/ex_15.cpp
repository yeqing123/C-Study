#include <iostream>
#include <memory>

using namespace std;

struct destination {};
struct connection {};
// 打开连接
connection connect(destination*)
{
    cout << "Open the connection" << endl;
    return connection();
}
// 关闭连接
void disconnection(connection)
{
    cout << "Close the connection" << endl;
}

void f1(destination &d)
{
    connection c = connect(&d);
    // 使用连接
    cout << "Using the connection..." << endl;
    // 忘记关闭连接
}

void f2(destination &d)
{
    int i = 2, j = 0;
    connection c = connect(&d);
    // 使用lambda表达式代替上一题的close_connection函数
    shared_ptr<connection> sp(&c, [](connection *p) { disconnection(*p); });
    // 使用连接
    cout << "Using the connection..." << endl;
    // 忘记关闭连接
}

int main()
{
    destination d = destination();
    f1(d);
    cout << endl;
    f2(d);  // 因为使用了智能指针，即使在函数中忘记关闭连接，退出函数时依然可以释放资源
    return 0;
}