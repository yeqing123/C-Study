#include <iostream>
#include <iterator>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 4) {                     // 首先判断传入程序的参数数量是否为4        
        cerr << "Wrong number of parameters!" 
             << "\nYou should enter it in this format: " 
             << "ex_33.exe input_file output_file1 output_file2" << endl;
        exit(1);
    }
    ifstream in(argv[1]);               // 创建文件输入流，并判断文件是否成功打开    
    if (!in) {
        cerr << "Opening input file \"" << argv[1] << "\" fail!" << endl;
        exit(1);
    }
    ofstream out1(argv[2]), out2(argv[3]);  // 创建文件输出流，如果文件不存在，程序会自动创建该文件，因此无需判断
    istream_iterator<int> in_iter(in), eof; // 创建流迭代器
    ostream_iterator<int> out_iter1(out1, " "), out_iter2(out2, "\n");
    while (in_iter != eof) {                // 通过流迭代器从输入文件中读取元素，并存入对应的输出文件中
        if (*in_iter % 2 == 0) {
            *out_iter2++ = *in_iter++;       // 偶数存入第二个文件
        } else {
            *out_iter1++ = *in_iter++;       // 奇数存入第一个文件
        }
    }
    return 0;
}