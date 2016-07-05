#ifndef SPORTS_H
#define SPORTS_H
#include "Car.h"

class Sports : virtual public Car
{
protected:
	Sports();

private:
	static double bonus_hp;

public:
	double get_bonus_hp() const;
	void update_hp();
	void bonus();
	void race(Car& c, int length, int laps);
};

#endif