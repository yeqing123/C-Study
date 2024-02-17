#include <iostream>
using namespace std;
// func函数返回一个包含10个string对象的数组的引用
string (&func()) [10] 
{
    // 把数组定义成static类型，使其不会因为函数执行完毕而被销毁
    static string sarr[10] = {
        "word_0", "word_1", "word_2", "word_3",
        "word_4", "word_5", "word_6", "word_7", 
        "word_8", "word_9"};
    return sarr;
}

int main()
{
    // 输出函数返回的数组的元素，以验证返回值是数组的引用而非指针
    for (auto elem : func()) {
        cout << elem << endl;
    }
    return 0;
}