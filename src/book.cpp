#include "../inc/book.hpp"

Book::Book(const std::string& title, const std::string& author, int year) {
    this->title = title;
    this->author = std::shared_ptr<std::string>(new std::string(author), ResourceDeleter());
    this->year = year;
    std::cout << "Book constructor called for: " << this->title << std::endl;
}

Book::~Book() {
    std::cout << "Book destructor called for: " << this->title << std::endl;
}

void Book::display() const {
    std::cout << "Title: " << this->title
              << ", Author: " << (this->author ? *this->author : "None")
              << ", Year: " << this->year << std::endl;
}
