#ifndef DEMON_H
#define DEMON_H
#include "DMGBuff.h"

class Demon : public DMGBuff
{
public:
	Demon(char* name = "Demon",  int health = 500, int damage = 100, float dc = 0.5, int dmgBuff = 0);
};

#endif