#include "../inc/book.hpp"

Book::Book(const std::string& title, const std::string& author, int year) {
    this->title = title;
    this->author = new std::string(author);
    this->year = year;
    std::cout << "Book constructor called for: " << this->title << std::endl; 
}

Book::~Book() {
    delete author;
    std::cout << "Book destructor called for: " << this->title << std::endl;
}

Book::Book(const Book& other) {
    this->title = other.title;
    this->author = new std::string(*other.author);
    this->year = other.year;
    std::cout << "Book copy constructor called for: " << this->title << std::endl; 
}

Book::Book(Book&& other) noexcept {
    this->title = std::move(other.title);
    this->author = other.author;
    this->year = other.year;
    other.author = nullptr;
    std::cout << "Book move constructor called for: " << this->title << std::endl;
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        delete this->author;
        this->title = other.title;
        this->author = new std::string(*other.author);
        this->year = other.year;
    }
    std::cout << "Book copy assignment operator called for: " << this->title << std::endl; 
    return *this;
}

Book& Book::operator=(Book&& other) noexcept {
    if (this != &other) {
        delete this->author;
        this->title = std::move(other.title);
        this->author = other.author;
        this->year = other.year;
        other.author = nullptr;
    }
    std::cout << "Book move assignment operator called for: " << this->title << std::endl;
    return *this;
}

void Book::display() const {
    std::cout << "Title: " << this->title
              << ", Author: " << (this->author ? *this->author : "None")
              << ", Year: " << this->year << std::endl;
}
