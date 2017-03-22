#include <iostream>
#include <cstring>
#include "book.hpp"

/*Отсутствие nullprt обусловлено невосприимчивостью компилятора к нему*/

Book::Book() {
	name = new char;
	auth =  new char;
	publ = new char;
	year = 0;
	pages = 0;

}

const char* Book::get_auth() const {
	return this->auth;
}

const char* Book::get_name() const {
	return this->name;
}

const char* Book::get_publ() const {
	return this->publ;
}

const int Book::get_year() const {
	return this->year;
}

const int Book::get_pages() const {
	return this->pages;
}

void Book::set_auth(char* new_auth)  {
	size_t len = strlen(new_auth) +1;
	memcpy(auth, new_auth, len);
}

void Book::set_publ(char* new_publ)  {
	size_t len = strlen(new_publ) +1;
	memcpy(publ, new_publ, len);
}

void Book::set_year(int new_year)  {
	year = new_year;
}

void Book::set_pages(int new_pages)  {
	pages = new_pages;
}

void Book::set_name(char* new_name) {
	size_t len = strlen(new_name) +1;
	memcpy(name, new_name, len);
}

void Book::show_book()  {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Author: " << auth << std::endl;
	std::cout << "Publisher: " << publ << std::endl;
	std::cout << "Year of publishing: " << year << std::endl;
	std::cout << "Number of pages: " << pages << std::endl;
}

Book::Book(const Book& rhs) {
	year = rhs.year;
	pages = rhs.pages;

	size_t len;
	len = strlen(rhs.name)+1;
	name = new char[len];
	memcpy(name, rhs.name, len);

	len = strlen(rhs.auth)+1;
	auth = new char[len];
	memcpy(auth, rhs.auth, len);

	len = strlen(rhs.publ)+1;
	publ = new char[len];
	memcpy(publ, rhs.publ, len);
}

Book& Book::operator=(const Book& rhs) {
if (this == &rhs) {
	return *this;
	}

	delete[] name;
	delete[] auth;
	delete[] publ;

	size_t len;
	len = strlen(rhs.name)+1;
	name = new char[len];
	memcpy(name, rhs.name, len);

	len = strlen(rhs.auth)+1;
	auth = new char[len];
	memcpy(auth, rhs.auth, len);

	len = strlen(rhs.publ)+1;
	publ = new char[len];
	memcpy(publ, rhs.publ, len);

	year = rhs.year;
	pages = rhs.pages;

return *this;
}

Book::~Book() {
	delete[] name;
	delete[] auth;
	delete[] publ;
	}
