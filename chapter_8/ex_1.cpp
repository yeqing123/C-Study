#include <iostream>
std::istream& read(std::istream& is) {
    std::cout << "Enter some strings: " << std::endl;
    std::string s;
    while (is >> s) {
        std::cout << s << std::endl;  // 从输入中读取数据然后打印到标准输出流
    }
    is.clear();                       // 将输入流复位，使它可以继续正常使用
    return is;
}

int main()
{
    std::istream &istrm =  read(std::cin);
    read(istrm);                     // 继续使用返回的输入流，验证它是否已经恢复正常
    return 0;
}