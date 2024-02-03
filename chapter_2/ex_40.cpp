# include <iostream>
int main()
{
    struct Sales_data {
        std::string bookName;   // 书名
        unsigned sold_quantity = 0; // 总销售量, unsigned单独使用表示：unsigned int
        double sold_amount = 0.0;   // 总销售额
        double average_price = 0.0;   // 平均价格
    };
}