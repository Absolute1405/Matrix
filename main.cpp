#include <iostream>
#include "book.hpp"
#include "book.cpp"

void set_book(Book Book1) {
	char* input = new char;
	std::cout << "Input book name " << std::endl;
	std::cin >> input;
	Book1.set_name(input);

	std::cout << "Input author name " << std::endl;
	std::cin >> input;
	Book1.set_auth(input);

	std::cout << "Input publisher name " << std::endl;
	std::cin >> input;
	Book1.set_publ(input);

	delete[] input;
	int num;

	std::cout << "Input year of publishing " << std::endl;
	std::cin >> num;
	Book1.set_year(num);

	std::cout << "Input number of pages " << std::endl;
	std::cin >> num;
	Book1.set_pages(num);
	}

void set_shelf(Book* Shelf, int number) {
	int i;

	for (i=0; i<=number; i++) {
		set_book(Shelf[i]);
		}
	}

void author_list(Book* Shelf, char* auth_name, int number) {
	int i;

	for (i=0; i<=number; i++) {
		if (Shelf[i].get_auth() == auth_name) {
			std::cout << Shelf[i].get_name();
			}
		}
	std::cout << std::endl;
	}

void publ_list(Book* Shelf, char* publ_name, int number) {
	int i;

	for(i=0; i<=number; i++) {
		if (Shelf[i].get_publ() == publ_name) {
			std::cout << Shelf[i].get_name();
			}
		}
	std::cout << std::endl;
	}

void year_list(Book* Shelf, int year, int number) {
	int i;

	for(i=0; i<=number; i++) {
		if (Shelf[i].get_year() > year) {
			std::cout << Shelf[i].get_name();
			}
		}
	std::cout << std::endl;
	}


int main() {
	Book* Shelf =  new Book;
	int number;
	int k=0;
	char* _name;
	int ye;
	std::cout<< "Input number of books " << std::endl;
	std::cin >> number;

	set_shelf(Shelf, number);

	std::cout<<"Press 1 to search by author, Press 2 to search by publisher, Press 3 to search by year" << std::endl;
	std::cin>>k;

	if (k==1) {
			std::cout<< "Input author name for searching:" << std::endl;
			std::cin>>_name;
			author_list(Shelf, _name, number);
	}

	if (k==2) {
			std::cout<< "Input publisher name for searching:" << std::endl;
			std::cin>>_name;
			publ_list(Shelf, _name, number);
	}

	if (k==1) {
			std::cout<< "Input year for searching:" << std::endl;
			std::cin>>ye;
			year_list(Shelf, ye, number);
	}

	return 0;
	}
