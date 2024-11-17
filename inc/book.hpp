#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
#include <iostream>

class Book {
private:
    std::string title;
    std::string* author; 
    int year;

public:
    Book(const std::string& title, const std::string& author, int year);
    ~Book();
    Book(const Book& other);
    Book(Book&& other);
    void display() const;
};
#endif 
