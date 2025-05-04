#pragma once
#include "Player.h"

class LoggedInPlayer : public Player
{
public:
	LoggedInPlayer(const char* pass);
	bool logIn(const char* pass);
private:
	char password[8 + 1];
};

