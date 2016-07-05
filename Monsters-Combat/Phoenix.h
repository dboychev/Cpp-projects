#ifndef PHOENIX_H
#define PHOENIX_H
#include "BonusDMG.h"

class Phoenix : public BonusDMG
{
public:
	Phoenix(char* name = "Phoenix", int health = 500, int damage = 110, float dc = 0.3, int bonusDmg = 0);
};


#endif