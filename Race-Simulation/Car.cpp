using namespace std;
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Car.h"

Car::Car(char* new_name, int new_hp, int new_maxSpeed)
{
	set_name(new_name);
	set_hp(new_hp);
	set_maxSpeed(new_maxSpeed);
	set_speed(0);
}

Car::Car(const Car& c)
{
	copyCar(c);
}

Car& Car::operator=(const Car& c)
{
	if (this != &c)
	{
		delCar();
		copyCar(c);
	}
	
	return *this;
}

Car::~Car()
{
	delCar();
}

void Car::set_name(char* new_name)
{
	name = new char[strlen(new_name) + 1];
	strcpy_s(name, strlen(new_name) + 1, new_name);
}

void Car::set_hp(int new_hp)
{
	hp = new_hp;
}

void Car::set_seats(int new_seats)
{
	seats = new_seats;
}

void Car::set_maxSpeed(int new_maxSpeed)
{
	maxSpeed = new_maxSpeed;
}

void Car::set_safety(int new_safety)
{
	safety = new_safety;
}

void Car::set_speed(double new_speed)
{
	if (new_speed > get_maxSpeed())
	{
		speed = get_maxSpeed();
	}

	else
	{
		speed = new_speed;
	}
}

const char* Car::get_name()
{
	return name;
}

int Car::get_hp() const
{
	return hp;
}

int Car::get_seats() const
{
	return seats;
}

int Car::get_maxSpeed() const
{
	return maxSpeed;
}

int Car::get_safety() const
{
	return safety;
}

double Car::get_speed() const
{
	return speed;
}

void Car::print() const
{
	cout << "Model: " << name << endl
		<< "Power: " << hp << " Horse Power" << endl
		<< "Seats: " << seats << endl
		<< "Max Speed: " << maxSpeed << " km/h" << endl
		<< "Safety Level: " << safety << " %" << endl;
}

double Car::acceleration() const
{
	return ((double)get_hp() / get_seats() / 25);
}

double Car::cur_speed(int second)
{
	double new_speed = get_speed();
	for (int i = 1; i <= second; i++)
	{
		if (new_speed < get_maxSpeed())
		new_speed += i * acceleration();
	}
	if (new_speed > get_maxSpeed())
	{
		new_speed = get_maxSpeed();
	}
	return new_speed;
}

void Car::up_speed(double second)
{
	for (int i = 1; i <= second; i++)
	{
		if (get_speed() < get_maxSpeed())
		{
			set_speed(get_speed() + acceleration());
		}
	}

	if (get_speed() > get_maxSpeed())
	{
		set_speed(get_maxSpeed());
	}
}

double Car::meters_passed(int second)
{
	double meters = 0;

	for (int i = 1; i <= second; i++)
	{
		meters = meters + (cur_speed(i)) / 3.6;
	}

	return meters;
}

double Car::lap(int meters)
{
	double i = 0;
	while (meters_passed(i) < meters)
	{
		i++;
	}

	double lap = (meters_passed(i) - meters) / cur_speed(i);

	return (i - 1) + lap;
}

void Car::bonus()	{}

void Car::turn(int meters)
{
	cout << get_name() << " is getting close to the TURN with " << cur_speed(lap(meters)) << " KM/H." << endl;

	slow_down(lap(meters));
}

void Car::slow_down(double seconds)
{
	int random = rand() % 100 + 1;
	if (random > get_safety())
	{
		double speed_temp = cur_speed(seconds);
		int safety_temp = get_safety();
		set_speed(cur_speed(seconds) * 0.4);
		set_safety(get_safety() * (0.9));
		cout << "! BAD TURN ! " << get_name() << ": " << speed_temp << " KM/H ---> " << get_speed() << " KM/H!" << endl;
		cout << "! BAD TURN ! " << get_name() << ": " << safety_temp << " SAFETY ---> " << get_safety() << " %." << endl;
	}
}

void Car::time(double seconds) const
{
	if (seconds > 59 && seconds < 3600)
	{
		cout << (int)seconds / 60 << " m, " << seconds - (((int)seconds / 60) * 60) << " s" << endl;
	}

	if (seconds <= 59)
	{
		cout << seconds << " s" << endl;
	}
}

void Car::race(Car& c, int length, int laps)	{}

void Car::copyCar(const Car& c)
{
	name = nullptr;
	set_name(c.name);
	set_hp(c.hp);
	set_seats(c.seats);
	set_maxSpeed(c.maxSpeed);
	set_safety(c.safety);
}

void Car::delCar()
{
	delete[] name;
}