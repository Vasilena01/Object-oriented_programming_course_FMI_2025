#pragma once
#include "FileReader.h"

class BinaryFileReader : public FileReader
{
public:
	BinaryFileReader(const MyString& filename);
	void read(int*& arr, size_t& size) const override;
};

