#include <iostream>
#include "StrBlob.h"

using namespace std;

int main()
{
    const StrBlob sb{"I", "am", "learning", "C++"}, sb2({"aa", "bb"});
    
    // 利用StrBlobPtr类，在for循环中遍历打印sb的所有元素
    bool first_word = true;
    auto end = sb.end();
    for (auto p = sb.begin(); neq(p, end); p.incr()) {
        if (first_word) {
            first_word = false;
        } else {
            cout << " ";
        }
        cout << p.deref();
    }
    cout << endl;

    StrBlobPtr sbp(sb, 0), sbp2(sb, 1), sbp3;
    // 验证eq函数结果
    // 一、两个对象中的当前位置虽然一样（都是0），但它们没有指向同一个序列
    cout << eq(StrBlobPtr(sb2, 0), sbp) << endl; 
    // 二、两个对象虽然指向了同一个序列，但是当前位置不同
    cout << eq(sbp, sbp2) << endl;
    // 三、两个对象指向同一个序列，并且当前位置也相同 
    cout << eq(StrBlobPtr(sb, 1), sbp2) << endl;
    // 四、两个对象都没有绑定序列，都为空 
    cout << eq(StrBlobPtr(), sbp3) << endl;

    // 应该抛出一个异常
    cout << sbp3.deref() << endl;
}