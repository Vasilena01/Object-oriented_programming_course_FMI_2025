#pragma once
#include <iostream>
#pragma warning (disable : 4996)
namespace CONSTANTS
{
	constexpr int bookNameSize = 256;
};

class Book
{
public:
	Book() = default;
	Book(const char* name, size_t pageCount);
	const char* getName() const;
	void printBook() const;
private:
	char name[CONSTANTS::bookNameSize];
	size_t pageCount;
};

