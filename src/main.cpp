#include "../inc/book.hpp"

int main() 
{
    Book book1("BookTitle", "BookAuthor", 1949);
    book1.display();
    Book book2 = book1;
    book2.display();
    Book book3 = std::move(book1);
    book3.display();
    return 0;
}
