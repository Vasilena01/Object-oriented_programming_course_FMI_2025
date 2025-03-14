#include "Zad4.h"

/* Baloon */
Baloon::Baloon()
{
	setPrice(0);
	setColor(1);
	this->count = 0;
}

Baloon::Baloon(unsigned price, int colorIndx)
{
	setPrice(price);
	setColor(colorIndx);
}

void Baloon::createBaloonFromFile(const char* filename)
{
	std::ifstream file(filename);

	if (!file.is_open())
		return;

	char buff[1024];

	file.getline(buff, sizeof(buff));
	std::stringstream ss(buff);

	char colorname[CONSTANTS::ALCHOHOL_NAME_SIZE];
	ss.getline(colorname, CONSTANTS::ALCHOHOL_NAME_SIZE, '-');
	int colorIndex = convertStringToColorToIndex(colorname);
	setColor(colorIndex);

	unsigned price = 0;
	ss >> price;
	setPrice(price);

	file.close();
}

unsigned Baloon::getPrice() const
{
	return this->price;
}

Color Baloon::getColor() const
{
	return this->color;
}

size_t Baloon::getCount() const
{
	return this->count;
}

void Baloon::setPrice(unsigned newPrice)
{
	this->price = newPrice;
}

void Baloon::setColor(int index)
{
	Color newColor = getColorByIndex(index);
	this->color = newColor;
}

void Baloon::setCount(size_t count)
{
	this->count = count;
}

void Baloon::printBaloon()
{
	std::cout << "Baloon: " << this->getPrice() << " ";
	printColor(this->getColor());
	std::cout << std::endl;
}

Color Baloon::getColorByIndex(int index)
{
	switch (index)
	{
	case 1: return Color::WHITE; break;
	case 2: return Color::GREEN; break;
	case 3: return Color::RED; break;
	default: return Color::WHITE; break;
	}
}

void Baloon::printColor(const Color& color)
{
	switch (color)
	{
	case Color::WHITE: std::cout << "White"; break;
	case Color::GREEN: std::cout << "Green"; break;
	case Color::RED: std::cout << "Red"; break;
	default: std::cout << "White"; break;
	}
}

int Baloon::convertStringToColorToIndex(const char* colorStr)
{
	char upperStr[256];
	for (size_t i = 0; colorStr[i] != '\0'; ++i) {
		upperStr[i] = toupper(colorStr[i]);
	}
	upperStr[strlen(colorStr)] = '\0';

	if (strcmp(upperStr, "WHITE") == 0) return static_cast<int>(Color::WHITE);
	if (strcmp(upperStr, "GREEN") == 0) return static_cast<int>(Color::GREEN);
	if (strcmp(upperStr, "RED") == 0) return static_cast<int>(Color::RED);

	return -1;
}

/* Narga */
Narga::Narga()
{
	setPrice(0);
	setBrandName("");
	setTaste(1);
	this->count = 0;
}

Narga::Narga(unsigned price, const char* brandName, int tasteIndx)
{
	setPrice(price);
	setBrandName(brandName);
	setTaste(tasteIndx);
}

void Narga::initDataFromConsole()
{
	std::cin >> this->price;
	std::cin >> this->brandName;
	int taste;
	std::cin >> taste;
	setTaste(taste);
}

void Narga::createNargaFromFile(const char* filename)
{
	std::ifstream file(filename);

	if (!file.is_open())
		return;

	char buff[1024];

	file.getline(buff, sizeof(buff));
	std::stringstream ss(buff);

	char brandname[CONSTANTS::BRAND_NAME_SIZE];
	ss.getline(brandname, CONSTANTS::BRAND_NAME_SIZE, '-');
	setBrandName(brandname);

	char tastename[CONSTANTS::BRAND_NAME_SIZE];
	ss.getline(tastename, CONSTANTS::BRAND_NAME_SIZE, '-');
	int tasteIndx = convertStringToTasteIndex(tastename);
	setTaste(tasteIndx);

	unsigned price = 0;
	ss >> price;
	setPrice(price);

	file.close();
}

void Narga::printNarga()
{
	std::cout << "Narga: " << this->price << " " << this->brandName << " ";
	printTaste(this->taste);
	std::cout << std::endl;
}

unsigned Narga::getPrice() const
{
	return this->price;
}

const char* Narga::getBrandName() const
{
	return this->brandName;
}

Taste Narga::getTaste() const
{
	return this->taste;
}

size_t Narga::getCount() const
{
	return this->count;
}

