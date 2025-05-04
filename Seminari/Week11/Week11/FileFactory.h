#pragma once
#include "FileReader.h"
#include "FileWriter.h"

class FileFactory
{
public:
	static FileReader* fileReaderFactory(MyString& filename);
	static FileWriter* fileWriterFactory(MyString& filename);
};

