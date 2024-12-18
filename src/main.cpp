#include "../inc/book.hpp"

int main() {
    Book book1("BookName1", "Author1", 2000); 
    book1.display();

    Book book2("BookName2", "Author2", 2010); 
    book2.display();

    Book book3("BookName3", "Author3", 2020); 
    book3.display();

    Book book4("BookName4", "Author4", 2022); 
    book4.display();

    return 0;
}
