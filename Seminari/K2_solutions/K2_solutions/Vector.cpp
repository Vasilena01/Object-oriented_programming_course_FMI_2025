#include "Vector.h"

Vector::Vector()
{
	size = 0;
	values = nullptr;
}

Vector::Vector(size_t size) : size(size)
{
	this->values = new int[size];
}

Vector::Vector(const Vector& other)
{
	copyFrom(other);
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Vector::Vector(Vector&& other)
{
	moveFrom(std::move(other));
}

Vector& Vector::operator=(Vector&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Vector::~Vector()
{
	free();
}

Vector& Vector::operator+=(const Vector& other)
{
	if (size != other.size) {
		throw std::logic_error("Both vectors should have equal sizes");
	}

	for (int i = 0; i < size; i++) {
		values[i] += other.values[i];
	}

	return *this;
}

size_t Vector::getSize() const
{
	return size;
}

int& Vector::operator[](size_t index)
{
	if (index >= size) {
		throw std::exception("Index out of range");
	}

	return values[index];
}

int Vector::operator[](size_t index) const
{
	if (index >= size) {
		throw std::exception("Index out of range");
	}

	return values[index];
}

void Vector::copyFrom(const Vector& other)
{
	values = new int[other.size];

	for (int i = 0; i < other.size; i++) {
		values[i] = other.values[i];
	}

	size = other.size;
}

void Vector::moveFrom(Vector&& other)
{
	values = other.values;
	other.values = nullptr;
	size = other.size;
	other.size = 0;
}

void Vector::free()
{
	delete[] values;
	values = nullptr;
	size = 0;
}

Vector operator*(double coef, const Vector& vector)
{
	Vector newVector(vector);

	for (int i = 0; i < vector.size; i++) {
		newVector[i] *= coef;
	}

	return newVector;
}

Vector operator+(const Vector& lhs, const Vector& rhs)
{
	Vector newVector(lhs);
	newVector += rhs;
	return newVector;
}

int operator^(const Vector& lhs, const Vector& rhs)
{
	if (lhs.getSize() != rhs.getSize()) {
		throw std::exception("Both vectors should have the same sizes");
	}

	int res = 0;
	for (int i = 0; i < lhs.getSize(); i++) {
		res += lhs[i] * rhs[i];
	}

	return res;
}

bool operator==(const Vector& lhs, const Vector& rhs)
{
	if (lhs.getSize() != rhs.getSize()) {
		throw std::exception("Both vectors should have the same sizes");
	}

	for (int i = 0; i < lhs.getSize(); i++) {
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}

	return true;
}

bool operator!=(const Vector& lhs, const Vector& rhs)
{
	return !(lhs == rhs);
}