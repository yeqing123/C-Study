#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char c;
    char *pca = new char[10];
    int i = 0;
    while (cin.get(c)) {       // 使用get函数从标准输入中读取字符
        if (isspace(c)) {     // 如果遇到空白字符，则结束输入
            break;
        }
        pca[i++] = c;
        if (i == 10) {
            throw out_of_range("Retain the upper limit of the array capacity!");
        }
    }
    pca[i] = '\0';            // 对于c风格的字符串，要在末尾添加额外的空字符
    cout << pca << endl;
    delete [] pca;

    return 0;
}