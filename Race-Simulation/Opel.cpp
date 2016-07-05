#include "Opel.h"

Opel::Opel(char* name, int hp, int maxSpeed) :
Car(name, hp, maxSpeed)
{
	set_name(name);
	set_hp(hp);
	set_maxSpeed(maxSpeed);
	set_seats(5);
	set_safety(70);
}