#ifndef TITAN_H
#define TITAN_H
#include "DMGBuff.h"

class Titan : public DMGBuff
{
public:
	Titan(char* name = "Titan", int health = 700, int damage = 130, float dc = 0.1, int dmgBuff = 0);
};

#endif