#include "Vampire.h"
using namespace std;

Vampire::Vampire(char* name, int health, int damage, float dc, int Regen) :
Monster(name, health, damage, dc)
{
	set_Regen();
	set_health(600);
	set_damage(90);
	set_dc(0.4);
}
