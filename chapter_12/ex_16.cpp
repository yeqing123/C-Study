#include <memory>

using namespace std;

int main()
{
    // 标准库为了防止对unique_ptr对象的拷贝和赋值操作，
    // 将其拷贝和赋值的函数命名为delete
    unique_ptr<int> up(new int(10));
    unique_ptr<int> up2(up);   // unique_ptr不支持拷贝
    unique_ptr<int> up3;
    up3 = up;                  // 也不支持赋值
}