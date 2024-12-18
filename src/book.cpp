#include "../inc/book.hpp"

Book::Book(const std::string& title, const std::string& author, int year) {
    this->title = title;
    this->author = std::make_shared<std::string>(author); // #13
    this->year = year;
    std::cout << "Book constructor called for: " << this->title << std::endl;
}

Book::~Book() {
    std::cout << "Book destructor called for: " << this->title << std::endl;
}

Book::Book(const Book& other) {
    this->title = other.title;
    this->author = other.author; // #14
    this->year = other.year;
    std::cout << "Book copy constructor called for: " << this->title << std::endl;
}

Book::Book(Book&& other) noexcept {
    this->title = std::move(other.title);
    this->author = std::move(other.author);
    this->year = other.year;
    std::cout << "Book move constructor called for: " << this->title << std::endl;
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        this->title = other.title;
        this->author = other.author; // #14
        this->year = other.year;
    }
    std::cout << "Book copy assignment operator called for: " << this->title << std::endl;
    return *this;
}

Book& Book::operator=(Book&& other) noexcept {
    if (this != &other) {
        this->title = std::move(other.title);
        this->author = std::move(other.author);
        this->year = other.year;
    }
    std::cout << "Book move assignment operator called for: " << this->title << std::endl;
    return *this;
}

void Book::display() const {
    std::cout << "Title: " << this->title
              << ", Author: " << (this->author ? *this->author : "None")
              << ", Year: " << this->year << std::endl;
}
