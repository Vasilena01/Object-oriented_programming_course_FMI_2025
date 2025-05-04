#include "PremiumPlayer.h"

PremiumPlayer::PremiumPlayer(const char* name) : Player(), username(name)
{
}

bool PremiumPlayer::levelUp()
{
	if (points >= 256 && points < 512) {
		star = Star::SECOND;
		return true;
	}
	else if (points >= 512 && points < 768 && star == Star::SECOND) {
		star = Star::THIRD;
		return true;
	}
	else if (points >= 768 && points < 1024 && star == Star::THIRD) {
		star = Star::FOURTH;
		return true;
	}
	else if (points >= 1024 && star == Star::FOURTH) {
		star = Star::FIFTH;
		return true;
	}
	else {
		return false;
	}
}
