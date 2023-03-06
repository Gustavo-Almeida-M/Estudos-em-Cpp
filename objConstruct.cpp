#include <iostream>

using namespace std;

class Book
{
    public:
    string title;
    string author;
    int pages;

    Book(string cTitle, string cAuthor, int cPages)
    {
        title = cTitle;
        author = cAuthor;
        pages = cPages;
    }
};

int main()
{
    Book book1("Carros", "Gustavo", 345);

    cout << book1.title;
}