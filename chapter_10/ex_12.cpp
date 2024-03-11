#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "../chapter_7/Sales_data_v3.h"   // 使用第七章自定义的Sales_data_v3类

using namespace std;

// 比较两个Sales_data对象中的isbn是否相等
bool compareIsbn(const Sales_data_v3 &record1, const Sales_data_v3 &record2)
{
    return record1.isbn() < record2.isbn();
}

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
    // 给vector中的元素按照isbn的字典顺序进行排序
    sort(vec.begin(), vec.end(), compareIsbn);
    // 打印经过排序后的结果
    for (auto &r : vec) { 
        print(cout, r) << endl;   // 调用接口print向控制台打印所有Sales_data_v3对象
    }
    return 0;
}