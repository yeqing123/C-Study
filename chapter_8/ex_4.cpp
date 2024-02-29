#include <fstream>
#include <iostream>
#include <vector>
// 函数readf以读模式打开一个文件，将每行的内容保存在string的vector中
std::vector<std::string> readf(std::string filename) {
    std::ifstream in(filename);     // 创建一个读取文件的输入流对象，并将其关联到指定的文件上
    std::vector<std::string> vec;
    if (in) {
        std::string s;
        while (getline(in, s)) {    // 从文件输入流中读取一行数据，保存到字符串s中
            vec.push_back(s);
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