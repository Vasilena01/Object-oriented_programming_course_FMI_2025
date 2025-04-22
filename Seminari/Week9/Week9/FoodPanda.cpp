#include "FoodPanda.h"

FoodPanda::FoodPanda(size_t newCap)
{
    restaurants = new Restaurant[newCap];
    capacity = newCap;
    size = 0;
}

FoodPanda::FoodPanda(const FoodPanda& other)
{
    copyFrom(other);
}

FoodPanda& FoodPanda::operator=(const FoodPanda& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

FoodPanda::FoodPanda(FoodPanda&& other)
{
    moveFrom(std::move(other));
}

FoodPanda& FoodPanda::operator=(FoodPanda&& other)
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

FoodPanda::~FoodPanda()
{
    free();
}

void FoodPanda::addRestaurant(const Restaurant& restaurant)
{
    if (size == capacity) {
        resize(capacity * 2);
    }

    restaurants[size++] = restaurant;
}

void FoodPanda::addProductToRestaurant(const MyString& product, Restaurant& restaurant)
{
    restaurant.addProduct(product);
}

void FoodPanda::addOrderToRestaurant(const Order& order)
{
    const char* restaurantName = order.getRestaurant();
    Restaurant& restaurant = getRestaurantByName(restaurantName);
    restaurant.receiveOrder(order);
}

Restaurant& FoodPanda::getRestaurantByName(const char* name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(restaurants[i].getName(), name) == 0)
        {
            return restaurants[i];
        }
    }
    throw std::exception("No restaurant found with this name");
}

void FoodPanda::resize(size_t newCap)
{
    Restaurant* newRestaurants = new Restaurant[newCap];
    for (int i = 0; i < size; i++)
    {
        newRestaurants[i] = restaurants[i];
    }

    delete[] restaurants;
    restaurants = newRestaurants;
    capacity = newCap;
}

void FoodPanda::copyFrom(const FoodPanda& other)
{
    restaurants = new Restaurant[other.capacity];
    for (int i = 0; i < other.size; i++)
    {
        restaurants[i] = other.restaurants[i];
    }
    size = other.size;
    capacity = other.capacity;
}

void FoodPanda::moveFrom(FoodPanda&& other)
{
    restaurants = other.restaurants;
    other.restaurants = nullptr;
    size = other.size;
    capacity = other.capacity;
}

void FoodPanda::free()
{
    delete[] restaurants;
}
