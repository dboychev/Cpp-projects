#ifndef VAMPIRE_H
#define VAMPIRE_H
#include "Regenerating.h"

class Vampire : public Regenerating
{
public:
	Vampire(char* name = "Vampire", int health = 600, int damage = 90, float dc = 0.4, int Regen = 0);
};

#endif