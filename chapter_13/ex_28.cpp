#include <iostream>
#include <vector>
/*
* 以类指针行为实现一个二叉树
*/

using namespace std;

class TreeNode {
// 声明友元
friend class BinStrTree;
friend void inorderTraversal(const TreeNode*);
friend TreeNode *buildTree(vector<string>&, int, int);
public:
    // 默认构造函数
    TreeNode(const string &s = string(), TreeNode *l = nullptr, TreeNode *r = nullptr) : 
        value(s), count(1), left(l), right(r) { }
    // 拷贝构造函数
    TreeNode(const TreeNode &t) : 
        value(t.value), left(t.left), right(t.right) 
    { 
        auto node = const_cast<TreeNode&>(t);   // 将常量类型的TreeNode引用，转换成非常量类型
        node.copyTree();                        // 递增t节点及其子树的引用计数
        count = node.count;                     // 拷贝引用计数
    }
    // 析构函数
    ~TreeNode() 
    { 
        releaseTree();          // 也需要对其子树中的所有节点执行releaseTree函数 
    }
    // 打印当前节点内容
    inline ostream &print(ostream &os) const
    {
        os << "value: " << value << ", count = " << count;
        return os;
    }
private:
    string value;           // 节点保存的值
    int count;              // 节点的引用计数
    TreeNode *left;         // 指向左子节点
    TreeNode *right;        // 指向右子节点
    // 将copyTree和releaseTree函数定义成私有成员，为的是防止从外部调用它们，
    // 使得节点引用计数的混乱，从而造成要么节点被过早释放，要么希望释放时无法释放，造成内存泄漏。
    // 对二叉树的修改应尽量由BinStrTree对象进行操作。
    void copyTree(void);        // 拷贝节点
    void releaseTree(void);     // 释放节点
};

// 将当前节点及其下面的左右子树都进行拷贝
inline void TreeNode::copyTree(void)
{
    // 递增本节点及其子树节点的引用计数count
    if (left) {                
        left->copyTree();  
    }
    if (right) {
        right->copyTree();
    }
    ++count;
}

// 将当前节点及其下面的左右子树都进行释放
inline void TreeNode::releaseTree(void)
{
    if (left) {                
        left->releaseTree();  
    }
    if (right) {
        right->releaseTree();
    }
    // 不一定每次都真的释放内存，通常是递减count，只到count==0时才释放内存
    if (--count == 0) {
        delete this;
    }
}

// 指向二叉树的指针类
class BinStrTree {
// 声明友元函数
friend void print_tree(const BinStrTree&);
public:
    // 默认构造函数
    BinStrTree(TreeNode *t = nullptr) : root(t) { }
    // 拷贝构造函数
    BinStrTree(const BinStrTree &bt) : root(bt.root) // 系统会先执行“root(bt.root)”，后执行函数体
    {                    
        if (root) {                            
            root->copyTree();
        }  
    }
    // 重载赋值运算符
    BinStrTree &operator=(const BinStrTree &bt)
    {
        if (bt.root) {
            bt.root->copyTree();    // 先拷贝运算符右侧对象
        }
        if (root) {
            root->releaseTree();   // 后释放运算符左侧对象，
        }
        root = bt.root;            // 最后执行拷贝，保证了对象自赋值的正确性
        return *this;
    }
    // 析构函数
    ~BinStrTree()
    {
        if (root) {
            root->releaseTree();      // 释放根节点一下的整棵树（先递减count的值，只有当count等于0时才真的释放内存）
        }
    }
private:
    TreeNode *root;           // 指向二叉树的根节点
};


// 以递归方式创建二叉树，保存参数sv中的元素
TreeNode *buildTree(vector<string> &sv, int left, int right)
{
    if (left > right) {
        return nullptr;
    }
    int mid = left + ((right - left) >> 1);
    // 注意：创建节点时必须使用new关键字分配动态内存，
    // 因为在动态内存中的对象函数退出依然有效，
    // 如果使用普通局部变量，函数退出对象即被销毁。
    TreeNode *root = new TreeNode(sv[mid]);       // 以中间位置的元素为树的根节点
    root->left = buildTree(sv, left, mid - 1);    // 将序列的左半边元素，创建为左子树
    root->right = buildTree(sv, mid + 1, right);  // 将序列的右半边元素，创建为右子树
    return root;                                  // 返回根节点指针
}

// 以中序遍历方式，打印二叉树所有节点（中序遍历打印的string顺序与原来的一致）
void inorderTraversal(const TreeNode *node)
{
    if (node) {
        inorderTraversal(node->left);
        node->print(cout) << endl;
        inorderTraversal(node->right);      
    }
}

// 打印BinStrTree对象，并判断是否为空树
void print_tree(const BinStrTree &tree) 
{
    if (!tree.root) {
        cout << "Empty tree!" << endl;
        return ;
    }
    inorderTraversal(tree.root);
}


int main()
{
    vector<string> sv{"aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh", "iii", "jjj"};
    TreeNode *root = buildTree(sv, 0, sv.size() - 1);  // 保存string序列sv，构建二叉树数据结构
    BinStrTree t1, t2;                                 // 创建两棵空树   
    {
        BinStrTree t3(root);                           // 创建第一个BinStrTree对象，树节点的count成员为初始值1
        BinStrTree t4(t3);                             // 以拷贝方式创建对象t4，count成员递增为2
                                                       // 说明有两个BinStrTree对象正在共享二叉树。
        t3 = t3;                                       // 保证自赋值也正确
                                                            
        // 以中序形式遍历二叉树   
        cout << "Inorder traversal the binary tree:" << endl;                        
        cout << "t3: ------------------" << endl;            
        print_tree(t3);
        cout << endl;

        cout << "t4: ------------------" << endl;     
        print_tree(t4);                                
        cout << endl;

        t2 = t4;                                       // 发生赋值拷贝，树节点的count成员变为3  
        cout << "t2 = t4:" << endl;                                       
        cout << "t2: ------------------" << endl;      // 此时内存中其实只有一份二叉树数据，
        print_tree(t2);                                // 被三个BinStrTree对象共享。
        cout << endl;                                                                            
    }
    // 作用域结束后，局部变量t3和t4的内存被释放，
    // 所有节点的count均递减为1，此时t2还在使用二叉树，
    cout << "releaseTree the memory for t3 and t4: " << endl;
    cout << "t2:-------------------" << endl;
    print_tree(t2);
    cout << endl;

    // t1自始至终都是空树
    cout << "t1:-------------------" << endl;
    print_tree(t1);                                       
    // 只有当t2也被释放，节点中count等于0时，
    // 二叉树的内存才会被释放。
}