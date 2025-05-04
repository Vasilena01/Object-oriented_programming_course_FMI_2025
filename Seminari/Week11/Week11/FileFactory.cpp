#include "FileFactory.h"
#include "HelperFunctions.h"
#include "BinaryFileReader.h"
#include "ArrFileReader.h"
#include "CsvFileReader.h"

#include "BinaryFileWriter.h"
#include "ArrFileWriter.h"
#include "CsvFileWriter.h"

FileReader* FileFactory::fileReaderFactory(MyString& filename)
{
    const char* extenssion = HelperFunctions::extractExtenssion(filename);
    if (strcmp(extenssion, ".dat")) {
        return new BinaryFileReader(filename);
    }
    else if (strcmp(extenssion, ".arr")) {
        return new ArrFileReader(filename);
    }
    else if (strcmp(extenssion, ".csv")) {
        return new CsvFileReader(filename);
    }
    else
    {
        throw std::exception("No such file type");
    }
}

FileWriter* FileFactory::fileWriterFactory(MyString& filename)
{
    const char* extenssion = HelperFunctions::extractExtenssion(filename);
    if (strcmp(extenssion, ".dat")) {
        return new BinaryFileWriter(filename);
    }
    else if (strcmp(extenssion, ".arr")) {
        return new ArrFileWriter(filename);
    }
    else if (strcmp(extenssion, ".csv")) {
        return new CsvFileWriter(filename);
    }
    else
    {
        throw std::exception("No such file type");
    }
}
