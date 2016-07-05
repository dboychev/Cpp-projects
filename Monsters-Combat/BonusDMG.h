#ifndef BONUSDMG_H
#define BONUSDMG_H
#include "Monster.h"

class BonusDMG : virtual public Monster
{
private:
	int bonusDmg;

public:
	void set_BonusDmg();
	int get_BonusDmg();
	void Attack(Monster& m);
};

#endif