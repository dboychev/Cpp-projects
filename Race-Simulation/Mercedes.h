#ifndef MERCEDES_H
#define MERCEDES_H
#include "Sports.h"
#include "Luxury.h"

class Mercedes : virtual public Sports, virtual public Luxury
{
public:
	Mercedes(char* name = "Mercedes", int hp = 260, int maxSpeed = 280);
	void bonus();
	void race(Car& c, int length, int laps);
};

#endif