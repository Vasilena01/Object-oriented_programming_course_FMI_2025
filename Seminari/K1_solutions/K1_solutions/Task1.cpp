#include "Task1.h"

Polynom::Polynom() : Polynom(8)
{}

Polynom::Polynom(size_t size)
{
	setSize(size);
	this->coeficients = new int[this->size];
	for (int i = 0; i < size; i++)
	{
		this->coeficients[i] = 1;
	}
}

Polynom::Polynom(const int* coef, size_t size)
{
	if (!coef)
	{
		return;
	}

	this->coeficients = new int[size];
	setSize(size);

	for (int i = 0; i < size; i++)
	{
		this->coeficients[i] = coef[i];
	}
}

Polynom::Polynom(const Polynom& other)
{
	copyFrom(other);
}

Polynom& Polynom::operator=(const Polynom& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Polynom::~Polynom()
{
	free();
}

size_t Polynom::getSize() const
{
	return size;
}

void Polynom::setSize(size_t newSize)
{
	this->size = newSize;
}

void Polynom::load(const char* filename)
{
	std::ifstream file(filename);

	if (!file.is_open()) {
		throw std::runtime_error("Can't open file");
	}

	this->size = getCoefCount(file);
	delete[] this->coeficients;
	this->coeficients = new int[this->size];
	for(int i = 0; i < this->size; i++)
	{
		file >> this->coeficients[i];
	}
}

Polynom& Polynom::add(const Polynom& other)
{
	size_t maxSize = std::max(this->size, other.size);
	if (maxSize > this->size)
	{
		resize(maxSize);
	}

	for (int i = 0; i < maxSize; i++)
	{
		if (i < other.size) {
			this->coeficients[i] += other.coeficients[i];
		}
	}

	return *this;
}

void Polynom::print() const
{
	if (this->size == 0) {
		throw std::exception("Nothing to print");
	}

	bool isFirst = false;
	for (int i = 0; i < this->size; i++)
	{
		if (!isFirst) {
			std::cout << this->coeficients[i] << "*x^" << i;
			isFirst = true;
		}
		else if (i != 0) {
			std::cout << " + " << this->coeficients[i] << "*x^" << i;
		}
		else
		{
			std::cout << " + " << this->coeficients[i];
		}
	}
}

void Polynom::copyFrom(const Polynom& other)
{
	this->size = other.size;
	this->coeficients = new int[other.size];
	for (int i = 0; i < this->size; i++)
	{
		this->coeficients[i] = other.coeficients[i];
	}
}

void Polynom::free()
{
	delete[] this->coeficients;
}

void Polynom::resize(size_t newSize)
{
	int* newCoef = new int[newSize];
	for (int i = 0; i < newSize; i++)
	{
		newCoef[i] = this->coeficients[i];
	}

	setSize(newSize);
	delete[] this->coeficients;
	this->coeficients = newCoef;
}

size_t Polynom::getCoefCount(std::ifstream& file)
{
	int currPos = file.tellg();
	int charCount = 0;

	while (!file.eof())
	{
		char ch;
		file.get(ch);

		if (ch == '\n')
		{
			charCount++;
		}
	}

	file.clear();
	file.seekg(currPos);
	return charCount;
}
