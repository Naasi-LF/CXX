#include <bits/stdc++.h>
using namespace std;
// 定义图书信息结构体
struct Book {
    string bookNumber;
    string bookName;
    double price;
};
int main() 
{
    double total=0.0;
    vector<Book> bookArray; // 存储图书信息的动态数组
    // 读入图书信息
    while (1) 
    {
        Book book;
        cin >> book.bookNumber >> book.bookName >> book.price;
        // 判断输入是否结束
        if (book.bookNumber == "0" && book.bookName == "0" && book.price == 0.0) 
            break;  
        total+=book.price;
        bookArray.push_back(book);
    }
    double averagePrice=total/bookArray.size();
    // 输出排序后的图书信息
    for (Book& book : bookArray)
    {
        if (book.price < averagePrice) 
            book.price *= 1.2; // 低于平均价格的价格提高20%
        else 
            book.price *= 1.1; // 高于或等于平均价格的价格提高10%
        
        cout << book.bookNumber << " " << book.bookName << " " << fixed << setprecision(2) << book.price << endl;
    }
    return 0;
}
