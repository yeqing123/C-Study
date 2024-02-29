#include <iostream>
#include <sstream>
// 修改练习1，是的read可以从一个istringstream对象中读取数据
std::istringstream& read(std::istringstream& is) {
    std::cout << "Enter some strings: " << std::endl;
    std::string s;
    while (is >> s) { 
        std::cout << s << std::endl;  // 从输入中读取数据然后打印到标准输出流
    }
    is.clear();  // 将输入流复位，使它可以继续正常使用
    return is;
}

int main()
{
    std::string s("hello world");
    std::istringstream sin(s);
    std::istringstream &istrm = read(sin);  // 从string流中读取内容
    istrm.str(s);   // 将字符串拷贝到istrm流中，因为使用clear函数已将流的状态复位，所以istrm流可以继续使用
    read(istrm);
    return 0;
}