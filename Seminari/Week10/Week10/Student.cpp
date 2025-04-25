#include "Student.h"

Student::Student(const MyString& name, unsigned fn, unsigned course) : name(name), fn(fn), course(course)
{}

const MyString Student::getName() const
{
    return name;
}

unsigned Student::getFn() const
{
    return fn;
}

unsigned Student::getCourse() const
{
    return course;
}

void Student::setName(const MyString& name)
{
    this->name = name;
}

void Student::setFn(unsigned fn)
{
    this->fn = fn;
}

void Student::setCourse(unsigned course)
{
    this->course = course;
}

void Student::print() const
{
    std::cout << name.c_str() << fn << course;
}
