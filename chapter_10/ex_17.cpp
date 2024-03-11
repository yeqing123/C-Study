#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "../chapter_7/Sales_data_v3.h"   // 使用第七章自定义的Sales_data_v3类

using namespace std;

int main()
{
    ifstream in("Sales_data.txt");   // 打开命名文件并创建文件流
    if (!in) {
        cerr << "File opening faild!" << endl;
        return -1;
    }
    vector<Sales_data_v3> vec;
    Sales_data_v3 record;
    while (read(in, record)) {   // 调用Sales_data_v3.h中的接口read，从文件输入流中读取数据
        vec.push_back(record);
    }
    // 使用lambda表达式，将按照每个isbn的字典顺序进行排序
    sort(vec.begin(), vec.end(), 
        [] (const Sales_data_v3 &sd1, const Sales_data_v3 &sd2)
            { return sd1.isbn() < sd2.isbn(); }
    );
    // 打印经过排序后的结果
    for (auto &r : vec) { 
        print(cout, r) << endl;   // 调用接口print向控制台打印所有Sales_data_v3对象
    }
    return 0;
}