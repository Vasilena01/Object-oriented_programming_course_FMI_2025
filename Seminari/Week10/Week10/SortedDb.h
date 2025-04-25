#pragma once
#include "StudentDb.h"

class SortedDb : public StudentDb
{
public:
	void sortBy(bool (*comparator)(const Student*, const Student*));
};

