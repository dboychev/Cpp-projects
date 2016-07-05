#include <iostream>
#include <stdlib.h>
#include <thread>
#include <chrono>
using namespace std;
#include "Monster.h"

Monster::Monster(char* new_name, int new_health, int new_damage, float new_dc)
{
	set_name(new_name);
	set_health(new_health);
	set_damage(new_damage);
	set_dc(new_dc);
}

Monster::Monster(const Monster& m)
{
	copyMonster(m);
}

Monster& Monster::operator=(const Monster& m)
{
	if (this != &m)
	{
		delMonster();
		copyMonster(m);
	}

	return *this;
}

Monster::~Monster()
{
	delMonster();
}

void Monster::set_name(char* new_name)
{
	name = new char[strlen(new_name) + 1];
	strcpy_s(name, strlen(new_name) + 1, new_name);
}

void Monster::set_health(int new_health)
{
	health = new_health;
}

void Monster::set_damage(int new_damage)
{
	damage = new_damage;
}

void Monster::set_dc(float new_dc)
{
	dc = new_dc;
}

const char* Monster::get_name()
{
	return name;
}

int Monster::get_health() const
{
	return health;
}

int Monster::get_damage() const
{
	return damage;
}

float Monster::get_dc() const
{
	return dc;
}

bool Monster::alive() const
{
	if (health > 0)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

void Monster::print() const
{
	cout << "Monster " << name << endl;
	cout << "HP " << health << endl;
	cout << "DMG " << damage << endl;
	cout << "Dodge Chance " << dc << endl;
}

void Monster::Combat(Monster& m)
{
	cout << get_name() << " VS " << m.get_name() << endl;
	cout << get_health() << " HP " << m.get_health() << endl;
	cout << get_damage() << " DMG " << m.get_damage() << endl;
	int random = rand() % 2;
	if (random == 1)
	{
		while (this->alive() != 0 && m.alive() != 0)
		{
			Attack(m);
			this_thread::sleep_for(chrono::seconds(1));
			if (m.alive() != 0)
			{
				m.Attack(*this);
				this_thread::sleep_for(chrono::seconds(1));
			}
		}
	}

	else
	{
		while (this->alive() != 0 && m.alive() != 0)
		{
			m.Attack(*this);
			this_thread::sleep_for(chrono::seconds(1));
			if (this->alive() != 0)
			{
				Attack(m);
				this_thread::sleep_for(chrono::seconds(1));
			}
		}
	}
}

ostream& operator<<(ostream& out, const Monster &m)
{
	
	return out;
}

void Monster::copyMonster(const Monster& m)
{
	name = nullptr;
	set_name(m.name);
	set_health(m.health);
	set_damage(m.damage);
	set_dc(m.dc);
}

void Monster::delMonster()
{
	delete[] name;
}