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

// 自定义shared_ptr指针的删除器
void close_connection(connection *p)
{
    disconnection(*p);
}

void f2(destination &d)
{
    int i = 2, j = 0;
    connection c = connect(&d);
    // 创建智能指针，并传入指定的“删除器”
    shared_ptr<connection> sp(&c, close_connection);
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