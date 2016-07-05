#ifndef REGENERATING_H
#define REGENERATING_H
#include "Monster.h"

class Regenerating : virtual public Monster
{
private:
	int Regen;

public:
	void set_Regen();
	int get_Regen();
	void Attack(Monster& m);
	
};

#endif