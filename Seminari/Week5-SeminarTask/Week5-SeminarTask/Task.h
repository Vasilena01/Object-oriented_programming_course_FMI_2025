#pragma once
#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)

class Task
{
public:
	Task();
	Task(const char* description);
	Task(std::ifstream& ifs);
	Task(const Task& other);
	Task& operator=(const Task& other);
	void operator>>(std::ofstream& ofs);
	~Task();
	const char* getDescription() const;
	unsigned getPriority() const;
	bool getStatus() const;
	int getDuration() const;
	void setStatus();
	const Task& compareTasks(const Task& other);
private:
	char* description;
	unsigned priority;
	bool status;
	int duration;
	static const int MAX_PRIORITY = 10;

	void copyFrom(const Task& other);
	void free();
};

