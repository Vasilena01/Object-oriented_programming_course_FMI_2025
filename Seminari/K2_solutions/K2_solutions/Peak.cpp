#include "Peak.h"
#pragma warning (disable : 4996 )

Peak::Peak()
{
    mountainName = nullptr;
    height = 0;
}

Peak::Peak(const char* name, unsigned height) : height(height)
{
    mountainName = new char[strlen(name) + 1];
    strcpy(mountainName, name);
}

Peak::Peak(const Peak& other)
{
    copyFrom(other);
}

Peak& Peak::operator=(const Peak& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Peak::Peak(Peak&& other)
{
    moveFrom(std::move(other));
}

Peak& Peak::operator=(Peak&& other)
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

Peak::~Peak()
{
    free();
}

void Peak::printName() const
{
}

unsigned Peak::getHeight() const
{
    return height;
}

const char* Peak::getMountainName() const
{
    return mountainName;
}

void Peak::copyFrom(const Peak& other)
{
    delete[] mountainName;
    mountainName = new char[strlen(other.mountainName) + 1];
    strcpy(mountainName, other.mountainName);
    height = other.height;
}

void Peak::moveFrom(Peak&& other)
{
    mountainName = other.mountainName;
    other.mountainName = nullptr;
    height = other.height;
    other.height = 0;
}

void Peak::free()
{
    delete[] mountainName;
    mountainName = nullptr;
    height = 0;
}
