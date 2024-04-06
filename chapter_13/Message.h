#ifndef MY_MESSAGE_H
#define MY_MESSAGE_H
#include <set>
#include <string>
#include "Folder.h"

class Message {
friend class Folder;
friend void swap(Message&, Message&);             
public:
    Message(const std::string s = std::string()) :  // 含参数的构造函数，同时也是默认构造函数 
        contents(s) { }
    Message(const Message&);                        // 拷贝构造函数
    Message(Message&&) noexcept;                    // 移动构造函数
    Message &operator=(const Message&);             // 拷贝赋值运算符
    Message &operator=(Message&&) noexcept;         // 移动赋值运算符
    ~Message();                                     // 析构函数
    void save(Folder*);                             // 将自己添加到指定的Folder中
    void remove(Folder*);                           // 将自己从指定的Folder中删除
    void addFldr(Folder*);                          // 将指定的Folder添加给自己的folders
    void remFldr(Folder*);                          // 从自己的folders中删除指定的Folder
private:
    std::string contents;                           // 消息内容
    std::set<Folder*> folders;                      // 消息所在的Folder对象
    // 定义两个在Message对象的拷贝、赋值操作中用得到工具函数，
    void add_to_folders(const Message&);            // 把自己添加到给定Message的folders集合的每个Folder中
    void remove_from_folders();                     // 从每个Folder中移除自己
    void move_Folders(Message*);                    // 移动给定Message对象的folders
};

// 拷贝构造函数
Message::Message(const Message &m) : 
    contents(m.contents), folders(m.folders)
{
    add_to_folders(m);
}

// 拷贝赋值运算符，要保证自赋值的正确
inline Message& Message::operator=(const Message &rm) 
{
    remove_from_folders();   // 从运算符左侧的对象的folders集合中删除其自身
    add_to_folders(rm);      // 将运算符左侧的对象添加到运算符右侧对象的floder集合中
    // 拷贝数据成员
    contents = rm.contents;
    folders = rm.folders;
    return *this;
}

// 因为移动数据成员folders时还需要处理对应的Folder。
// 为了避免重复，我们单独提出来用一个函数实现。
void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);  // 移动folders
    // 处理每个Folder        
    for (auto f : folders) {
        f->remMsg(this);
        f->addMsg(m);
    }
    m->folders.clear();  // 确保销毁m是无害的
}

// 移动构造函数
Message::Message(Message &&m) noexcept : contents(std::move(m.contents))
{
    move_Folders(&m);    // 移动folders，并更新每个Folder
}

// 移动赋值运算符
Message &Message::operator=(Message &&rm) noexcept
{
    if (this != &rm) {           // 如果是自赋值，则什么也不做。
        remove_from_folders();   // 从每个Folder中移除自己
        move_Folders(&rm);       // 移动folders
        contents = std::move(rm.contents);  // 移动contents
    }
    return *this;
}

// 析构函数
Message::~Message() { remove_from_folders(); }

// 把自己添加到给定Message的folders集合的每个Folder中
inline void Message::add_to_folders(const Message &m) 
{
    for (auto f : m.folders) {
        f->addMsg(this);
    }
}

// 从每个Folder中移除自己
inline void Message::remove_from_folders()
{
    for (auto f : folders) {
        f->remMsg(this);
    }
}

// 将自己添加到指定的Folder中
inline void Message::save(Folder *f)
{
    folders.insert(f);           // 将给定的Folder添加到floder集合中
    f->addMsg(this);             // 向给定的Folder中添加Message
}

// 将自己从指定的Folder中删除
inline void Message::remove(Folder *f)
{
    folders.erase(f);           // 从folders集合中删除指定的Folder
    f->remMsg(this);            // 从指定的Folder中删除Message
}

// 将指定的Folder添加给自己的folders
/*
* 注意save、remove与addFldr、remFldr两对函数的区别
* 前者是将一个Message从指定的Folder中保存或删除，
* 需要同时操作folders和messages两个集合。
* 后者只是单纯地将指定的Folder从函数调用者的folders集合中添加或删除，
* 无需操作messages集合。
*/
inline void Message::addFldr(Folder *f)
{
    folders.insert(f);
}

// 从自己的folders中删除指定的Folder
inline void Message::remFldr(Folder *f)
{
    folders.erase(f);
}

inline void swap(Message &lm, Message &rm)
{
    // 先从各自的folder列表中删除自己
    lm.remove_from_folders();            
    rm.remove_from_folders();            
    // 将各自添加到对方的folder列表中 
    lm.add_to_folders(rm);
    rm.add_to_folders(lm);
    // 调用库函数swap，交换数据成员
    std::swap(lm.contents, rm.contents);
    std::swap(lm.folders, rm.folders);
}
#endif