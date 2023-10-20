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
    vector<Book> bookArray; // 存储图书信息的动态数组
    // 读入图书信息
    while (1) 
    {
        Book book;
        cin >> book.bookNumber >> book.bookName >> book.price;
        // 判断输入是否结束
        if (book.bookNumber == "0" && book.bookName == "0" && book.price == 0.0) 
            break;  
        bookArray.push_back(book);
    }
    cout << bookArray.size();
    // 输出排序后的图书信息
    for (Book& book : bookArray)     
        cout << book.bookNumber << " " << book.bookName << " " << fixed << setprecision(2) << book.price << endl;
    return 0;
}
