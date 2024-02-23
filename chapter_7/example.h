#include <vector>
class Example {
public:
    static double rate = 3.5;
    static const int vecSize = 20;
    // 编译器会把vec当作一个静态成员函数，故而把vecSize视为参数类型，从而报错。应该去掉圆括号只做声明，然后在类的外部定义它。
    static std::vector<double> vec(vecSize);  
};
//std::vector<double> Example::vec(vecSize);  //在类的外部定义就没有错误了