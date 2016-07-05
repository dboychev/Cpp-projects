#ifndef WEREWOLF_H
#define WEREWOLF_H
#include "Regenerating.h"

class Werewolf : public Regenerating
{
public:
	Werewolf(char* name = "Werewolf", int health = 550, int damage = 100, float dc = 0.5, int Regen = 0);
};

#endif
