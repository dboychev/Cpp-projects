/*#include <iostream>
using namespace std;
#include "Garage.h"

Garage::Garage(char* new_name, int new_capacity)
{
	set_name(new_name);
	set_capacity(new_capacity);
}

Garage(const Garage& g);
Garage& opreator = (const Garage& g);
~Garage();

void Garage::set_name(char* new_name)
{
	name = new char[strlen(new_name) + 1];
	strcpy_s(name, strlen(new_name) + 1, new_name);
}

void Garage::set_capacity(int new_capacity)
{
	capacity = new_capacity;
}

void Garage::copyGarage(const Garage& g)
{
	set_name(g.name);
	number = g.number;
	for (int i = 0; i < number; i++)
	{
		cars[i] = new Car(*g.cars[i]);
	}
}*/