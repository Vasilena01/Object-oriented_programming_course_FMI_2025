#include "Book.h"

Book::Book(const char* name, size_t pageCount) : pageCount(pageCount)
{
	strcpy(this->name, name);
}

const char* Book::getName() const
{
	return name;
}

void Book::printBook() const
{
	std::cout << name << " " << pageCount << std::endl;
}
