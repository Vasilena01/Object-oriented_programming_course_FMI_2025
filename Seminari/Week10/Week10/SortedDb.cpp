#include "SortedDb.h"

void SortedDb::sortBy(bool (*comparator)(const Student*, const Student*))
{
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (!comparator(students[j], students[j + 1])) {
                Student* temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
