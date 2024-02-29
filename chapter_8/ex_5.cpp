#include <fstream>
#include <iostream>
#include <vector>
// 重写练习4，将每个单词作为一个独立元素保存在vector中
std::vector<std::string> readf(std::string filename) {
    std::ifstream in(filename);     // 创建一个读取文件的输入流对象，并将其关联到指定的文件上
    std::vector<std::string> vec;
    if (in) {
        std::string word;
        while (in >> word) {    // 从文件中挨个读取单词
            vec.push_back(word);
        }
    } else {    // 打开文件失败
        std::cerr << "Failed to open file!" << std::endl;
    }
    return vec;
}

int main() 
{
    std::vector<std::string> vec = readf("iotest.txt");
    // 将读取的内容打印到标准输出流
    for (auto s : vec) {
        std::cout << s << std::endl;
    }
    return 0;
}