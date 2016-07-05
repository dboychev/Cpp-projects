#ifndef LEXUS_H
#define LEXUS_H
#include "Luxury.h"

class Lexus : public Luxury
{
public:
	Lexus(char* name = "Lexus", int hp = 260, int maxSpeed = 260);
};

#endif 