#ifndef DMGBUFF_H
#define DMGBUFF_H
#include "Monster.h"

class DMGBuff : virtual public Monster
{
private:
	int dmgBuff;

public:
	void set_DMGBuff();
	int get_DMGBuff();
	void Attack(Monster& m);
};

#endif