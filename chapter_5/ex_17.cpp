#include <iostream>
#include <vector>

using namespace std;

// 比较两个包含整数的vector，判断其中一个是否为另一个的前缀，
// 后面两个string参数分别表示两个序列的名字
void compareIvec(const vector<int> &v1, const vector<int> &v2, 
    const string &name1, const string &name2)
{
    auto iter1 = v1.cbegin(), iter2 = v2.cbegin();
    while (iter1 != v1.cend() && iter2 != v2.cend()) {
        if (*iter1 != *iter2) {                      // 如果出现元素不相等，则直接退出函数
            cout << name1 << " and " << name2 << " are not equal!" << endl; 
            return ;
        }   
        ++iter1;
        ++iter2;
    }
    if (iter1 == v1.cend()) {
        cout << name1 << " is " << name2 << "'s prefix" << endl;
    } else {
        cout << name2 << " is " << name1 << "'s prefix" << endl;
    }
}
int main()
{
    vector<int> v1 = {0, 1, 1, 2, 3}, v2 = {0, 1, 1, 2, 3, 5, 8};
    vector<int> v3 = {0, 1, 3, 6, 7}, v4 = {5, 3, 6, 8, 0, 1, 1, 3};
    compareIvec(v1, v2, "v1", "v2");
    compareIvec(v3, v4, "v3", "v4");
    return 0;
}