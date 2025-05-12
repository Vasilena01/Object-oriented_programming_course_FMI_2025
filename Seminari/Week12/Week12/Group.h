#pragma once
#include "Person.h"

class Group
{
public:
	Group();
	Group(size_t cap);
	Group(const Group& other);
	Group& operator=(const Group& other);
	Group(Group&& other);
	Group& operator=(Group&& other);
	~Group();

	Group& operator+=(Person& newPerson);
	Group& operator-=(const Person& person);

	Person* operator[](const char* egn) const;
	size_t operator()() const;
	bool operator()(const Person& person) const;
	size_t getSize() const;
	size_t getPersonByIndex(const Person& person) const;
protected:
	Person** people;
	size_t size;
	size_t capacity;

	void resize(size_t newCap);
	void copyFrom(const Group& other);
	void moveFrom(Group&& other);
	void free();
};

Group operator+(const Group& curr, Person& newPerson);
Group operator-(const Group& curr, const Person& person);