using namespace std;
#include <iostream>
#include <stdlib.h>
#include "Chimera.h"

Chimera::Chimera(char* name, int health, int damage, float dc, int Regen, int DMGBuff) :
Monster(name, health, damage, dc)
{
	set_Regen();
	set_DMGBuff();
	set_health(500);
	set_damage(115);
	set_dc(0.4);
}

void Chimera::Attack(Monster& m)
{
	float random = ((float)(rand() % 100 + 1) / 100);
	if (random > m.get_dc())
	{
		int random2 = (rand() % 100 + 1);
		if (random2 <= get_Regen())
		{
			set_health(get_health() * 1.3);
			cout << get_name() << " increases his HEALTH POINTS to " << get_health() << "." << endl;
		}

		int random3 = (rand() % 100 + 1);
		if (random3 <= get_DMGBuff())
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