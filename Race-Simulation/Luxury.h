#ifndef LUXURY_H
#define LUXURY_H
#include "Car.h"

class Luxury : virtual public Car
{
protected:
	Luxury();

private:
	static double bonus_maxSpeed;

public:
	double get_bonus_maxSpeed() const;
	void update_maxSpeed();
	void bonus();
	void race(Car& c, int length, int laps);


};

#endif