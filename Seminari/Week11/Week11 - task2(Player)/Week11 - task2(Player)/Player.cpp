#include "Player.h"

int Player::idCount = 0;

Player::Player()
{
	id = ++idCount;
	star = Star::FIRST;
}

bool Player::levelUp()
{
	if (points >= 256 && points < 512) {
		star = Star::SECOND;
		return true;
	}
	else if (points >= 512 && points < 2014 && star == Star::SECOND) {
		star = Star::THIRD;
		return true;
	}
	else if (points >= 1024 && points < 2048 && star == Star::THIRD) {
		star = Star::FOURTH;
		return true;
	}
	else if (points >= 2048 && star == Star::FOURTH) {
		star = Star::FIFTH;
		return true;
	}
	else {
		return false;
	}
}
