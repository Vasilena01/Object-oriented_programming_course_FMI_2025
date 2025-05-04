#include "BinaryFileReader.h"
#include "HelperFunctions.h"

BinaryFileReader::BinaryFileReader(const MyString& filename) : FileReader(filename)
{}

void BinaryFileReader::read(int*& arr, size_t& size) const
{
	std::ifstream file(filename.c_str(), std::ios::binary);
	if (!file.is_open()) {
		throw std::logic_error("Couldn't open file");
	}

	delete[] arr;
	size_t fileSize = HelperFunctions::getFileSize(file);
	size = fileSize / sizeof(int);
	arr = new int[size];
	file.read((char*)&arr, fileSize);
}