void Narga::setPrice(unsigned newPrice)
{
	this->price = newPrice;
}

void Narga::setBrandName(const char* newName)
{
	if (strlen(newName) > CONSTANTS::BRAND_NAME_SIZE)
	{
		std::cerr << "Too long name";
		return;
	}

	strcpy(this->brandName, newName);
}

void Narga::setTaste(int index)
{
	Taste newTaste = getTasteFromIndex(index);
	this->taste = newTaste;
}

void Narga::setCount(size_t count)
{
	this->count = count;
}

Taste Narga::getTasteFromIndex(int index)
{
	switch (index)
	{
	case 1: return Taste::BLUEBERRY; break;
	case 2: return Taste::QUEEN; break;
	case 3: return Taste::MANGO; break;
	case 4: return Taste::MELON; break;
	case 5: return Taste::BERRY; break;
	default: return Taste::BLUEBERRY; break;
	}
}

void Narga::printTaste(const Taste& taste)
{
	switch (taste)
	{
	case Taste::BLUEBERRY: std::cout << "Blueberry"; break;
	case Taste::QUEEN: std::cout << "Queen"; break;
	case Taste::MANGO: std::cout << "Mango"; break;
	case Taste::MELON: std::cout << "Melon"; break;
	case Taste::BERRY: std::cout << "Berry"; break;
	default: std::cout << "Blueberry"; break;
	}
}

int Narga::convertStringToTasteIndex(const char* tasteStr)
{
	char upperStr[256];
	for (size_t i = 0; tasteStr[i] != '\0'; ++i) {
		upperStr[i] = toupper(tasteStr[i]);
	}
	upperStr[strlen(tasteStr)] = '\0';

	if (strcmp(upperStr, "BLUEBERRY") == 0) return static_cast<int>(Taste::BLUEBERRY);
	if (strcmp(upperStr, "QUEEN") == 0) return static_cast<int>(Taste::QUEEN);
	if (strcmp(upperStr, "MANGO") == 0) return static_cast<int>(Taste::MANGO);
	if (strcmp(upperStr, "MELON") == 0) return static_cast<int>(Taste::MELON);
	if (strcmp(upperStr, "BERRY") == 0) return static_cast<int>(Taste::BERRY);

	return -1;
}

/* Alchohol */
Alchohol::Alchohol()
{
	setPrice(0.0);
	setName("");
}

Alchohol::Alchohol(double price, const char* name)
{
	setPrice(price);
	setName(name);
}

void Alchohol::createAlchoholFromFile(const char* filename)
{
	std::ifstream file(filename);

	if (!file.is_open())
		return;

	char buff[1024];

	file.getline(buff, sizeof(buff));
	std::stringstream ss(buff);

	char name[CONSTANTS::ALCHOHOL_NAME_SIZE];
	ss.getline(name, CONSTANTS::ALCHOHOL_NAME_SIZE, '-');
	setName(name);

	double price = 0.0;
	ss >> price;
	setPrice(price);

	file.close();
}

double Alchohol::getPrice() const
{
	return this->price;
}

const char* Alchohol::getName() const
{
	return this->name;
}

size_t Alchohol::getCount() const
{
	return this->count;
}

void Alchohol::setPrice(double newPrice)
{
	this->price = newPrice;
}

void Alchohol::setName(const char* newName)
{
	if (strlen(newName) > CONSTANTS::ALCHOHOL_NAME_SIZE)
	{
		std::cerr << "Too long name";
		return;
	}
	strcpy(this->name, newName);
}

void Alchohol::setCount(size_t count)
{
	this->count = count;
}

void Alchohol::printAlchohol()
{
	std::cout << "Alchocol: " << this->name << " " << this->price << std::endl;
}

/* Night club */
void NightClub::addBaloon(Baloon& newBaloon)
{
	if (this->baloonsCount >= CONSTANTS::BALOON_COUNT)
	{
		std::cerr << "Not enough space to add";
		return;
	}

	size_t countOccur = newBaloon.getCount();
	if (countOccur == 0)
	{
		this->baloons[this->baloonsCount] = newBaloon;
		this->baloonsCount++;
	}
	newBaloon.setCount(countOccur + 1);
}

void NightClub::addAlchohol(Alchohol& newAlchohol)
{
	if (this->bottlesCount >= CONSTANTS::ALCHOHOL_COUNT)
	{
		std::cerr << "Not enough space to add";
		return;
	}

	size_t countOccur = newAlchohol.getCount();
	if (countOccur == 0)
	{
		this->bottles[this->bottlesCount] = newAlchohol;
		this->bottlesCount++;
	}

	newAlchohol.setCount(countOccur + 1);
}

