#ifndef SUBARU_H
#define SUBARU_H
#include "Sports.h"

class Subaru : public Sports
{
public:
	Subaru(char* name = "Subaru", int hp = 300, int maxSpeed = 280);
};

#endif