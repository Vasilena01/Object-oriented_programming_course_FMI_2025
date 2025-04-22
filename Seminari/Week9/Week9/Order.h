#pragma once
#include <iostream>
#include "MyString.h"
#pragma warning ( disable: 4996)

class Order
{
public:
	Order();
	Order(const char* restaurant);
	Order(const Order& other);
	Order& operator=(const Order& other);
	Order(Order&& other);
	Order& operator=(Order&& other);
	~Order();

	void addProduct(const MyString& product);
	double calculateDeliveryTime();

	const char* getRestaurant() const;
	const MyString* getProducts() const;
	unsigned getProductsCount() const;
	void setRestaurant(const char* name);
private:
	char* restaurant;
	MyString* products;
	unsigned productsCount;
	unsigned capacity;
	unsigned totalProductsLen;

	void resize(unsigned newCap);
	void copyFrom(const Order& other);
	void moveFrom(Order&& other);
	void free();
};

