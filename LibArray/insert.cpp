
#include "book.h"
void bookInsert(vector<Book>& bookArray)
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
    Book newBook;
    cin >> index;
    cin >> newBook.bookNum >> newBook.bookName >> newBook.price;
    bookArray.insert(bookArray.begin()+index-1,newBook);
    for (Book& i:bookArray)
    {
        cout << i.bookNum << " " << i.bookName << " " << fixed << setprecision(2) << i.price << endl;
    }
    
}