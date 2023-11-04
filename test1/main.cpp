// 图书馆管理系统
#include <bits/stdc++.h>
using namespace std;
class Book
{
public:
    string bookNum;//书号
    string bookName;//书名
    double price;//价格
};

class Library//构建一个图书馆类
{
private:
    vector<Book> books;//线性表存储结构,顺序存储这里用vector
public:
    Library()
    {
        cout << "input count:\n";
        int m;
        cin >> m;
        //录入结构体
        while (m--)
        {
            Book B;//输入的结构体变量
            cin >> B.bookNum >> B.bookName >> B.price;
            books.push_back(B);
        }
    }
    void Insert(Book& newBook,int index)//插入
    {
        books.insert(books.begin()+index-1,newBook);
        for (Book& i:books)
        {
            cout << i.bookNum << " " << i.bookName << " " << fixed << setprecision(2) << i.price << endl;
        }
    }
    void Erase(int index)//删除
    {
        books.erase(books.begin()+index-1);
        for (Book& i:books)
        {
            cout << i.bookNum << " " << i.bookName << " " << fixed << setprecision(2) << i.price << endl;
        }
    }
    void Repeat()//去重
    {
        unordered_set<string> U;//去重标记,储存书号

        for (size_t i =0;i<books.size();i++)
        {
            if (U.find(books[i].bookNum) == U.end())//如果没有插入过
            {
                U.insert(books[i].bookNum);//插入保存
            }
            else{
                books.erase(books.begin()+i);//不然就删掉
            }
        }
        cout << books.size() << endl;
        for (Book& i:books)
        {
            cout << i.bookNum << " " << i.bookName << " " << fixed << setprecision(2) << i.price << endl;
        }
    }
    ~Library()
    {
        books.clear();
    }
};

int main()
{
    Library library;
    while (1)
    {
        cout << "choose one:\n" << "1. Insert\n" << "2. Erase\n" << "3. Repeat\n" << "4. exit" << endl;
        int i; cin >> i;
        switch (i)
        {
            case 1:
            {
                int index;
                Book newBook;
                cin >> index;
                cin >> newBook.bookNum >> newBook.bookName >> newBook.price;
                cout << endl;//美观性
                library.Insert(newBook,index);
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
        if(i==4)//退出循环
            break;
    }
    system("pause");
    return 0;
}