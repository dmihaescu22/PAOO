#include "../inc/book.hpp"

Book::Book(const std::string& title,const std::string& author,int year) 
{
    this->title = title;
    this->author = new std::string(author);
    this->year = year;
    std::cout<<"Book constructor called for: "<<title<<std::endl;
}

Book::~Book() {
    if (author) {
        std::cout<<"Book destructor called for: "<< title <<", Year: "<<year<<std::endl;
    } else {
        std::cout<<"Book destructor called for an empty object"<<std::endl;
    }
    delete author;
}

Book::Book(const Book& other) 
{
    this->title = other.title;
    this->author = new std::string(*other.author);
    this->year = other.year;
    std::cout<<"Book copy constructor called for: "<<title<< std::endl;
}

Book::Book(Book&& other)
{
    this->title = std::move(other.title);
    this->author = other.author;
    this->year = other.year;
    other.author = nullptr;
    std::cout <<"Book move constructor called for: "<<title<< std::endl;
}

void Book::display() const 
{
    std::cout<<"Title: "<<title<<", Author: "<<*author<<", Year: "<<year<<std::endl;
}
