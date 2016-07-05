using namespace std;
#include "Dragon.h"

Dragon::Dragon(char* name, int health, int damage, float dc, int bonusDmg) :
Monster(name, health, damage, dc)
{
	set_BonusDmg();
	set_health(600);
	set_damage(105);
	set_dc(0.3);
}