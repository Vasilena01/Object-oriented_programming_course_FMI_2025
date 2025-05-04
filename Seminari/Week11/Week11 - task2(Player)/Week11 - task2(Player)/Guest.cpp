#include "Guest.h"

Guest::Guest(int playTime) : Player(), playTime(playTime)
{
}

bool Guest::levelUp()
{
    std::cout << "Guests can't level up";
    return false;
}
