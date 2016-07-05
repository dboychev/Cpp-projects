#ifndef CYCLOP_H
#define CYCLOP_H
#include "BonusDMG.h"

class Cyclop : public BonusDMG
{
public:
	Cyclop(char* name = "Cyclop", int health = 700, int damage = 120, float dc = 0.1, int bonusDmg = 0);
};

#endif