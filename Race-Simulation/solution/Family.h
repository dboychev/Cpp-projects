#ifndef FAMILY_H
#define FAMILY_H
#include "Car.h"

class Family : virtual public Car
{
protected:
	Family();

private:
	static double bonus_safety;

public:
	double get_bonus_safety() const;
	void update_safety();
	void bonus();
	void race(Car& c, int length, int laps);

};

#endif