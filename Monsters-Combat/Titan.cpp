using namespace std;
#include "Titan.h"

Titan::Titan(char* name, int health, int damage, float dc, int dmgBuff) :
Monster(name, health, damage, dc)
{
	set_DMGBuff();
	set_health(700);
	set_damage(130);
	set_dc(0.1);
}
