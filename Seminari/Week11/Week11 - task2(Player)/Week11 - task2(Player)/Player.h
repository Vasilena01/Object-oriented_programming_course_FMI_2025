#pragma once
#include <iostream>

enum class Star {
	FIRST = 1,
	SECOND,
	THIRD,
	FOURTH,
	FIFTH
};

class Player
{
public:
	Player();
	virtual bool levelUp();
protected:
	static int idCount;
	int id;
	unsigned points;
	Star star;
};

