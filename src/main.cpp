#include "../inc/book.hpp"

int main() {
    Book book1("BookName1", "Author1", 2000); 
    book1.display();

    Book book2 = book1; 
    book2.display();

    Book book3 = std::move(book1); 
    book3.display();

    Book book4("BookName2", "Author2", 2010);
    book4 = book2; 
    book4.display();

    book4 = std::move(book3); 
    book4.display();

    return 0;
}
