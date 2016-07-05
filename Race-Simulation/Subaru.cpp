#include "Subaru.h"

Subaru::Subaru(char* name, int hp, int maxSpeed) :
Car(name, hp, maxSpeed)
{
	set_name(name);
	set_hp(hp);
	set_maxSpeed(maxSpeed);
	set_seats(2);
	set_safety(30);
}