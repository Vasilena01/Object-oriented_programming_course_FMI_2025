#include "BinaryFileWriter.h"

BinaryFileWriter::BinaryFileWriter(const MyString& filename) : FileWriter(filename)
{}

void BinaryFileWriter::write(const int* arr, size_t size) const
{
	std::ofstream file(filename.c_str(), std::ios::binary);
	if (!file.is_open()) {
		throw std::logic_error("Couldn't open file");
	}

	file.write((const char*)&arr, size * sizeof(arr[0]));
}
