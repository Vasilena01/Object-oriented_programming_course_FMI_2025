#pragma once
#include "Peak.h"

class TPeak : public Peak
{
public:
	TPeak();
	TPeak(const char* mountainName, int height, const char* peakName);

	TPeak(const TPeak& other);
	TPeak& operator=(const TPeak& other);
	TPeak(TPeak&& other);
	TPeak& operator=(TPeak&& other);
	~TPeak();

	void printName() const override;
	const char* getPeakName() const;
private:
	char* peakName;

	void copyFrom(const TPeak& other);
	void moveFrom(TPeak&& other);
	void free();
};

