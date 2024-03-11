// #define NDEBUG // 当定义了预处理变量NDEBUG，则打开调试器；否则关闭调试器
#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &vec, unsigned index)
{
    size_t sz = vec.size();
    #ifndef NDEBUG  
    // 输出vector对象的大小
    cout << "vector size: " << sz << endl;
    #endif
    if (index == sz) {
        return ;
    }
    cout << vec[index] << endl;
    print(vec, index + 1); 
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(v, 0);
    return 0;
}