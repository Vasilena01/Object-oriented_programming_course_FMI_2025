#pragma once
#include <iostream>
#include <fstream>

class Vector
{
public:
	Vector();
	Vector(size_t size);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	Vector(Vector&& other);
	Vector& operator=(Vector&& other);
	~Vector();

	Vector& operator+=(const Vector& other);

	friend Vector operator*(double coef, const Vector& vector);

	size_t getSize() const;
	int& operator[](size_t index);
	int operator[](size_t index) const;
private:
	int* values;
	size_t size;

	void copyFrom(const Vector& other);
	void moveFrom(Vector&& other);
	void free();
};

Vector operator+(const Vector& lhs, const Vector& rhs);
int operator^(const Vector& lhs, const Vector& rhs);
bool operator==(const Vector& lhs, const Vector& rhs);
bool operator!=(const Vector& lhs, const Vector& rhs);