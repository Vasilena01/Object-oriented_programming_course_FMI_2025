#include "MyString.h"

MyString::MyString()
{
    data = nullptr;
    size = 0;
    capacity = 8;
}

MyString::MyString(const char* str)
{
    size = strlen(str);
    capacity = size * 2;
    data = new char[capacity];
}

MyString::MyString(const MyString& other)
{
    copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString::MyString(MyString&& other) noexcept
{
    moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

MyString::~MyString()
{
    free();
}

size_t MyString::length() const
{
    return size;
}

const char* MyString::c_str() const
{
    return data;
}

MyString& MyString::operator+=(const MyString& other)
{
    if (capacity < size + other.size + 1) {
        resize(size + other.size);
    }

    strncat(data, other.data, other.size);
    size += other.size;
    return *this;
}

char& MyString::operator[](int index)
{
    if (index > capacity)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

char MyString::operator[](int index) const
{
    if (index > capacity)
    {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

MyString::MyString(size_t strLen)
{
    data = new char[strLen];
    data[0] = '\0';
    capacity = strLen;
    size = 0;
}

void MyString::resize(size_t newSize)
{
    char* newData = new char[newSize];
    strcpy(newData, data);
    delete[] data;
    data = newData;
    capacity = newSize;
}

void MyString::copyFrom(const MyString& other)
{
    data = new char[other.capacity];
    strcpy(data, other.data);
    size = other.size;
    capacity = other.capacity;
}

void MyString::moveFrom(MyString&& other)
{
    data = other.data;
    other.data = nullptr;
    size = other.size;
    capacity = other.capacity;
}

void MyString::free()
{
    delete[] data;
}

MyString operator+(const MyString& rhs, const MyString& lhs)
{
    MyString result(rhs.length() + lhs.length());
    result += lhs;
    result += rhs;
    return result;
}

std::istream& operator<<(std::istream& ifs, MyString& str)
{
    size_t size = 0;
    ifs.read((char*)&size, sizeof(size));
    str.data = new char[size];
    ifs.read((char*)&str.data, size);
    return ifs;
}

void operator>>(std::ostream& ofs, const MyString& str)
{
    ofs << str.c_str();
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

void swap(MyString& lhs, MyString& rhs)
{
    MyString tmp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(tmp);
}
