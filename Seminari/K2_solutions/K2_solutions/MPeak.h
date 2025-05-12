#pragma once
#include "Peak.h"

class MPeak : public Peak
{
public:
	MPeak();
	MPeak(const char* mountainName, int height, int kotaNum);

	void printName() const override;
private:
	int kotaNum;
};

