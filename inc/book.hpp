#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <iostream>
#include <memory>

class ResourceDeleter {
public:
    void operator()(std::string* ptr) {
        std::cout << "Custom deleter called for allocated resource\n";
        delete ptr;
    }
};

class Book {
private:
    std::string title;
    std::shared_ptr<std::string> author;
    int year;

public:
    Book(const std::string& title = "Unknown Title",
         const std::string& author = "Unknown Author",
         int year = 0);

    ~Book();

    Book(const Book& other) = delete;       // Blocat
    Book(Book&& other) noexcept = delete;   // Blocat

    Book& operator=(const Book& other) = delete; // Blocat
    Book& operator=(Book&& other) noexcept = delete; // Blocat

    void display() const;
};

#endif // BOOK_HPP
