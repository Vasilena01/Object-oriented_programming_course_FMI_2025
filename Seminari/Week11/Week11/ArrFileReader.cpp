#include "ArrFileReader.h"
#include "HelperFunctions.h"

ArrFileReader::ArrFileReader(const MyString& filename) : FileReader(filename)
{}

void ArrFileReader::read(int*& arr, size_t& size) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw std::logic_error("Couldn't open file");
	}

	delete[] arr;
	size = HelperFunctions::getCharCount(file, ' ') + 1;
	arr = new int[size];
	
	for (int i = 0; i < size; i++) {
		file >> arr[i];
	}
}
