#include<bits/stdc++.h>
using namespace std;

// 定义图书信息结构体
struct Book {
    string bookNumber;
    string bookName;
    double price;
};

int main() {
    int n;
    cin >> n; // 读取图书数目
    vector<Book> bookArray(n); // 存储图书信息的动态数组

    // 读入图书信息
    for (int i = 0; i < n; i++) {
        cin >> bookArray[i].bookNumber >> bookArray[i].bookName >> bookArray[i].price;
    }

    double maxPrice = 0.0; // 最高价格的初始值
    vector<Book> mostBook; // 存储最贵图书的容器

    // 查找最高价格的图书
    for (const Book& book : bookArray) {
        if (book.price > maxPrice) 
        {
            maxPrice = book.price;
            mostBook.clear(); // 清空之前的最贵图书
            mostBook.push_back(book); // 添加新的最贵图书
        } 
        else if (book.price == maxPrice) 
        {
            mostBook.push_back(book); // 有多本价格相同的最贵图书
        }
    }

    // 输出最贵图书的信息
    cout << mostBook.size() << endl;
    for (const Book& book : mostBook) {
        cout << book.bookNumber << " " << book.bookName << " " << fixed << setprecision(2) << book.price << endl;
    }

    return 0;
}
