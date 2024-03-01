#include <iostream>
#include <string>
using namespace std;
// Date类保存年、月、日三个unsigned类型的成员数据，
// 其构造函数接受一个string参数，并可以处理各种类型的日期格式，
// 如：January 1, 1900、1/1/1990、Jan 1 1900等。
class Date {
public:
    Date(string date) 
    {
        trim(date);               // 去掉字符串两端的空格
        if (!verify(date)) {      // 验证传入构造函数的日期格式是否正确
            cerr << "There is an error in the date format!" << endl;
        } else {
            auto first_slash_pos = date.find_first_of("/");    // 查找是否为“月/日/年”这样的格式
            if (first_slash_pos != string::npos) {             // 如果是，则分析该格式类型的日期
                string month_str = date.substr(0, first_slash_pos);   // 截取月份子串
                month = stoi(month_str);                              // 转换成数值
                string dandy = date.substr(first_slash_pos + 1);      // 截取“日”与“年”的子串
                auto second_slash_pos = dandy.find_first_of("/");     // 查找第二个斜杠
                string day_str = dandy.substr(0, second_slash_pos);   // 截取表示“日”的子串
                day = stoi(day_str);                                  // 转换成数值
                string year_str = dandy.substr(second_slash_pos + 1); // 截取“年”的子串
                year = stoi(year_str);                                // 转换成数值
            } else {                                                  // 分析“月/日/年”格式以外的其他格式
                string::size_type month_pos;
                // 查找表示月份的英文单词或缩写，并获取其第一次出现的位置month_pos(string类型的每个所有操作，都返回一个string::size_type值)
                if ((month_pos = date.find("January")) != string::npos or 
                    (month_pos = date.find("Jan")) != string::npos) {
                    month = 1;
                } else if ((month_pos = date.find("February")) != string::npos or 
                        (month_pos = date.find("Feb")) != string::npos) {
                    month = 2;
                } else if ((month_pos = date.find("March")) != string::npos or 
                        (month_pos = date.find("Mar")) != string::npos) {
                    month = 3;
                } else if ((month_pos = date.find("April")) != string::npos or 
                        (month_pos = date.find("Apr")) != string::npos) {
                    month = 4;
                } else if ((month_pos = date.find("May")) != string::npos) {
                    month = 5;
                } else if ((month_pos = date.find("Jnue")) != string::npos or 
                        (month_pos = date.find("Jun")) != string::npos) {
                    month = 6;
                } else if ((month_pos = date.find("July")) != string::npos or 
                        (month_pos = date.find("Jul")) != string::npos) {
                    month = 7;
                } else if ((month_pos = date.find("August")) != string::npos or 
                        (month_pos = date.find("Aug")) != string::npos) {
                    month = 8;
                } else if ((month_pos = date.find("September")) != string::npos or 
                        (month_pos = date.find("Sep")) != string::npos) {
                    month = 9;
                } else if ((month_pos = date.find("October")) != string::npos or 
                        (month_pos = date.find("Oct")) != string::npos) {
                    month = 10;
                } else if ((month_pos = date.find("November")) != string::npos or 
                        (month_pos = date.find("Nov")) != string::npos) {
                    month = 11;
                } else if ((month_pos = date.find("December")) != string::npos or 
                        (month_pos = date.find("Dec")) != string::npos) {
                    month = 12;
                }
                if (month_pos == 0) {                                           // 判断月份的单词是否在字符串的首位
                    int count = separator_count(date, "., ", true);             // 计算date字符串中分隔符数量（注意：当第三个参数为true时，
                                                                                // 只统计分隔符连续出现的次数，后面如果还有分隔符间隔出现则不予统计）
                    string dandy = date.substr(date.find_first_of("., ") + count);  // 如果是，则根据分隔符（逗号、点、空格）截取剩余的“日”与“年”的子串
                    auto pos = dandy.find_first_of(", ");                       // 查找并获取子串的分隔符
                    string day_str = dandy.substr(0, pos);                      // 截取“日”的子串
                    day = stoi(day_str);                                        // 并转换成数值
                    count = separator_count(dandy, "., ", true);
                    string year_str = dandy.substr(pos + count);                // 截取剩余的“年”的子串
                    year = stoi(year_str);                                      // 并转换成数值
                } else {
                    string day_str = date.substr(0, month_pos);                 // 如果月份在中间，则截取前面的“日”的子串
                    day = stoi(day_str);                                        // 并转换成数值
                    string year_str = date.substr(date.find_last_of(", ") + 1); // 截取月份后面的“年”的子串
                    year = stoi(year_str);                                      // 并转换成数值
                }
            }
        }
    }
    // 将日期打印到指定的输出流中
    ostream &print(ostream &os) const {
        os << "year: " << year << "\tmonth: " << month << "\tday: " << day;
        return os;
    }
private:
    unsigned year = 0;
    unsigned month = 0;
    unsigned day = 0;
    // 验证日期字符串的格式是否合法
    bool verify(string date) const 
    {
        // 如果在字符串中存在"/"，则"/"只能出现两次
        if (separator_count(date, "/") == 2) {
            return true;
        } else {                                                        // 当字符串中没有“/”时，则需要对其他格式进行分析判断
            int count = 0, sum = 0;                                     // count保存每当年、月、日的分隔符连续出现时的个数
                                                                        // sum保存字符串中一共间隔出现了几次分隔符（连续的算作一次）
            // while循环每次都会得到一个新的count（一个连续的分隔符的数量）
            while ((count = separator_count(date, "., ", true)) != 0) {
                ++sum;                                                  // 累计分隔符间隔性出现的次数
                date = date.substr(date.find_first_of("., ") + count);  // 截掉字符串中已经查找过的部分，只保留剩余部分
            }
            cout << "sum: " << sum << endl;
            if (sum == 2) {                                             // 只有当分隔符间隔性的出现2次，日期格式才算合法
                return true;
            }
        }
        return false;
    }
    // 统计date字符串中年、月、日的分隔符separator出现的次数。如果第三个参数continuous为true，
    // 则只统计第一次连续出现的分隔符个数，后面的不连续部分不予统计。如果传入该参数的实参为false，或者没有实参（默认值为false），
    // 则统计date中所有的分隔符的个数。
    int separator_count(string date, string separator, bool continuous = false) const 
    {
        int count = 0, pos = 0;
        while ((pos = date.find_first_of(separator, pos)) != string::npos) {
            ++count;
            ++pos;
            // 当continuous为true时，只统计第一次连续出现的分隔符个数
            if (continuous && pos < date.size() && 
                    (date.substr(pos, 1).find_first_of(separator)) == string::npos) {
                break;
            }
        }
        return count;
    }
    //C++ 去字符串两边的空格
    void trim(string &s) const
    {
        if (s.empty()) {
            return ;
        }
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
};

int main()
{
    Date("1/1/2024").print(cout) << endl;
    Date("Nov.25 1999").print(cout) << endl;
    Date("6th   May,   2024").print(cout) << endl;
    Date("Feb   20   2013").print(cout) << endl;   
    Date("September22nd  2012").print(cout) << endl;  // 日期格式错误，年、月、日都需要由分隔符“,”、“/”或空格进行分隔
}