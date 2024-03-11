# include <iostream>
int main() 
{
    // 使用转移序列先输出2M，然后转到新一行
    std::cout << "\62\115\012";
    // 先输出2，再输出一个制表符，再输出字母M，最后转到新的一行
    std::cout << "2\tM\n";

    return 0;
}