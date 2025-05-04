#pragma once
#include <iostream>
#include <fstream>
#include "MyString.h"

class FileReader
{
public:
	FileReader(const MyString& newFilename);
	virtual void read(int*& arr, size_t& size) const = 0;
protected:
	MyString filename;
};