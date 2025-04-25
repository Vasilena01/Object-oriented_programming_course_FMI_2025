#pragma once
#include "MyString.h"

class Student
{
public:
	Student() = delete;
	Student(const MyString& name, unsigned fn, unsigned course);
	const MyString getName() const;
	unsigned getFn() const;
	unsigned getCourse() const;

	void setName(const MyString& name);
	void setFn(unsigned fn);
	void setCourse(unsigned course);
	void print() const;
private:
	MyString name;
	unsigned fn;
	unsigned course;
};

