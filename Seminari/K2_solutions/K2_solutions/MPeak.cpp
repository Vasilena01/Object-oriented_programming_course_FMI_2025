#include "MPeak.h"

MPeak::MPeak() : Peak()
{
}

MPeak::MPeak(const char* mountainName, int height, int kotaNum) : Peak(mountainName, height), kotaNum(kotaNum)
{
}

void MPeak::printName() const
{
	std::cout << "MPeak kota number: " << kotaNum << std::endl;
}
