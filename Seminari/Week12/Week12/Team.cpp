#include "Team.h"

Team::Team() : Group()
{
}

Team::Team(size_t cap) : Group(cap)
{
}

bool Team::operator()(Person& manager, Person& subordinate)
{
    if (!(Group::operator()(manager)) || !(Group::operator()(subordinate))) {
        return false;
    }

    Person* oldManager = subordinate.getManager();
    if (oldManager != nullptr) {
        oldManager->removeSubordinate(&subordinate);
    }

    subordinate.setManager(&manager);
    manager.addSubordinate(&subordinate);

    return true;
}

size_t Team::getManagersCount() const {
    size_t count = 0;
    for (size_t i = 0; i < getSize(); i++) {
        if (people[i]->hasSubordinates()) {
            count++;
        }
    }
    return count;
}

bool operator>(const Team& lhs, const Team& rhs)
{
    return lhs.getManagersCount() > rhs.getManagersCount();
}

bool operator<(const Team& lhs, const Team& rhs)
{
    return lhs.getManagersCount() <  rhs.getManagersCount();
}

bool operator>=(const Team& lhs, const Team& rhs)
{
    return lhs.getManagersCount() >= rhs.getManagersCount();
}

bool operator<=(const Team& lhs, const Team& rhs)
{
    return lhs.getManagersCount() <= rhs.getManagersCount();
}
