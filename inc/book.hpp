#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <iostream>
#include <memory> // #14

class Book {
private:
    std::string title;
    std::shared_ptr<std::string> author; // #13
    int year;

public:
    Book(const std::string& title = "Unknown Title",
         const std::string& author = "Unknown Author",
         int year = 0);

    ~Book();

    Book(const Book& other);
    Book(Book&& other) noexcept;

    Book& operator=(const Book& other);
    Book& operator=(Book&& other) noexcept;

    Book& operator=(int) = delete;
    Book(int) = delete;

    void display() const;
};

#endif // BOOK_HPP
