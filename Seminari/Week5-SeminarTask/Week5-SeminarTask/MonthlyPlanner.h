#pragma once
#include "Task.h"

enum class Month
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

class MonthlyPlanner
{
public:
	MonthlyPlanner();
	MonthlyPlanner(int month);
	MonthlyPlanner(const MonthlyPlanner& other);
	MonthlyPlanner& operator=(const MonthlyPlanner& other);
	~MonthlyPlanner();

	void addTask(const Task& task, int dayIndex, int beginTime);
	Task* getUnfinishedTasksForDay(int dayIndex);
	void markAsFinished(int dayIndex, int time);
	void operator>>(std::ofstream& ofs);
	void operator<<(std::ifstream& ifs);
private:
	Month month;
	Task** tasks;
	size_t size;
	size_t capacity;
	Month& getMonthByIndex(int index);
	void copyFrom(const MonthlyPlanner& other);
	void free();
};

