#include "Zad6.h"

Category getCategoryFromId(unsigned id)
{
	switch(id)
	{
	case 1: return Category::ELECTRONICS; break;
	case 2: return Category::CLOTHING; break;
	case 3: return Category::BOOKS; break;
	case 4: return Category::FOOD; break;
	case 5: return Category::BEAUTY; break;
	default: std::cout << "Unavailable category!"; break;
	}
}

void printCategory(const Category& category)
{
	switch (category)
	{
	case Category::ELECTRONICS: std::cout << "Electronics"; break;
	case Category::CLOTHING: std::cout << "Clothing"; break;
	case Category::BOOKS: std::cout << "Books"; break;
	case Category::FOOD: std::cout << "Food"; break;
	case Category::BEAUTY: std::cout << "Beauty"; break;
	default: return;
	}
}

size_t getFileSize(std::ifstream& file)
{
	size_t curr = file.tellg();
	file.seekg(0, std::ios::end);
	size_t size = file.tellg();
	file.seekg(curr);
	return size;
}

Product getProductInput()
{
	Product product;
	std::cin >> product.name >> product.availableQuantity >> product.price;
	int categoryId;
	std::cin >> categoryId;
	product.category = getCategoryFromId(categoryId);
	std::cin >> product.shipping;
	return product;
}

void readProductsFromFile(const char* filename, Product*& products, size_t& productsCount)
{
	std::ifstream file(filename, std::ios::binary);
	if (!file.is_open())
		return;

	size_t fileSize = getFileSize(file);
	productsCount = fileSize / sizeof(Product);
	products = new Product[productsCount];

	file.read((char*)products, fileSize);
}

void writeProductsToFile(const char* filename, const Product* products, size_t productsCount)
{
	std::ofstream file(filename, std::ios::binary);
	if (!file.is_open())
		return;

	file.write((const char*)products, productsCount * sizeof(Product));
}

void writeProductsFromTheConsoleToFile(const char* filename, size_t productsSize)
{
	std::ofstream file(filename, std::ios::binary);
	if (!file.is_open())
		return;

	for (int i = 0; i < productsSize; i++)
	{
		Product newProduct = getProductInput();
		file.write((const char*)&newProduct, sizeof(Product));
	}
}

void writeProductsFromCertainCategoryToFile(const char* filename, const Category& category, const Product* products, size_t size)
{
	std::ofstream file(filename, std::ios::binary);
	if (!file.is_open())
		return;

	for (int i = 0; i < size; i++)
	{
		if (category == products[i].category)
		{
			file.write((const char*)&products[i], sizeof(Product));
		}
	}
}

void changeQuantityInfo(const char* filename, Product* products, const char* prname, unsigned newQuantity, size_t productsSize)
{
	for (int i = 0; i < productsSize; i++)
	{
		if (strcmp(products[i].name, prname) == 0)
		{
			products[i].availableQuantity = newQuantity;
			break;
		}
	}

	writeProductsToFile(filename, products, productsSize);
}

void printProduct(const Product& product)
{
	std::cout << "Name: " << product.name << " ";
	std::cout << "Availability: " << product.availableQuantity << " ";
	std::cout << "Price: " << product.price << " ";
	std::cout << "Category: ";
	printCategory(product.category);
	std::cout << " ";
	std::cout << "Shipping: " << product.shipping << " ";
}

void printProducts(const Product* products, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		printProduct(products[i]);
		std::cout << std::endl;
	}
}

void printProductByName(const Product* products, const char* name, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		if(strcmp(products[i].name, name) == 0)
			printProduct(products[i]);
		std::cout << std::endl;
	}
}

void input6()
{
	char filename[CONSTANTS::DEFAULT_MAX_SIZE] = "products.dat";
	size_t productsSize = 2;

	//writeProductsFromTheConsoleToFile(filename, productsSize);
	Product* products;
	size_t newProductsSize = 0;
	readProductsFromFile(filename, products, newProductsSize);
	printProducts(products, newProductsSize);

	changeQuantityInfo(filename, products, "laptop", 543, newProductsSize);
	//printProducts(products, newProductsSize);
	//printProductByName(products, "pc", newProductsSize);

	char secondFilename[CONSTANTS::DEFAULT_MAX_SIZE] = "productsFromCategory.dat";
	writeProductsFromCertainCategoryToFile(secondFilename, Category::ELECTRONICS, products, newProductsSize);
	Product* productsByCategory;
	size_t productsSize3 = 0;
	readProductsFromFile(secondFilename, productsByCategory, productsSize3);
	printProducts(productsByCategory, productsSize3);
}