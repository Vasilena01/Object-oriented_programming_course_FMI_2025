#include "FilteredDb.h"

void FilteredDb::filter(bool (*predicate)(const Student*))
{
	for (int i = size - 1; i >= 0; i--) {
		if (students[i] && !predicate(students[i])) {
			removeByFn(students[i]->getFn());
		}
	}
}

void FilteredDb::limit(int N)
{
	int count = 0;

	for (int i = 0; i < size; ++i) {
		if (students[i]) {
			count++;
			if (count > N) {
				removeByFn(students[i]->getFn());
			}
		}
	}
}
