#include <iostream>
using namespace std;

string sarr[10] = {
    "word_0", "word_1", "word_2", "word_3",
    "word_4", "word_5", "word_6", "word_7", 
    "word_8", "word_9"
    };

// func函数返回一个包含10个string对象的数组的引用
string (&func()) [10] 
{
    return sarr;
}

int main()
{
    // 因为函数返回的数组的引用，所以可以直接输出其元素
    for (auto s : func()) {
        cout << s << " ";  
    }
    cout << endl;
    return 0;
}