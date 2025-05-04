#pragma once
#include "Player.h"
#include "MyString.h"

class PremiumPlayer : public Player
{
public:
	PremiumPlayer(const char* name);
	bool levelUp() override;
private:
	MyString username;
};

