#pragma once
#include <iostream>

class Peak
{
public:
	Peak();
	Peak(const char* name, unsigned height);

	Peak(const Peak& other);
	Peak& operator=(const Peak& other);
	Peak(Peak&& other);
	Peak& operator=(Peak&& other);
	~Peak();

	virtual void printName() const = 0;

	unsigned getHeight() const;
	const char* getMountainName() const;
private:
	unsigned height;
	char* mountainName;

	void copyFrom(const Peak& other);
	void moveFrom(Peak&& other);
	void free();
};

