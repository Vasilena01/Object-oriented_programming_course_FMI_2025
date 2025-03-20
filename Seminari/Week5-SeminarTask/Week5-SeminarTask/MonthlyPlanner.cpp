#include "MonthlyPlanner.h"

Month& MonthlyPlanner::getMonthByIndex(int index)
{
	// TODO: insert return statement here
}

void MonthlyPlanner::copyFrom(const MonthlyPlanner& other)
{
}

void MonthlyPlanner::free()
{
}

MonthlyPlanner::MonthlyPlanner()
{
}

MonthlyPlanner::MonthlyPlanner(int month)
{
}

MonthlyPlanner::MonthlyPlanner(const MonthlyPlanner& other)
{
}

MonthlyPlanner& MonthlyPlanner::operator=(const MonthlyPlanner& other)
{
	// TODO: insert return statement here
}

MonthlyPlanner::~MonthlyPlanner()
{
}

void MonthlyPlanner::addTask(const Task& task, int dayIndex, int beginTime)
{
}

Task* MonthlyPlanner::getUnfinishedTasksForDay(int dayIndex)
{
	return nullptr;
}

void MonthlyPlanner::markAsFinished(int dayIndex, int time)
{
}

void MonthlyPlanner::operator>>(std::ofstream& ofs)
{
}

void MonthlyPlanner::operator<<(std::ifstream& ifs)
{
}
