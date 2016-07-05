using namespace std;
#include "Werewolf.h"

Werewolf::Werewolf(char* name, int health, int damage, float dc, int Regen) :
Monster(name, health, damage, dc)
{
	set_Regen();
	set_health(550);
	set_damage(100);
	set_dc(0.5);
}