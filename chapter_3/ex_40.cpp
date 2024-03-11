#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    char s1[] = "hello ", s2[] = "world";
    // 定义一个结果数组，长度为拼接后的字符串长度（注意最后要多一个空字符）
    char result[strlen(s1) + strlen(s2) - 1];
    // 将字符串s1拷贝到结果字符串中
    strcpy(result, s1);
    // 将字符串s2拼接到结果字符串的末尾
    strcat(result, s2);
    // 打印结果
    cout << s1 << endl;
    cout << s2 << endl;
    cout << result << endl;
    return 0;
}