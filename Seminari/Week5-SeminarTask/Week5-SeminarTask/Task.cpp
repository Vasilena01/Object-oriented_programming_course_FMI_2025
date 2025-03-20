#include "Task.h"

Task::Task()
{
    description = nullptr;
    priority = 0;
    status = false;
    duration = 0;
}

Task::Task(const char* description)
{
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
    priority = 0;
    status = false;
    duration = 0;
}

Task::Task(std::ifstream& ifs)
{
    size_t strlen = 0;
    ifs.read((char*)&strlen, sizeof(strlen));
    description = new char[strlen + 1];
    char* newDesc = nullptr;
    ifs.read(newDesc, strlen);
    strcpy(description, newDesc);
    ifs.read((char*)&priority, sizeof(priority));
    ifs.read((char*)&status, sizeof(status));
    ifs.read((char*)&duration, sizeof(duration));
    delete[] newDesc;
}

Task::Task(const Task& other)
{
    copyFrom(other);
}

Task& Task::operator=(const Task& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

void Task::operator>>(std::ofstream& ofs)
{
    size_t strsize = strlen(description);
    ofs.write((const char*)&strsize, sizeof(strsize));
    ofs.write((const char*)&description, sizeof(description));
    ofs.write((const char*)&priority, sizeof(priority));
    ofs.write((const char*)&status, sizeof(status));
    ofs.write((const char*)&duration, sizeof(duration));
}

Task::~Task()
{
    free();
}

const char* Task::getDescription() const
{
    return description;
}

unsigned Task::getPriority() const
{
    return priority;
}

bool Task::getStatus() const
{
    return status;
}

int Task::getDuration() const
{
    return duration;
}

void Task::setStatus()
{
    status = true;
}

const Task& Task::compareTasks(const Task& other)
{
    if (priority == other.priority)
    {
        if (duration < other.duration)
        {
            return *this;
        }
        else
        {
            return other;
        }
    }
    else if (priority > other.priority)
    {
        return *this;
    }
    else
    {
        return other;
    }
}

void Task::copyFrom(const Task& other)
{
    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);
    priority = other.priority;
    status = other.status;
    duration = other.duration;
}

void Task::free()
{
    delete[] description;
}
