/*#ifndef GARAGE_H
#define GARAGE_H
#include "Car.h"

class Garage
{
private:
	Car** cars;
	char* name;
	int number;
	int capacity;

	void delGarage();
	void copyGarage(const Garage& g);

public:
	Garage(char* new_name = "", int new_capacity = 8);
	Garage(const Garage& g);
	Garage& opreator = (const Garage& g);
	~Garage();

	void set_name(char* new_name);
	void set_capacity(int new_capacity);

	char* get_name();
	int get_capacity();
	int get_number();

};


#endif*/