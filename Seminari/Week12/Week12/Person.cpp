#include "Person.h"
#pragma warning (disable : 4996)
Person::Person(const char* firstName, const char* familyName, const char* egn)
{
    setFirstName(firstName);
    setFamilyName(familyName);
    strcpy(this->egn, egn);
}

Person::Person(const char* firstName, const char* middleName, const char* familyName, const char* egn) : Person(firstName, familyName, egn)
{
    setMiddleName(middleName);
}

Person::Person(const Person& other)
{
    copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Person::~Person()
{
    free();
}

const char* Person::getEgn() const
{
    return egn;
}

const char* Person::getFirstName() const
{
    return firstName;
}

const char* Person::getMiddleName() const
{
    return middleName;
}

const char* Person::getFamilyName() const
{
    return familyName;
}

void Person::setFirstName(const char* name)
{
    strcpy(this->firstName, name);
}

void Person::setMiddleName(const char* name)
{
    strcpy(this->middleName, name);
}

void Person::setFamilyName(const char* name)
{
    strcpy(this->familyName, name);
}

Person* Person::getManager() const
{
    return manager;
}

size_t Person::getSubordinateCount() const
{
    return subCount;
}

bool Person::hasSubordinates() const
{
    return subCount > 0;
}

void Person::setManager(Person* newManager)
{
    manager = newManager;
}

void Person::addSubordinate(Person* sub)
{
    if (subCount == subCapacity) {
        expandSubordinates();
    }
    subordinates[subCount++] = sub;
}

void Person::removeSubordinate(Person* sub)
{
    for (size_t i = 0; i < subCount; i++) {
        if (subordinates[i] == sub) {
            for (size_t j = i; j < subCount - 1; j++) {
                subordinates[j] = subordinates[j + 1];
            }
            subCount--;
            return;
        }
    }
}

Person* Person::clone() const
{
    return new Person(*this);
}

void Person::copyFrom(const Person& other)
{
    strcpy(firstName, other.firstName);
    strcpy(middleName, other.middleName);
    strcpy(familyName, other.familyName);

    manager = other.manager;
    subCount = other.subCount;
    subCapacity = other.subCapacity;
    subordinates = new Person * [subCapacity];
    for (size_t i = 0; i < subCount; i++) {
        subordinates[i] = other.subordinates[i];
    }
}

void Person::free()
{
    delete[] subordinates;
    delete[] manager;
    subordinates = nullptr;
    subCount = subCapacity = 0;
}

void Person::expandSubordinates()
{
    if (subCapacity == 0) subCapacity = 2;
    else subCapacity *= 2;

    Person** temp = new Person * [subCapacity];
    for (size_t i = 0; i < subCount; i++) {
        temp[i] = subordinates[i];
    }

    delete[] subordinates;
    subordinates = temp;
}

bool operator==(const Person& lhs, const Person& rhs)
{
    return strcmp(lhs.getEgn(), rhs.getEgn()) == 0;
}

bool operator!=(const Person& lhs, const Person& rhs)
{
    return !(lhs == rhs);
}

