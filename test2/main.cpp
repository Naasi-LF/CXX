#include <bits/stdc++.h>
using namespace std;

class Book {
public:
    string bookNum;  // 书号
    string bookName; // 书名
    double price;    // 价格
};

class Library {
private:
    list<Book> books; //使用list容器储存
public:
    Library() 
    {
        cout << "input count:\n";
        int m;
        cin >> m;
        while (m--) 
        {
            Book B;
            cin >> B.bookNum >> B.bookName >> B.price;
            books.push_back(B);//链表尾插一个数据
        }
    }

    void Insert(Book &newBook, int index) 
    {
        auto it = books.begin();
        advance(it, index - 1);//移动index-1个单位,这里不能用it+index-1
        books.insert(it, newBook);//链表结构不是连续的，不能像vector操作

        for (const Book &i : books) 
        {
            cout << i.bookNum << " " << i.bookName << " " << fixed << setprecision(2) << i.price << endl;
        }
    }

    void Erase(int index) {
        auto it = books.begin();
        advance(it, index - 1);//与前面理由一致
        books.erase(it);

        for (const Book &i : books) 
        {
            cout << i.bookNum << " " << i.bookName << " " << fixed << setprecision(2) << i.price << endl;
        }
    }

    void Repeat() {
        unordered_set<string> U;   
        list<Book> Ubook;          

        for (auto it = books.begin(); it != books.end();) //不是数组结构，不能用索引i，因此使用迭代器指针
        {
            if (U.find(it->bookNum) == U.end()) 
            {
                U.insert(it->bookNum);
                Ubook.push_back(*it);
                it++;
            } else {
                it = books.erase(it);
            }
        }

        cout << books.size() << endl;

        for (const Book &i : books) 
        {
            cout << i.bookNum << " " << i.bookName << " " << fixed << setprecision(2) << i.price << endl;
        }
    }

    ~Library() {
        books.clear();
    }
};

int main() 
{
    Library library;
    while (1) 
    {
        cout << "choose one:\n" << "1. Insert\n" << "2. Erase\n" << "3. Repeat\n" << "4. exit" << endl;
        int i;
        cin >> i;
        switch (i) 
        {
            case 1: 
            {
                int index;
                Book newBook;
                cin >> index;
                cin >> newBook.bookNum >> newBook.bookName >> newBook.price;
                cout << endl; //美观
                library.Insert(newBook, index);
                break;
            }
            case 2: 
            {
                int index;
                cin >> index;
                cout << endl;
                library.Erase(index);
                break;
            }
            case 3: 
            {
                cout << endl;
                library.Repeat();
                break;
            }
            case 4:
                break;
            default: 
            {
                cout << "error\n";
                break;
            }
        }
        if (i == 4) 
            break;
    }
    system("pause");
    return 0;
}
