#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>

namespace CONSTANTS
{
	constexpr int SIZE = 128;
	constexpr int ARR_SIZE = 100;
}

struct User
{
	char name[CONSTANTS::SIZE];
	char email[CONSTANTS::SIZE];
	char pass[CONSTANTS::SIZE];
};

struct System
{
	User users[CONSTANTS::ARR_SIZE];
};

void printUser(const User& user);
void printUsers(const System& system, size_t usersSize);
User getUserFromCurrLine(const char* buff);
void readUsersFromFile(const char* filename, User* users, size_t& usersSize);
void writeUserToFile(const char* filename, const User& user);
void writeUsersToFile(const char* filename, const User* users, size_t usersSize);
void input9();