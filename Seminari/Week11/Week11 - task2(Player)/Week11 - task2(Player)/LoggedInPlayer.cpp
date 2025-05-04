#include "LoggedInPlayer.h"

LoggedInPlayer::LoggedInPlayer(const char* pass) : Player()
{
	if (strlen(pass) > 8) {
		throw std::exception("incorent length must be lower than 9");
	}

	strcpy(password, pass);
}

bool LoggedInPlayer::logIn(const char* pass)
{
	if (strcmp(pass, password) == 0 && id > 0) {
		return true;
	}
	else
	{
		return false;
	}
}
