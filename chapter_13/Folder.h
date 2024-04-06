#ifndef MY_FOLDER_H
#include <string>
#include <set>
#include "Message.h"

class Message;
class Folder {
public:
    Folder() { };
    Folder(const std::set<Message*> ms) : messages(ms) {}
    Folder(const Folder&);
    Folder &operator=(const Folder&);
    ~Folder();
    void addMsg(Message*);
    void remMsg(Message*);
private:
    std::set<Message*> messages;
    // 定义两个工具类，用于Folder对象的拷贝和赋值操作
    void add_to_messages(const Folder&);    // 将自己添加给指定Folder对象的messages集合中
    void remove_from_messages();            // 将自己从messages集合中删除
};

// 拷贝构造函数
Folder::Folder(const Folder &f)
{
    add_to_messages(f);
}

// 析构函数
Folder::~Folder() { remove_from_messages(); }

// 将指定的Message对象添加到messages集合中
inline void Folder::addMsg(Message *m)
{
    messages.insert(m);
}

// 将指定的Message对象从messages集合中删除
inline void Folder::remMsg(Message *m)
{
    messages.erase(m);
}

// 将自己添加给指定的messages集合中
inline void Folder::add_to_messages(const Folder &f) 
{
    for (auto m : f.messages) {
        m->addFldr(this);
}

// 将自己从messages集合中删除
inline void Folder::remove_from_messages()
{
    for (auto m : messages) {
        m->remFldr(this);
    }
}

// 重载拷贝赋值运算符
inline Folder &Folder::operator=(const Folder &f)
{
    add_to_messages(f);      // 将自己添加给f中的messages集合
    remove_from_messages();  // 将自己从自己的messages集合中删除
    messages = f.messages;   // 将运算符右侧的messages成员拷贝给运算符左侧的对象
    return *this;
}
#endif