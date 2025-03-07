#pragma once
#include <iostream>
#include <fstream>

namespace CONSTANTS
{
	constexpr int DEFAULT_MAX_SIZE = 100;
}

enum Category
{
	ELECTRONICS = 1, 
	CLOTHING, 
	BOOKS, 
	FOOD,
	BEAUTY
};

struct Product
{
	char name[CONSTANTS::DEFAULT_MAX_SIZE];
	unsigned availableQuantity;
	double price;
	Category category;
	char shipping[CONSTANTS::DEFAULT_MAX_SIZE];
};

Category getCategoryFromId(unsigned id);
void printCategory(const Category& category);
size_t getFileSize(std::ifstream& file);
Product getProductInput();
void readProductsFromFile(const char* filename, Product*& products, size_t& productsCount);
void writeProductsToFile(const char* filename, const Product* products, size_t productsCount);
void writeProductsFromTheConsoleToFile(const char* filename, size_t productsSize);
void changeQuantityInfo(Product* products, const char* prname, unsigned newQuantity, size_t productsSize);
void printProduct(const Product& product);
void printProducts(const Product* products, size_t size);
void printProductByName(const Product* products, const char* name, size_t size);
void writeProductsFromCertainCategoryToFile(const char* filename, const Category& category, const Product* products, size_t size);
void input6();