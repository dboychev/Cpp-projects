#ifndef CHIMERA_H
#define CHIMERA_H
#include "Regenerating.h"
#include "DMGBuff.h"

class Chimera : virtual public Regenerating, virtual public DMGBuff
{
public:
	Chimera(char* name = "Chimera", int health = 500, int damage = 115, float dc = 0.4, int Regen = 0, int DMGBuff = 0);
	void Attack(Monster& m);
};


#endif