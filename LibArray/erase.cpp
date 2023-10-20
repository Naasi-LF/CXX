#include "book.h"
void bookErase(vector<Book>& bookArray)
{
    int m;
    cin >> m;
    //录入结构体
    for (int i = 0; i < m; i++)
    {
        Book B;
        cin >> B.bookNum >> B.bookName >> B.price;
        bookArray.push_back(B);
    }
    int index;
    cin >> index;
    bookArray.erase(bookArray.begin()+index-1);
    for (Book& i:bookArray)
    {
        cout << i.bookNum << " " << i.bookName << " " << fixed << setprecision(2) << i.price << endl;
    }
}