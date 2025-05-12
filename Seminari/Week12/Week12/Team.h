#pragma once
#include "Group.h"

class Team : public Group
{
public:
	Team();
	Team(size_t cap);

	bool operator()(Person& manager, Person& subordinate);
	size_t getManagersCount() const;
};

bool operator>(const Team& lhs, const Team& rhs);
bool operator<(const Team& lhs, const Team& rhs);
bool operator>=(const Team& lhs, const Team& rhs);
bool operator<=(const Team& lhs, const Team& rhs);