
#pragma once
#include <iostream>
#pragma warning ( disable: 4996)

class MyString
{
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;
	~MyString();

	size_t length() const;
	const char* c_str() const;
	MyString& operator+=(const MyString& other);
	char& operator[](int index);
	char operator[](int index) const;

	friend MyString operator+(const MyString& rhs, const MyString& lhs);
	friend std::istream& operator<<(std::istream& ifs, MyString& str);
private:
	char* data;
	size_t size;
	size_t capacity;

	explicit MyString(size_t strLen);
	void resize(size_t newSize);
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();
};

void operator>>(std::ostream& ofs, const MyString& str);

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);

void swap(MyString& lhs, MyString& rhs);