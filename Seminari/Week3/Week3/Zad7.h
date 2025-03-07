#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#pragma warning(disable : 4996)

namespace CONSTANTS
{
	constexpr int SIZE = 50;
	constexpr int MIN_STRENGTH = 10;
	constexpr int MAX_STRENGTH = 1000;
}

enum Type
{
	NORMAL = 1, 
	FIRE, 
	WATER, 
	GRASS, 
	ELECTRIC, 
	GHOST, 
	FLYING
};

struct Pokemon
{
	char name[CONSTANTS::SIZE];
	Type type;
	unsigned strength;
};

struct PokemonHandler
{
	std::fstream file;
	char fileName[CONSTANTS::SIZE];
};

Type getTypeById(unsigned id);
int getIdFromType(const Type& type);
void printType(const Type& type);
void initPokemonFromConsole(Pokemon& pokemon);
void readPokemonFromFile(PokemonHandler& handler, Pokemon& pokemon);
void writePokemonToFile(PokemonHandler& handler, const Pokemon& pokemon);
PokemonHandler newPokemonHandler(const char* filename);
int size(const PokemonHandler& ph);
Pokemon at(PokemonHandler& ph, int i);
void swap(PokemonHandler& ph, int i, int j);
void textify(const PokemonHandler& ph, const char* filename);
void untextify(PokemonHandler& ph, const char* filename);
void printPokemons(PokemonHandler& handler);
void input7();
