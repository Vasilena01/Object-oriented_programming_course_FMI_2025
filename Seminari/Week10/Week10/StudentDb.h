#pragma once
#include "Student.h"

class StudentDb
{
public:
	StudentDb();
	StudentDb(const StudentDb& other);
	StudentDb& operator=(const StudentDb& other);
	StudentDb(StudentDb&& other);
	StudentDb& operator=(StudentDb&& other);
	~StudentDb();

	void add(Student* newStudent);
	void add(const Student& newStudent);
	void removeByFn(unsigned fn);
	Student* findByFn(unsigned fn);
	void display() const;
protected:
	Student** students;
	size_t size;
	size_t capacity;

	int findFirstFreeIndex();
	void resize(size_t newCap);
	void copyFrom(const StudentDb& other);
	void moveFrom(StudentDb&& other);
	void free();
};

