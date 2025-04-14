#pragma once
#include <iostream>
#include <fstream>

class Statistics
{
public:
	Statistics();
	Statistics(size_t size);
	Statistics(const double* nums, size_t size);
	Statistics(const Statistics& other);
	Statistics& operator=(const Statistics& other);
	~Statistics();

	void load(const char* filename);
	double min() const;
	double printAvg() const;
	void print() const;
	Statistics& combine(const Statistics& other);
private:
	double* arr;
	size_t size;

	void copyFrom(const Statistics& other);
	void free();
	void resize(size_t newSize);
	size_t getElCount(std::ifstream& file);
};

