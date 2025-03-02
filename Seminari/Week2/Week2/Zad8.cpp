#include "Zad8.h"

char* extractKeyFromBuff(const char* buff)
{
	char* key = new char[1024] {};
	int index = 0;
	for (int i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == ' ')
			break;
		key[index++] = buff[i];
	}
	key[index] = '\0';
	return key;
}

char* extractValueFromBuff(const char* buff)
{
	char* value = new char[1024] {};
	int index = 0;
	int startIndex = 0;
	for (int i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] != ' ')
		{
			startIndex++;
		}
		else
		{
			break;
		}
	}

	startIndex++;
	for (int i = startIndex; buff[i] != '\0'; i++)
	{
		value[index++] = buff[i];
	}
	value[index] = '\0';
	return value;
}

char* readValueFromFile(const char* filename, const char* tag)
{
	std::ifstream file(filename);

	if (!file.is_open())
	{
		return nullptr;
	}

	char buff[1024];
	while (file.getline(buff, sizeof(buff)))
	{
		char* key = extractKeyFromBuff(buff);
		if (strcmp(key, tag) == 0)
		{
			char* value = extractValueFromBuff(buff);
			delete[] key;
			return value;
		}
	}
	return nullptr;
}

char* getTagNameFromFile(std::ifstream& file)
{
	char* buff = new char[1024] {};
	char curr;
	int index = 0;
	while (!file.eof())
	{
		file.get(curr);
		if (curr == '}')
			break;
		buff[index++] = curr;
	}
	buff[index] = '\0';
	return buff;
}

void replaceValuesInFile(const char* examplefilename, const char* destfilename, const char* valuesfilename)
{
	std::ifstream fileSrc(examplefilename);
	std::ofstream fileDest(destfilename);

	if (!fileSrc.is_open() || !fileDest.is_open())
		return;

	char buff[1024];
	char curr;
	while (fileSrc.get(curr))
	{
		if (fileSrc.eof())
			break;

		if (curr == '{')
		{
			char* tagName = getTagNameFromFile(fileSrc);
			char* value = readValueFromFile(valuesfilename, tagName);
			fileDest << value;
			continue;
		}
		fileDest.put(curr);
	}
}

void input8() {
	const char* valuesFileName = "keyValues.txt";
	const char* exampleFileName = "example.txt";
	const char* destFileName = "dest.txt";

	replaceValuesInFile(exampleFileName, destFileName, valuesFileName);
}