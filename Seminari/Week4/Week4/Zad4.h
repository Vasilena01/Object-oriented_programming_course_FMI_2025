#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#pragma warning (disable : 4996)

namespace CONSTANTS
{
	constexpr int BRAND_NAME_SIZE = 1024;
	constexpr int ALCHOHOL_NAME_SIZE = 128;
	constexpr int BALOON_COUNT = 1024;
	constexpr int ALCHOHOL_COUNT = 512;
	constexpr int NARGA_COUNT = 256;
}

enum class Color
{
	WHITE = 1,
	GREEN,
	RED
};

enum class Taste
{
	BLUEBERRY = 1,
	QUEEN,
	MANGO,
	MELON,
	BERRY
};

class Baloon
{
public:
	Baloon();
	Baloon(unsigned price, int colorIndx);
	void createBaloonFromFile(const char* filename);

	unsigned getPrice() const;
	Color getColor() const;
	size_t getCount() const;
	void setPrice(unsigned newPrice);
	void setColor(int index);
	void setCount(size_t count);

	void printBaloon();
private:
	unsigned price;
	Color color;
	size_t count = 0;

	Color getColorByIndex(int index);
	void printColor(const Color& color);
	int convertStringToColorToIndex(const char* colorStr);
};

class Narga
{
public:
	Narga();
	Narga(unsigned price, const char* brandName, int tasteIndx);
	void initDataFromConsole();
	void createNargaFromFile(const char* filename);
	void printNarga();

	unsigned getPrice() const;
	const char* getBrandName() const;
	Taste getTaste() const;
	size_t getCount() const;

	void setPrice(unsigned newPrice);
	void setBrandName(const char* newName);
	void setTaste(int index);
	void setCount(size_t count);
private:
	unsigned price;
	char brandName[CONSTANTS::BRAND_NAME_SIZE];
	Taste taste;
	size_t count = 0;

	Taste getTasteFromIndex(int index);
	void printTaste(const Taste& taste);
	int convertStringToTasteIndex(const char* tasteStr);
};

class Alchohol
{
public:
	Alchohol();
	Alchohol(double price, const char* name);
	void createAlchoholFromFile(const char* filename);

	double getPrice() const;
	const char* getName() const;
	size_t getCount() const;

	void setPrice(double newPrice);
	void setName(const char* newName);
	void setCount(size_t count);

	void printAlchohol();
private:
	char name[CONSTANTS::ALCHOHOL_NAME_SIZE];
	double price;
	size_t count = 0;
};

class NightClub
{
public:
	void addBaloon(Baloon& newBaloon);
	void addAlchohol(Alchohol& newAlchohol);
	void addNarga(Narga& newNarga);
	
	void removeBaloonFromArr(Baloon& baloon);
	void removeAlchoholFromArr(Alchohol& alchohol);
	void removeNargaFromArr(Narga& narga);

	int findBaloonIndexByColor(const Color& color);
	int findNargaIndexByNameTaste(const char* brandName, const Taste& taste);
	int findAlchoholIndexByName(const char* name);

	void removeBaloonByColor(const Color& color);
	void removeNargaByNameTaste(const char* brandName, const Taste& taste);
	void removeAlchoholByName(const char* name);

	void printBaloonsArr();
	void printBottlesArr();
	void printNargasArr();
private:
	Baloon baloons[CONSTANTS::BALOON_COUNT];
	Alchohol bottles[CONSTANTS::ALCHOHOL_COUNT];
	Narga nargas[CONSTANTS::NARGA_COUNT];
	size_t baloonsCount = 0;
	size_t bottlesCount = 0;
	size_t nargasCount = 0;
};

