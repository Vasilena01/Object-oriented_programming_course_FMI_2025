#include "TPeak.h"
#pragma warning (disable : 4996 )

TPeak::TPeak() : Peak()
{
    peakName = nullptr;
}

TPeak::TPeak(const char* mountainName, int height, const char* peakName) : Peak(mountainName, height)
{
    this->peakName = new char[strlen(peakName) + 1];
    strcpy(this->peakName, peakName);
}

TPeak::TPeak(const TPeak& other) : Peak(other)
{
    copyFrom(other);
}

TPeak& TPeak::operator=(const TPeak& other)
{
    if (this != &other) {
        Peak::operator=(other);

        free();
        copyFrom(other);
    }

    return *this;
}

TPeak::TPeak(TPeak&& other) : Peak(other)
{
    moveFrom(std::move(other));
}

TPeak& TPeak::operator=(TPeak&& other)
{
    if (this != &other) {
        Peak::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

TPeak::~TPeak()
{
    free();
}

void TPeak::printName() const
{
    std::cout << "TPeak name: " << peakName << std::endl;
}

const char* TPeak::getPeakName() const
{
    return peakName;
}

void TPeak::copyFrom(const TPeak& other)
{
    delete[] peakName;
    peakName = new char[strlen(other.peakName) + 1];
    strcpy(peakName, other.peakName);
}

void TPeak::moveFrom(TPeak&& other)
{
    peakName = other.peakName;
    other.peakName = nullptr;
}

void TPeak::free()
{
    delete[] peakName;
    peakName = nullptr;
}