void NightClub::addNarga(Narga& newNarga)
{
	if (this->nargasCount >= CONSTANTS::NARGA_COUNT)
	{
		std::cerr << "Not enough space to add";
		return;
	}

	size_t countOccur = newNarga.getCount();
	if (countOccur == 0)
	{
		this->nargas[this->nargasCount] = newNarga;
		this->nargasCount++;
	}

	newNarga.setCount(countOccur + 1);
}

void NightClub::removeBaloonFromArr(Baloon& baloon)
{
	size_t currOccur = baloon.getCount();
	if (currOccur < 1)
	{
		std::cerr << "Not part of the array!";
		return;
	}
	else if (currOccur == 1)
	{
		baloon.setCount(currOccur - 1);
		removeBaloonByColor(baloon.getColor());
	}
	else
	{
		baloon.setCount(currOccur - 1);
	}
}

void NightClub::removeAlchoholFromArr(Alchohol& alchohol)
{
	size_t currOccur = alchohol.getCount();
	if (currOccur < 1)
	{
		std::cerr << "Not part of the array!";
		return;
	}
	else if (currOccur == 1)
	{
		alchohol.setCount(currOccur - 1);
		removeAlchoholByName(alchohol.getName());
	}
	else
	{
		alchohol.setCount(currOccur - 1);
	}
}

void NightClub::removeNargaFromArr(Narga& narga)
{
	size_t currOccur = narga.getCount();
	if (currOccur < 1)
	{
		std::cerr << "Not part of the array!";
		return;
	}
	else if (currOccur == 1)
	{
		narga.setCount(currOccur - 1);
		removeNargaByNameTaste(narga.getBrandName(), narga.getTaste());
	}
	else
	{
		narga.setCount(currOccur - 1);
	}
}

int NightClub::findBaloonIndexByColor(const Color& color)
{
	int index = 0;
	for (int i = 0; i < baloonsCount; i++)
	{
		if (baloons[i].getColor() == color)
		{
			index = i;
		}
	}
	return index;
}

int NightClub::findNargaIndexByNameTaste(const char* brandName, const Taste& taste)
{
	int index = 0;
	for (int i = 0; i < nargasCount; i++)
	{
		if (nargas[i].getTaste() == taste && (strcmp(nargas[i].getBrandName(), brandName) == 0))
		{
			index = i;
		}
	}
	return index;
}

int NightClub::findAlchoholIndexByName(const char* name)
{
	int index = 0;
	for (int i = 0; i < bottlesCount; i++)
	{
		if (strcmp(bottles[i].getName(), name) == 0)
		{
			index = i;
		}
	}
	return index;
}

void NightClub::removeBaloonByColor(const Color& color)
{
	int index = findBaloonIndexByColor(color);

	if (index == -1)
	{
		std::cerr << "Not existing in this array!";
		return;
	}

	for (int i = index + 1; i < baloonsCount; i++)
	{
		baloons[i - 1] = baloons[i];
	}
	baloonsCount--;
}

void NightClub::removeNargaByNameTaste(const char* brandName, const Taste& taste)
{
	int index = findNargaIndexByNameTaste(brandName, taste);

	if (index == -1)
	{
		std::cerr << "Not existing in this array!";
		return;
	}

	for (int i = index + 1; i < nargasCount; i++)
	{
		nargas[i - 1] = nargas[i];
	}
	nargasCount--;
}

void NightClub::removeAlchoholByName(const char* name)
{
	int index = findAlchoholIndexByName(name);

	if (index == -1)
	{
		std::cerr << "Not existing in this array!";
		return;
	}

	for (int i = index + 1; i < bottlesCount; i++)
	{
		bottles[i - 1] = bottles[i];
	}
	bottlesCount--;
}

void NightClub::printBaloonsArr()
{
	for (int i = 0; i < this->baloonsCount; i++)
	{
		this->baloons[i].printBaloon();
	}
}

void NightClub::printBottlesArr()
{
	for (int i = 0; i < this->bottlesCount; i++)
	{
		this->bottles[i].printAlchohol();
	}
}

void NightClub::printNargasArr()
{
	for (int i = 0; i < this->nargasCount; i++)
	{
		this->nargas[i].printNarga();
	}
}
