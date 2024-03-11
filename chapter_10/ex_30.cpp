#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, " ");
    vector<int> ivec;
    copy(in_iter, eof, inserter(ivec, ivec.begin()));  // 使用迭代器范围从标准输入流中读取整数，并使用插入迭代器保存到容器中
    sort(ivec.begin(), ivec.end());                    // 对容器中的元素进行排序
    copy(ivec.begin(), ivec.end(), out_iter);          // 将排序后的结果打印到标准输出流中

    return 0;
}