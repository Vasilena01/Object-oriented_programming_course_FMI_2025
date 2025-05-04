#pragma once
#include <iostream>
#include <fstream>
#include "MyString.h"

namespace HelperFunctions
{
	size_t getFileSize(std::ifstream& ifs);
	size_t getCharCount(std::ifstream& ifs, char ch);
	const char* extractExtenssion(MyString& filename);
};

