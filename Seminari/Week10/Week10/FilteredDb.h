#pragma once
#include "StudentDb.h"

class FilteredDb : public StudentDb
{
public:
	void filter(bool (*predicate)(const Student*));
	void limit(int N);
};

