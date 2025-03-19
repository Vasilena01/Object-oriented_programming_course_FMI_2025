#pragma once
#include "Book.h"

class Library
{
public:
	Library();
	Library(const Library& other);
	Library& operator=(const Library& other);
	~Library();

	void addBook(const Book& newBook);
	void addBook(const char* name, size_t pageCount);
	void removeBookByName(const char* bookName);
	void removeBookByIndex(int index);
	void printLibrary() const;
private:
	Book* books;
	size_t size;
	size_t capacity;

	void copyFrom(const Library& other);
	void resize(size_t newCapacity);
	void free();
};