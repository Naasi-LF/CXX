#include "book.h"
void bookRepeat(vector<Book>& bookArray)
{
    int m;
    cin >> m;
    set<string> U;//去重标记
    vector<Book> Ubook;//去重的结构体
    //录入结构体
    for (int i = 0; i < m; i++)
    {
        Book B;
        cin >> B.bookNum >> B.bookName >> B.price;
        bookArray.push_back(B);
    }

    for (Book& B:bookArray)
    {
        if (U.find(B.bookNum) == U.end())//set容器没有这个数
        {
            U.insert(B.bookNum);
            Ubook.push_back(B);
        }
    }

    cout << U.size() << endl;

    for (Book& i:Ubook)
    {
        cout << i.bookNum << " " << i.bookName << " " << fixed << setprecision(2) << i.price << endl;
    }
}

    
