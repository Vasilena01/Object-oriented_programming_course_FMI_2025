#include "HelperFunctions.h"

size_t HelperFunctions::getFileSize(std::ifstream& ifs)
{
    size_t curr = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t size = ifs.tellg();
    ifs.seekg(curr);

    return size;
}

size_t HelperFunctions::getCharCount(std::ifstream& ifs, char ch)
{
    int count = 0;
    size_t currPos = ifs.tellg();
    ifs.seekg(0);

    while (true) {
        if (ifs.eof()) {
            break;
        }

        char curr = ifs.get();
        if (curr == ch) {
            count++;
        }
    }

    ifs.clear();
    ifs.seekg(currPos);
    return count;
}

const char* HelperFunctions::extractExtenssion(MyString& filename)
{
    int i = filename.length() - 1;
    for (int j = i; j >= 0; j--, i--) {
        if (filename[i] == '.')
        {
            break;
        }
    }

    MyString substr = filename.substr(i, filename.length() - i);
    return substr.c_str();
}
