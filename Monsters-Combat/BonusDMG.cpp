using namespace std;
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BonusDMG.h"

void BonusDMG::set_BonusDmg()
{
	bonusDmg = rand() % 100 + 1;
}

int BonusDMG::get_BonusDmg()
{
	return bonusDmg;
}

void BonusDMG::Attack(Monster& m)
{
	float random = ((float)(rand() % 100 + 1) / 100);
	cout << random << endl;
	if (random > m.get_dc())
	{
		int random2 = (rand() % 100 + 1);
		if (random2 <= bonusDmg && m.alive() != 0)
		{
			m.set_health(m.get_health() - (get_damage() * 1.5));
			cout << get_name() << " increases its DAMAGE to " << get_damage() * 1.5 << " for the current attack." << endl;
			cout << get_name() << " hits " << m.get_name() << " with " << get_damage()
				<< " DAMAGE and decreases its HEALTH POINTS to " << m.get_health() << "." << endl;
			if (m.get_health() <= 0)
			{
				set_health(get_health() + 200);
				cout << get_name() << " WINS! " << m.get_name() << " DESTROYED!" << endl;
			}
		}
		else if (m.alive() != 0)
		{
			m.set_health(m.get_health() - get_damage());
			cout << get_name() << " hits " << m.get_name() << " with " << get_damage()
				<< " DAMAGE and decreases its HEALTH POINTS to " << m.get_health() << "." << endl;
			if (m.get_health() <= 0)
			{
				m.set_health(m.get_health() + 200);
				cout << get_name() << " WINS! " << m.get_name() << " DESTROYED!" << endl;
			}
		}
	}
	else
	{
		cout << m.get_name() << " dodges " << get_name() << "'s attack. " << endl;
	}

	cout << endl;
}

