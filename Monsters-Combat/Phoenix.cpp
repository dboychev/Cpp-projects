using namespace std;
#include "Phoenix.h"

Phoenix::Phoenix(char* name, int health, int damage, float dc, int bonusDmg) :
Monster(name, health, damage, dc)
{
	set_BonusDmg();
	set_health(500);
	set_damage(110);
	set_dc(0.3);
}