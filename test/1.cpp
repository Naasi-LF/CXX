#include <bits/stdc++.h>
using namespace std;
// ����ͼ����Ϣ�ṹ��
struct Book {
    string bookNumber;
    string bookName;
    double price;
};
int main() 
{
    vector<Book> bookArray; // �洢ͼ����Ϣ�Ķ�̬����
    // ����ͼ����Ϣ
    while (1) 
    {
        Book book;
        cin >> book.bookNumber >> book.bookName >> book.price;
        // �ж������Ƿ����
        if (book.bookNumber == "0" && book.bookName == "0" && book.price == 0.0) 
            break;  
        bookArray.push_back(book);
    }
    cout << bookArray.size();
    // ���������ͼ����Ϣ
    for (Book& book : bookArray)     
        cout << book.bookNumber << " " << book.bookName << " " << fixed << setprecision(2) << book.price << endl;
    return 0;
}
