#include "ArrFileWriter.h"

ArrFileWriter::ArrFileWriter(const MyString& filename) : FileWriter(filename)
{
}

void ArrFileWriter::write(const int* arr, size_t size) const
{
	std::ofstream file(filename.c_str());
	if (!file.is_open()) {
		throw std::logic_error("Couldn't open file");
	}

	for (int i = 0; i < size; i++) {
		if (i == size - 1) {
			file << arr[i];
		}
		else {
			file << arr[i] << " ";
		}
	}
}
