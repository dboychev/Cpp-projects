#ifndef OGRE_H
#define OGRE_H
#include "DMGBuff.h"

class Ogre : public DMGBuff
{
public:
	Ogre(char* name = "Ogre", int health = 500, int damage = 120, float dc = 0.3, int dmgBuff = 0);
};

#endif