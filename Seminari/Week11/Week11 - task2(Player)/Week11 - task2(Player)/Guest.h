#pragma once
#include "Player.h"

class Guest : public Player
{
public:
	Guest(int playTime);
	bool levelUp() override;
private:
	int playTime;
};

