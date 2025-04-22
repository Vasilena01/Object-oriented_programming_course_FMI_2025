#pragma once
#include "Restaurant.h"

class FoodPanda
{
public:
	FoodPanda(size_t newCap);
	FoodPanda(const FoodPanda& other);
	FoodPanda& operator=(const FoodPanda& other);
	FoodPanda(FoodPanda&& other);
	FoodPanda& operator=(FoodPanda&& other);
	~FoodPanda();

	void addRestaurant(const Restaurant& restaurant);
	void addProductToRestaurant(const MyString& product, Restaurant& restaurant);
	void addOrderToRestaurant(const Order& order);
private:
	Restaurant* restaurants;
	size_t size;
	size_t capacity;

	Restaurant& getRestaurantByName(const char* name);
	void resize(size_t newCap);
	void copyFrom(const FoodPanda& other);
	void moveFrom(FoodPanda&& other);
	void free();
};

