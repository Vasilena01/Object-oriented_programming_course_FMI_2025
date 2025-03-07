#include "Zad7.h"

Type getTypeById(unsigned id)
{
	switch(id)
	{
	case 1: return Type::NORMAL; break;
	case 2: return Type::FIRE; break;
	case 3: return Type::WATER; break;
	case 4: return Type::GRASS; break;
	case 5: return Type::ELECTRIC; break;
	case 6: return Type::GHOST; break;
	case 7: return Type::FLYING; break;
	default: std::cout << "Invalid id!"; break;
	}
}

int getIdFromType(const Type& type)
{
	switch(type)
	{
	case Type::ELECTRIC: return 5; break;
	case Type::FIRE: return 2; break;
	case Type::FLYING: return 7; break;
	case Type::GHOST: return 6; break;
	case Type::GRASS: return 4; break;
	case Type::NORMAL: return 1; break;
	case Type::WATER: return 3; break;
	default: return -1;
	}
}

void printType(const Type& type)
{
	switch (type)
	{
	case Type::ELECTRIC: std::cout << "Electric"; break;
	case Type::FIRE: std::cout << "Fire"; break;
	case Type::FLYING: std::cout << "Flying"; break;
	case Type::GHOST: std::cout << "Ghost"; break;
	case Type::GRASS: std::cout << "Grass"; break;
	case Type::NORMAL: std::cout << "Normal"; break;
	case Type::WATER: std::cout << "Water"; break;
	default: std::cout << "Type none";
	}
}

void initPokemonFromConsole(Pokemon& pokemon)
{
	std::cin >> pokemon.name;
	int type;
	std::cin >> type;
	pokemon.type = getTypeById(type);
	int strength;
	std::cin >> strength;
	while (strength < CONSTANTS::MIN_STRENGTH || strength > CONSTANTS::MAX_STRENGTH)
	{
		std::cin >> strength;
	}
	pokemon.strength = strength;
}

void readPokemonFromFile(PokemonHandler& handler, Pokemon& pokemon)
{
	if (!handler.file.is_open())
		return;

	handler.file.read((char*)&pokemon, sizeof(Pokemon));
}

void writePokemonToFile(PokemonHandler& handler, const Pokemon& pokemon)
{
	if (!handler.file.is_open())
		return;

	handler.file.seekg(0, std::ios::end);
	handler.file.write((const char*)&pokemon, sizeof(Pokemon));
	handler.file.seekg(0);
}

PokemonHandler newPokemonHandler(const char* filename)
{
	PokemonHandler handler;
	handler.file = std::fstream (filename, std::ios::binary | std::ios::in | std::ios::out);
	strcpy(handler.fileName, filename);
	return handler;
}

int size(PokemonHandler& ph) {
	if (!ph.file.is_open()) {
		std::cerr << "File is not open!" << std::endl;
		return -1;
	}

	int currPos = ph.file.tellg();
	ph.file.seekg(0, std::ios::end);
	int size = ph.file.tellg();
	ph.file.seekg(currPos);
	return size;
}

Pokemon at(PokemonHandler& ph, int i)
{
	int pokemonsCount = size(ph) / sizeof(Pokemon);
	if (i > pokemonsCount)
	{
		std::cerr << "Index out of bound!" << std::endl;
		return {};
	}

	Pokemon toreturn;
	int positionInFile = i * sizeof(Pokemon);
	ph.file.seekg(positionInFile);
	ph.file.read((char*)&toreturn, sizeof(Pokemon));
	ph.file.seekg(0);
	return toreturn;
}

void swap(PokemonHandler& ph, int i, int j)
{
	int pokemonsCount = size(ph) / sizeof(Pokemon);
	if (i >= pokemonsCount || j >= pokemonsCount)
	{
		std::cerr << "Index out of bound!" << std::endl;
		return;
	}

	int positionFirstInFile = i * sizeof(Pokemon);
	int positionSecondInFile = j * sizeof(Pokemon);
	Pokemon firstPokemon = at(ph, i);
	Pokemon secondPokemon = at(ph, j);
	ph.file.seekg(positionFirstInFile);
	ph.file.write((const char*)&secondPokemon, sizeof(Pokemon));
	ph.file.seekg(positionSecondInFile);
	ph.file.write((const char*)&firstPokemon, sizeof(Pokemon));
	ph.file.seekg(0);
}

void textify(PokemonHandler& ph, const char* filename)
{
	std::ofstream file(filename);
	if (!file.is_open())
		return;

	int pokemonsCount = size(ph) / sizeof(Pokemon);
	for (int i = 0; i < pokemonsCount; i++)
	{
		Pokemon curr = at(ph, i);
		file << curr.name << " " << getIdFromType(curr.type) << " " << curr.strength << '\n';
	}
}

void untextify(PokemonHandler& ph, const char* filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
		return;

	ph.file = std::fstream(ph.fileName, std::ios::in | std::ios::out | std::ios::trunc);
	if (!ph.file.is_open())
		return;

	char buff[1024];
	while (file.getline(buff, sizeof(buff)))
	{
		std::stringstream ss(buff);
		Pokemon newPokemon;
		ss >> newPokemon.name;
		char idCh;
		ss >> idCh;
		int id = idCh - '0';
		newPokemon.type = getTypeById(id);
		ss >> newPokemon.strength;
		writePokemonToFile(ph, newPokemon);
	}
}

void printPokemon(const Pokemon& pokemon)
{
	std::cout << "Name: " << pokemon.name << std::endl;
	std::cout << "Type: ";
	printType(pokemon.type);
	std::cout << std::endl;
	std::cout << "Strength: " << pokemon.strength << std::endl;
}

void printPokemons(PokemonHandler& handler)
{
	handler.file.seekg(0, std::ios::beg);
	int fileSize = size(handler);
	int pokemonsCount = fileSize / sizeof(Pokemon);
	for (int i = 0; i < pokemonsCount; i++)
	{
		Pokemon pokemon;
		readPokemonFromFile(handler, pokemon);
		printPokemon(pokemon);
	}
}

void input7()
{
	char filename[CONSTANTS::SIZE] = "pokemons3.dat";
	Pokemon pokemon;
	PokemonHandler handler = newPokemonHandler(filename);

	// Methods to test code:
	//initPokemonFromConsole(pokemon);
	//writePokemonToFile(handler, pokemon);
	//readPokemonFromFile(handler, pokemon);
	//printPokemons(handler);
	//Pokemon toreturn = at(handler, 2);
	//printPokemon(toreturn);
	//swap(handler, 1, 4);
	//printPokemons(handler);
	//textify(handler, "pokemonsTxt.txt");
	//untextify(handler, "pokemonsTxt.txt");
	//printPokemons(handler);
}