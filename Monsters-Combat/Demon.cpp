using namespace std;
#include "Demon.h"

Demon::Demon(char* name, int health, int damage, float dc, int dmgBuff) :
Monster(name, health, damage, dc) 
{
	set_DMGBuff();
	set_health(500);
	set_damage(100);
	set_dc(0.5);
}
