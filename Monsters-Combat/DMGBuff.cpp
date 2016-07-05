#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "DMGBuff.h"
using namespace std;

void DMGBuff::set_DMGBuff()
{
	dmgBuff = rand() % 100 + 1;
}

int DMGBuff::get_DMGBuff()
{
	return dmgBuff;
}

void DMGBuff::Attack(Monster& m)
{
	float random = ((float)(rand() % 100 + 1) / 100);
	if (random > m.get_dc())
	{
		int random2 = (rand() % 100 + 1);
		if (random2 <= dmgBuff)
		{
			set_damage(get_damage() * 1.1);
			cout << get_name() << " increases its DAMAGE to " << get_damage() << "." << endl;
		}
		m.set_health(m.get_health() - get_damage());
		cout << get_name() << " hits " << m.get_name() << " with " << get_damage()
			<< " DAMAGE and decreases its HEALTH POINTS to " << m.get_health() << "." << endl;
		if (m.get_health() <= 0)
		{
			cout << get_name() << " WINS! " << m.get_name() << " DESTROYED!" << endl;
		}
	}

	else
	{
		cout << m.get_name() << " dodges " << get_name() << "'s attack. " << endl;
	}

	cout << endl;
}
