#pragma once
#include <iostream>
#include "GlobalConstants.h"

class Person
{
public:
	Person() = default;
	Person(const char* firstName, const char* familyName, const char* egn);
	Person(const char* firstName, const char* middleName, const char* familyName, const char* egn);
	
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	const char* getEgn() const;
	const char* getFirstName() const;
	const char* getMiddleName() const;
	const char* getFamilyName() const;
	void setFirstName(const char* name);
	void setMiddleName(const char* name);
	void setFamilyName(const char* name);

	Person* getManager() const;
	size_t getSubordinateCount() const;
	bool hasSubordinates() const;

	void setManager(Person* newManager);
	void addSubordinate(Person* sub);
	void removeSubordinate(Person* sub);

	virtual Person* clone() const;
private:
	char egn[GlobalConstants::EGN_LEN];
	char firstName[GlobalConstants::NAME_LEN];
	char middleName[GlobalConstants::NAME_LEN];
	char familyName[GlobalConstants::NAME_LEN];

	Person* manager;
	Person** subordinates;
	size_t subCount;
	size_t subCapacity;

	void copyFrom(const Person& other);
	void free();
	void expandSubordinates();
};

bool operator==(const Person& lhs, const Person& rhs);
bool operator!=(const Person& lhs, const Person& rhs);