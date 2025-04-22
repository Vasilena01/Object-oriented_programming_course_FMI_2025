#include "Restaurant.h"

Restaurant::Restaurant(const char* name, size_t cap)
{
    strncpy(this->name, name, 25);
    this->name[24] = '\0';
    products = new MyString[cap];
    size = 0;
    capacity = cap;
}

Restaurant::Restaurant(const Restaurant& other)
{
    copyFrom(other);
}

Restaurant& Restaurant::operator=(const Restaurant& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Restaurant::Restaurant(Restaurant&& other)
{
    moveFrom(std::move(other));
}

Restaurant& Restaurant::operator=(Restaurant&& other)
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Restaurant::~Restaurant()
{
    free();
}

void Restaurant::addProduct(const MyString& product)
{
    if (size == capacity) {
        resize(capacity * 2);
    }

    products[size++] = product;
}

bool Restaurant::receiveOrder(const Order& order)
{
    for (int i = 0; i < order.getProductsCount(); i++)
    {
        MyString currProduct = order.getProducts()[i];
        if (!contains(currProduct)) {
            throw std::exception("The restaurant don't have the current product");
            return false;
        }
    }

    if (strcmp(order.getRestaurant(), name) != 0) {
        throw std::exception("The order's restaurant name is not the same as the curr restaurant name");
        return false;
    }
    return true;
}

const char* Restaurant::getName() const
{
    return name;
}

bool Restaurant::contains(const MyString& product)
{
    for (int i = 0; i < size; i++)
    {
        if (product == products[i]) {
            return true;
        }
    }
    return false;
}

void Restaurant::resize(size_t newCap)
{
    MyString* newProducts = new MyString[newCap];
    for (int i = 0; i < size; i++)
    {
        newProducts[i] = products[i];
    }

    delete[] products;
    products = newProducts;
    capacity = newCap;
}

void Restaurant::copyFrom(const Restaurant& other)
{
    strcpy(name, other.name);
    products = new MyString[other.capacity];
    for (int i = 0; i < other.size; i++)
    {
        products[i] = other.products[i];
    }
    size = other.size;
    capacity = other.capacity;
}

void Restaurant::moveFrom(Restaurant&& other)
{
    products = other.products;
    other.products = nullptr;
    strcpy(name, other.name);
    size = other.size;
    capacity = other.capacity;
}

void Restaurant::free()
{
    delete[] products;
}
