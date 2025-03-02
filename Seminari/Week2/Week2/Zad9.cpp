#include "Zad9.h"

void printUser(const User& user)
{
	std::cout << user.name << " " << user.email << " " << user.pass << std::endl;
}

void printUsers(const System& system, size_t usersSize)
{
	for (int i = 0; i < usersSize; i++)
	{
		printUser(system.users[i]);
	}
}

User getUserFromCurrLine(const char* buff)
{
	User user;
	int index = 0;
	int currValueIndex = 0;
	char currValue[1024]{};

	for (int i = 0; i < strlen(buff); i++)
	{
		if (buff[i] == ' ')
		{
			currValue[currValueIndex] = '\0';

			if (index == 0)
			{
				strcpy(user.name, currValue);
			}
			else if (index == 1)
			{
				strcpy(user.email, currValue);
			}

			currValueIndex = 0;
			index++;
		}
		else
		{
			currValue[currValueIndex++] = buff[i];
		}
	}

	if (currValueIndex > 0)
	{
		currValue[currValueIndex] = '\0';

		strcpy(user.pass, currValue);
	}

	return user;
}

void readUsersFromFile(const char* filename, User* users, size_t& usersSize)
{ 
	std::ifstream file(filename);
	if (!file.is_open())
		return;

	char buff[1024];

	while (file.getline(buff, sizeof(buff)))
	{
		users[usersSize++] = getUserFromCurrLine(buff);
	}
}

void writeUserToFile(std::ofstream& file, const User& user)
{
	file << user.name << " " << user.email << " " << user.pass << "\n";
}

void writeUsersToFile(const char* filename, const User* users, size_t usersSize)
{
	std::ofstream file(filename);
	if (!file.is_open())
		return;

	for (int i = 0; i < usersSize; i++)
	{
		writeUserToFile(file, users[i]);
	}
}

bool checkIfUserIsAlreadyRegistered(const char* name, const char* password, const User* users, size_t usersSize)
{
	for (int i = 0; i < usersSize; i++)
	{
		if (strcmp(name, users[i].name) == 0 && strcmp(password, users[i].pass) == 0)
		{
			return true;
		}
	}
	return false;
}

void input9()
{
	System system;
	User user;
	const char* filename = "users.txt";
	size_t usersSize = 0;

	readUsersFromFile(filename, system.users, usersSize);
	char input[CONSTANTS::SIZE]{};
	std::cout << "Enter command (register | login | exit): ";
	while (std::cin >> input)
	{
		std::cout << std::endl;
		if (strcmp(input, "register") == 0)
		{
			std::cout << "Enter name: ";
			std::cin >> user.name;
			std::cout << std::endl;

			std::cout << "Enter email: ";
			std::cin >> user.email;
			std::cout << std::endl;

			std::cout << "Enter password: ";
			std::cin >> user.pass;
			std::cout << std::endl;

			if (checkIfUserIsAlreadyRegistered(user.name, user.pass, system.users, usersSize))
			{
				std::cout << "This user is already registered!" << std::endl;
			}
			else
			{
				system.users[usersSize++] = user;
				writeUsersToFile(filename, system.users, usersSize);
			}
		
			std::cout << "Enter command (register | login | exit): ";
			continue;
		}
		else if (strcmp(input, "login") == 0)
		{
			std::cout << "Enter name: ";
			std::cin >> user.name;
			std::cout << std::endl;

			std::cout << "Enter password: ";
			std::cin >> user.pass;
			std::cout << std::endl;

			if (checkIfUserIsAlreadyRegistered(user.name, user.pass, system.users, usersSize))
			{
				std::cout << "Login successful!" << std::endl;
			}
			else
			{
				std::cout << "Invalid login data! Please try again!" << std::endl;
			}
			std::cout << "Enter command (register | login | exit): ";
			continue;
		}
		else if (strcmp(input, "exit") == 0)
		{
			std::cout << "Exiting program...";
			break;
		}
		else
		{
			std::cout << "Enter command (register | login | exit): ";
			std::cout << "Invalid command. Try again!" << std::endl;
		}
	}
}