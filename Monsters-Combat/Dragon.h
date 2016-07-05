#ifndef DRAGON_H
#define DRAGON_H
#include "BonusDMG.h"

class Dragon : public BonusDMG
{
public:
	Dragon(char* name = "Dragon", int health = 600, int damage = 105, float dc = 0.3, int bonusDmg = 0);
};

#endif