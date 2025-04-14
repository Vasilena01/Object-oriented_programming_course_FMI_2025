#pragma once
#include <iostream>
#include <fstream>

class Polynom
{
public:
	Polynom();
	Polynom(size_t size);
	Polynom(const int* coef, size_t size);
	Polynom(const Polynom& other);
	Polynom& operator=(const Polynom& other);
	~Polynom();

	size_t getSize() const;
	void setSize(size_t newSize);

	void load(const char* filename);
	Polynom& add(const Polynom& other);
	void print() const;
private:
	int* coeficients;
	size_t size;

	void copyFrom(const Polynom& other);
	void free();
	void resize(size_t newSize);
	size_t getCoefCount(std::ifstream& file);
};

