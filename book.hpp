
#ifndef BOOK_BOOK_HPP
#define BOOK_BOOK_HPP


class Book {
	
	public:
	Book();
	~Book();
	
	
	Book& operator=(const Book& rhs);
	Book(const Book& rhs);
	
	const char* get_auth() const;
	const char* get_name() const;
	const char* get_publ() const;
	const int get_year() const;
	const int get_pages() const;
	
	void set_auth(char* new_auth);
	void set_name(char* new_name);
	void set_publ(char* new_publ);
	void set_year(int new_year);
	void set_pages(int new_pages);
	
	void show_book();
	
	private:
	char* auth;
	char* name;
	char* publ;
	int year;
	int pages;
};

#endif //BOOK_BOOK_HPP
