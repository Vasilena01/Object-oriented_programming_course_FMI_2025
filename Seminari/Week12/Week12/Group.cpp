#include "Group.h"

void Group::resize(size_t newCap)
{
	Person** newPeople = new Person * [newCap];
	capacity = newCap;
	for (int i = 0; i < size; i++) {
		newPeople[i] = people[i];
	}

	delete[] people;
	people = newPeople;
}

void Group::copyFrom(const Group& other)
{
	people = new Person*[other.capacity];
	for (int i = 0; i < other.size; i++) {
		people[i] = other.people[i]->clone();
	}

	size = other.size;
	capacity = other.capacity;
}

void Group::moveFrom(Group&& other)
{
	people = other.people;
	other.people = nullptr;
}

void Group::free()
{
	for (int i = 0; i < size; i++) {
		delete people[i];
	}

	delete[] people;
}

Group::Group()
{
	capacity = 8;
	size = 0;
	people = new Person * [capacity];
}

Group::Group(size_t cap)
{
	capacity = cap;
	size = 0;
	people = new Person * [capacity];
}

Group::Group(const Group& other)
{
	copyFrom(other);
}

Group& Group::operator=(const Group& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Group::Group(Group&& other)
{
	moveFrom(std::move(other));
}

Group& Group::operator=(Group&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Group::~Group()
{
	free();
}

Group& Group::operator+=(Person& newPerson)
{
	if (this->operator()(newPerson)) {
		throw std::exception("Person already exists");
	}

	if (size == capacity) {
		resize(capacity * 2);
	}

	people[size++] = newPerson.clone();
	return *this;
}

Group& Group::operator-=(const Person& person)
{
	if (!this->operator()(person)) {
		throw std::exception("Person doesn't exist");
	}

	size_t index = getPersonByIndex(person);
	if (index == -1) {
		throw std::exception("Couldn't find person");
	}

	delete people[index];
	people[index] = nullptr;
	size--;
	return *this;
}

Person* Group::operator[](const char* egn) const
{
	for (int i = 0; i < size; i++) {
		if (strcmp(people[i]->getEgn(), egn) == 0) {
			return people[i];
		}
	}
	return nullptr;
}

bool Group::operator()(const Person& person) const
{
	for (int i = 0; i < size; i++) {
		if (*people[i] == person) {
			return true;
		}
	}
	return false;
}

size_t Group::getSize() const
{
	return size;
}

size_t Group::getPersonByIndex(const Person& person) const
{
	if (!this->operator()(person)) {
		throw std::exception("Person doesn't exist");
	}

	for (int i = 0; i < size; i++) {
		if (*people[i] == person) {
			return i;
		}
	}
	return -1;
}

size_t Group::operator()() const
{
	return size;
}

Group operator+(const Group& curr, Person& newPerson)
{
	Group newGroup(curr);
	newGroup += newPerson;
	return newGroup;
}

Group operator-(const Group& curr, const Person& person)
{
	Group newGroup(curr);
	newGroup -= person;
	return newGroup;
}
