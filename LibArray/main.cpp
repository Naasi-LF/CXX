

#include "book.h"
#include "erase.h"
#include "insert.h"
#include "repeat.h"

int main()
{
    vector<Book> bookArray;
    int choose;
    cin >> choose;
    switch (choose)
    {
    case 1:
        bookRepeat(bookArray);
        break;
    case 2:
        bookInsert(bookArray);
        break;
    case 3:
        bookErase(bookArray);
        break;
    default:
        break;
    }
    system("pause");
}
