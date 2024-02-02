# include <iostream>
int main()
{
    // 这两条是正确的
    std::cout << "/*";
    std::cout << "*/";
    
    // 下面两条是错误的
    //std::cout << /* "*/" */;
    //std::cout << /* "*/" /* "*/" */;
    // 应当修改为
    std::cout << "/* */ */";
    std::cout << "/* */ /* */ */";
}