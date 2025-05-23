#pragma once
#include "FileReader.h"

class ArrFileReader : public FileReader
{
public:
	ArrFileReader(const MyString& filename);
	void read(int*& arr, size_t& size) const override;
};