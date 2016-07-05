using namespace std;
#include "Cyclop.h"

Cyclop::Cyclop(char* name, int health, int damage, float dc, int bonusDmg) :
Monster(name, health, damage, dc)
{
	set_BonusDmg();
	set_health(700);
	set_damage(120);
	set_dc(0.1);
}