#include <iostream>
#include <vector>
#include <list>

using namespace std;

void output_list(list<int> lst) 
{
    for (auto i : lst) {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 为了区别inserter和back_inserter的区别，我们在三个容器中定义三个初始元素
    list<int> lst1{1, 2, 3}, lst2{1, 2, 3}, lst3{1, 2, 3};

    copy(vec.cbegin(), vec.cend(), inserter(lst1, lst1.begin()));  
    copy(vec.cbegin(), vec.cend(), back_inserter(lst2));
    copy(vec.cbegin(), vec.cend(), front_inserter(lst3));
    output_list(lst1);
    output_list(lst2);
    output_list(lst3);
    return 0;
}