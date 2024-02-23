#include <vector>
class NoDefault {   
public:
    // 没有定义默认构造函数
    NoDefault(int i) {}
};

struct C {
   // C() {};  // 报错，因为NoDefault类没有定义默认构造函数
    NoDefault nd;  // 没有初始值
};

int main()
{
    // 运行程序时会出错，因为NoDefault缺少默认构造函数
    std::vector<C> vec(10);   
    std::vector<NoDefault> vec(10);
}