#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include "Regenerating.h"

void Regenerating::set_Regen()
{
	Regen = rand() % 100 + 1;
}

int Regenerating::get_Regen()
{
	return Regen;
}

void Regenerating::Attack(Monster& m)
{
	float random = ((float)(rand() % 100 + 1) / 100);
	if (random > m.get_dc())
	{
		int random2 = (rand() % 100 + 1);
		if (random2 <= Regen)
		{
			set_health(get_health() * 1.3);
			cout << get_name() << " increases his HEALTH POINTS to " << get_health() << "." << endl;
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