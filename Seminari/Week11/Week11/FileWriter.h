#pragma once
#include <iostream>
#include <fstream>
#include "MyString.h"

class FileWriter
{
public:
	FileWriter(const MyString& newFilename);
	virtual void write(const int* arr, size_t size) const = 0;
protected:
	MyString filename;
};