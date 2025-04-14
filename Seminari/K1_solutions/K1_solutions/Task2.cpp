#include "Task2.h"

Statistics::Statistics() : Statistics(4)
{
}

Statistics::Statistics(size_t size)
{
    this->arr = new double[size];
    for (int i = 0; i < size; i++)
    {
        this->arr[i] = 0;
    }
    this->size = size;
}

Statistics::Statistics(const double* nums, size_t size)
{
    if (nums == nullptr)
        return;

    this->arr = new double[size];
    for (int i = 0; i < size; i++)
    {
        this->arr[i] = nums[i];
    }
    this->size = size;
}

Statistics::Statistics(const Statistics& other)
{
    copyFrom(other);
}

Statistics& Statistics::operator=(const Statistics& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Statistics::~Statistics()
{
    free();
}

void Statistics::load(const char* filename)
{
    if (filename == nullptr)
        return;

    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Can't open file");
    }

    this->size = getElCount(file) + 1;
    delete[] this->arr;
    this->arr = new double[this->size];

    for (int i = 0; i < this->size; i++)
    {
        file >> this->arr[i];
    }
    
}

double Statistics::min() const
{
    double minValue = INT_MAX;

    for (int i = 0; i < this->size; i++)
    {
        if (this->arr[i] < minValue)
        {
            minValue = this->arr[i];
        }
    }

    return minValue;
}

double Statistics::printAvg() const
{
    if (this->size == 0)
        return 0;

    double sum = 0;
    for (int i = 0; i < this->size; i++)
    {
        sum += this->arr[i];
    }

    sum / this->size;
}

void Statistics::print() const
{
    for (int i = 0; i < this->size; i++)
    {
        std::cout << this->arr[i] << " ";
    }
}

Statistics& Statistics::combine(const Statistics& other)
{
    size_t oldSize = this->size;
    size_t newSize = this->size + other.size;
    resize(newSize);

    for (int i = 0; i < newSize; i++)
    {
        this->arr[i + oldSize] = other.arr[i];
    }

    return *this;
}

void Statistics::copyFrom(const Statistics& other)
{
    this->arr = new double[other.size];
    for (int i = 0; i < other.size; i++)
    {
        this->arr[i] = other.arr[i];
    }
    this->size = other.size;
}

void Statistics::free()
{
    delete[] this->arr;
}

void Statistics::resize(size_t newSize)
{
    double* newArr = new double[newSize];
    for (int i = 0; i < newSize; i++)
    {
        newArr[i] = this->arr[i];
    }

    delete[] this->arr;
    this->arr = newArr;
    this->size = newSize;
}

size_t Statistics::getElCount(std::ifstream& file)
{
    size_t currPos = file.tellg();
    int counter = 0;

    while (!file.eof())
    {
        char ch;
        file.get(ch);

        if (ch == ' ')
            counter++;
    }

    file.clear();
    file.seekg(currPos);
    return counter;
}
