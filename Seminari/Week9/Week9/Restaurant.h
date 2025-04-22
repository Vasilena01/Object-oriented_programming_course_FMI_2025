#pragma once
#include <iostream>
#include "Order.h"

class Restaurant
{
public:
	Restaurant() = default;
	Restaurant(const char* name, size_t cap);
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	Restaurant(Restaurant&& other);
	Restaurant& operator=(Restaurant&& other);
	~Restaurant();

	void addProduct(const MyString& product);
	bool receiveOrder(const Order& order);
	const char* getName() const;
private:
	char name[25];
	MyString* products;
	size_t size;
	size_t capacity;

	bool contains(const MyString& product);
	void resize(size_t newCap);
	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other);
	void free();
};