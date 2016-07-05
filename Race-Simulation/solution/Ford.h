#ifndef FORD_H
#define FORD_H
#include "Family.h"

class Ford : public Family
{
public:
	Ford(char* name = "Ford", int hp = 180, int maxSpeed = 220);
};

#endif