#include "Order.h"

Order::Order()
{
    restaurant = nullptr;
    products = nullptr;
    productsCount = 0;
    capacity = 8;
    totalProductsLen = 0;
}

Order::Order(const char* restaurant)
{
    this->restaurant = new char[strlen(restaurant) + 1];
    products = nullptr;
    productsCount = 0;
    capacity = 8;
    totalProductsLen = 0;
}

Order::Order(const Order& other)
{
    copyFrom(other);
}

Order& Order::operator=(const Order& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Order::Order(Order&& other)
{
    moveFrom(std::move(other));
}

Order& Order::operator=(Order&& other)
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Order::~Order()
{
    free();
}

void Order::addProduct(const MyString& product)
{
    if (productsCount == capacity) {
        resize(capacity * 2);
    }

    totalProductsLen += product.length();
    products[productsCount++] = product;
}

double Order::calculateDeliveryTime()
{
    return totalProductsLen + productsCount;
}

const char* Order::getRestaurant() const
{
    return restaurant;
}

const MyString* Order::getProducts() const
{
    return products;
}

unsigned Order::getProductsCount() const
{
    return productsCount;
}

void Order::setRestaurant(const char* name)
{
    delete[] restaurant;
    restaurant = new char[strlen(name) + 1];
    strcpy(restaurant, name);
}

void Order::resize(unsigned newCap)
{
    MyString* newProducts = new MyString[newCap];
    for (int i = 0; i < productsCount; i++)
    {
        newProducts[i] = products[i];
    }
    delete[] products;
    products = newProducts;
    capacity = newCap;
}

void Order::copyFrom(const Order& other)
{
    restaurant = new char[strlen(other.restaurant) + 1];
    products = new MyString[other.capacity];
    strcpy(restaurant, other.restaurant);
    for (int i = 0; i < other.productsCount; i++)
    {
        products[i] = other.products[i];
    }
    productsCount = other.productsCount;
    capacity = other.capacity;
    totalProductsLen = other.totalProductsLen;
}

void Order::moveFrom(Order&& other)
{
    restaurant = other.restaurant;
    other.restaurant = nullptr;
    products = other.products;
    other.products = nullptr;
    productsCount = other.productsCount;
    capacity = other.capacity;
    totalProductsLen = other.totalProductsLen;
}

void Order::free()
{
    delete[] restaurant;
    delete[] products;
}
