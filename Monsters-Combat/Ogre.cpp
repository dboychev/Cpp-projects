using namespace std;
#include "Ogre.h"

Ogre::Ogre(char* name, int health, int damage, float hc, int dmgBuff) :
Monster(name, health, damage, hc)
{
	set_DMGBuff();
	set_health(500);
	set_damage(120);
	set_dc(0.3);
}