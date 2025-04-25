#include "StudentDb.h"

StudentDb::StudentDb()
{
    capacity = 8;
    size = 0;
    students = new Student * [capacity] {nullptr};

}

StudentDb::StudentDb(const StudentDb& other)
{
    copyFrom(other);
}

StudentDb& StudentDb::operator=(const StudentDb& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

StudentDb::StudentDb(StudentDb&& other)
{
    moveFrom(std::move(other));
}

StudentDb& StudentDb::operator=(StudentDb&& other)
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

StudentDb::~StudentDb()
{
    free();
}

void StudentDb::add(Student* newStudent)
{
    if (size == capacity) {
        resize(capacity * 2);
    }

    int firstFreeIndx = findFirstFreeIndex();
    students[firstFreeIndx] = newStudent;
}

void StudentDb::add(const Student& newStudent)
{
    add(newStudent);
}

void StudentDb::removeByFn(unsigned fn)
{
    if (findByFn(fn) == nullptr) {
        throw std::exception("The student with the given fn doesn't exist in the db!");
    }

    for (int i = 0; i < size; i++) {
        Student* curr = students[i];
        if (curr && curr->getFn() == fn)
        {
            delete[] students[i];
            students[i] = nullptr;
            break;
        }
    }
    size--;
}

Student* StudentDb::findByFn(unsigned fn)
{
    for (int i = 0; i < size; i++) {
        Student* curr = students[i];
        if (curr->getFn() == fn)
        {
            return curr;
        }
    }

    return nullptr;
}

void StudentDb::display() const
{
    for (int i = 0; i < size; i++)
    {
        students[i]->print();
        std::cout << std::endl;
    }
}

int StudentDb::findFirstFreeIndex()
{
    for (int i = 0; i < size; i++) {
        if (students[i] == nullptr)
        {
            return i;
        }
    }
    return size;
}

void StudentDb::resize(size_t newCap)
{
    Student** newStudents = new Student * [newCap];
    for (int i = 0; i < size; i++) {
        newStudents[i] = students[i];
    }
    delete[] students;
    students = newStudents;
    capacity = newCap;
}

void StudentDb::copyFrom(const StudentDb& other)
{
    students = new Student * [other.capacity];
    for (int i = 0; i < other.size; i++) {
        students[i] = other.students[i];
    }

    size = other.size;
    capacity = other.capacity;
}

void StudentDb::moveFrom(StudentDb&& other)
{
    students = other.students;
    other.students = nullptr;
}

void StudentDb::free()
{
    for (int i = 0; i < size; i++)
    {
        delete students[i];
    }
    delete[] students;
}
