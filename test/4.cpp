#include<bits/stdc++.h>

using namespace std;

struct Book {
    string bookNumber;
    string bookName;
    double price;
};

int main() {
    int n;
    cin >> n; 
    vector<Book> bookArray(n); 

    for (int i = 0; i < n; i++) {
        cin >> bookArray[i].bookNumber >> bookArray[i].bookName >> bookArray[i].price;
    }

    reverse(bookArray.begin(), bookArray.end());

    for (const Book& book : bookArray) {
        cout << book.bookNumber << " " << book.bookName << " " << fixed << setprecision(2) << book.price << endl;
    }

    return 0;
}
