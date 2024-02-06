#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    char s1[] = "hello ", s2[] = "world";
    // 将s2连接到s1的尾端
    strcat(s1, s2);
    cout << strlen(s1) << endl;
    // 定义s3，其维度等于连接后的字符串长度
    char s3[strlen(s1)];
    // 将连接后的字符串拷贝到s3中
    strcpy(s3, s1);
    // 打印结果
    for (char c : s3) {
        cout << c;
    }
    cout << endl;
    return 0;
}