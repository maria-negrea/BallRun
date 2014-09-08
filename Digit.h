#pragma once
#include "WorldObject.h"

class Digit : public WorldObject
{
	int digit;
public:
	Digit(int digit);
	~Digit();
};
