#include "Library.h"

Library::Library()
{
    capacity = 1;
    size = 0;
    books = new Book[capacity];
}

Library::Library(const Library& other)
{
    copyFrom(other);
}

Library& Library::operator=(const Library& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Library::~Library()
{
    free();
}

void Library::addBook(const Book& newBook)
{
    if (size == capacity)
        resize(size * 2);

    books[size] = newBook;
    size++;
}

void Library::addBook(const char* name, size_t pageCount)
{
    Book newBook(name, pageCount);
    addBook(newBook);
}

void Library::removeBookByName(const char* bookName)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(bookName, books[i].getName()) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        throw std::exception("No book with the given name was found");
    }

    removeBookByIndex(index);
}

void Library::removeBookByIndex(int index)
{
    if (index >= size || index >= capacity)
    {
        throw std::out_of_range("Index out of range");
    }

    for (int i = index + 1; i < size; i++)
    {
        books[i - 1] = books[i];
    }
    size--;
}

void Library::printLibrary() const
{
    for (int i = 0; i < size; i++)
    {
        books[i].printBook();
    }
}

void Library::copyFrom(const Library& other)
{
    books = new Book[other.size];
    for (int i = 0; i < other.size; i++)
    {
        books[i] = other.books[i];
    }
    capacity = other.capacity;
    size = other.size;
}

void Library::resize(size_t newCapacity)
{
    Book* newBooks = new Book[newCapacity];
    for (int i = 0; i < size; i++)
    {
        newBooks[i] = books[i];
    }
    delete[] books;
    books = newBooks;
    capacity = newCapacity;
}

void Library::free()
{
    delete[] books;
}
