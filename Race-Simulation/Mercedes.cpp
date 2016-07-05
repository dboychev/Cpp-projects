#include "Mercedes.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <iomanip>
using namespace std;

Mercedes::Mercedes(char* name, int hp, int maxSpeed) :
Car(name, hp, maxSpeed)
{
	set_name(name);
	set_hp(hp);
	set_maxSpeed(maxSpeed);
	set_seats(4);
	set_safety(40);
}

void Mercedes::bonus()
{
	int random_bonus = rand() % 100 + 1;
	int random_bonus2 = rand() % 100 + 1;
	int random_bonus_number = rand() % 100 + 1;
	int random_bonus_number2 = rand() % 100 + 1;

	int hp_temp = get_hp();
	int maxSpeed_temp = get_maxSpeed();

	if (random_bonus_number < random_bonus)
	{
		update_hp();
		cout << "! BONUS ! " << get_name() << ": " << hp_temp << " HP ---> " << get_hp() << endl;
	}

	if (random_bonus_number2 < random_bonus2)
	{
		update_maxSpeed();
		cout << "! BONUS ! " << get_name() << ": " << maxSpeed_temp << " MAX SPEED ---> " << get_maxSpeed() << endl;
	}
}

void Mercedes::race(Car& c, int length, int laps)
{
	cout << setw(22) << get_name() << " - VS - " << c.get_name() << endl;
	cout << setw(22) << get_hp() << " - HP - " << c.get_hp() << endl;
	cout << setw(21) << get_maxSpeed() << " - KM/H - " << c.get_maxSpeed() << endl;
	cout << setw(21) << get_seats() << " - SEATS - " << c.get_seats() << endl;
	cout << setw(21) << get_safety() << " % SAFE % " << c.get_safety() << endl;

	double time_A = 0;
	double time_B = 0;

	for (int i = 1; i < laps; i++)
	{
		this_thread::sleep_for(chrono::seconds(1));
		cout << setw(8) << "LAP: " << i << endl;

		double A = time_A;
		double B = time_B;

		time_A += lap(length);
		time_B += c.lap(length);

		if (A < B)
		{
			if (time_A > time_B)
			{
				this_thread::sleep_for(chrono::seconds(1));
				cout << endl << "!!! " << c.get_name() << " OUTRUN " << get_name() << " !!!" << endl;
				this_thread::sleep_for(chrono::seconds(1));
			}
		}

		if (B < A)
		{
			if (time_A < time_B)
			{
				this_thread::sleep_for(chrono::seconds(1));
				cout << endl << "!!! " << get_name() << " OUTRUN " << c.get_name() << " !!!" << endl;
				this_thread::sleep_for(chrono::seconds(1));
			}
		}

		if (A == B)
		{
			if (time_A < time_B)
			{
				this_thread::sleep_for(chrono::seconds(1));
				cout << endl << "!!! " << get_name() << " OUTRUN " << c.get_name() << " !!!" << endl;
				this_thread::sleep_for(chrono::seconds(1));
			}

			if (time_A > time_B)
			{
				this_thread::sleep_for(chrono::seconds(1));
				cout << endl << "!!! " << c.get_name() << " OUTRUN " << get_name() << " !!!" << endl;
				this_thread::sleep_for(chrono::seconds(1));
			}
		}

		this_thread::sleep_for(chrono::seconds(1));
		if (time_A <= time_B)
		{
			up_speed(lap(length));
			c.up_speed(lap(length));
			turn(length);
			this_thread::sleep_for(chrono::seconds(1));
			c.turn(length);
			this_thread::sleep_for(chrono::seconds(1));
			cout << get_name() << ": ";
			time(time_A);
			this_thread::sleep_for(chrono::seconds(1));
			cout << c.get_name() << ": ";
			time(time_B);
			this_thread::sleep_for(chrono::seconds(1));
			bonus();
			this_thread::sleep_for(chrono::seconds(1));
			c.bonus();
		}

		else if (time_B < time_A)
		{
			c.up_speed(lap(length));
			up_speed(lap(length));
			c.turn(length);
			this_thread::sleep_for(chrono::seconds(1));
			turn(length);
			this_thread::sleep_for(chrono::seconds(1));
			cout << c.get_name() << ": ";
			time(time_B);
			this_thread::sleep_for(chrono::seconds(1));
			cout << get_name() << ": ";
			time(time_A);
			this_thread::sleep_for(chrono::seconds(1));
			c.bonus();
			this_thread::sleep_for(chrono::seconds(1));
			bonus();
		}
		cout << endl;
	}

	double A = time_A;
	double B = time_B;

	time_A += lap(length);
	time_B += c.lap(length);

	if (A < B)
	{
		if (time_A > time_B)
		{
			this_thread::sleep_for(chrono::seconds(1));
			cout << endl << "!!! " << c.get_name() << " OUTRUN " << get_name() << " !!!" << endl;
			this_thread::sleep_for(chrono::seconds(1));
		}
	}

	if (B < A)
	{
		if (time_A < time_B)
		{
			this_thread::sleep_for(chrono::seconds(1));
			cout << endl << "!!! " << get_name() << " OUTRUN " << c.get_name() << " !!!" << endl;
		}
	}

	if (A == B)
	{
		if (time_A < time_B)
		{
			this_thread::sleep_for(chrono::seconds(1));
			cout << endl << "!!! " << get_name() << " OUTRUN " << c.get_name() << " !!!" << endl;
		}

		if (time_A > time_B)
		{
			this_thread::sleep_for(chrono::seconds(1));
			cout << endl << "!!! " << c.get_name() << " OUTRUN " << get_name() << " !!!" << endl;
		}
	}

	this_thread::sleep_for(chrono::seconds(1));
	cout << setw(8) << "LAP: " << laps << endl;
	this_thread::sleep_for(chrono::seconds(1));

	if (time_A < time_B)
	{
		cout << get_name() << " is getting close the FINAL line with " << get_speed() << " km/h." << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << c.get_name() << " is getting close to the FINAL line with " << c.get_speed() << " km/h." << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << get_name() << " WINS!" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << get_name() << " TIME: "; time(time_A);
		this_thread::sleep_for(chrono::seconds(1));
		cout << c.get_name() << " TIME: +"; time(time_B - time_A); cout << endl;
	}

	if (time_B < time_A)
	{
		cout << c.get_name() << " is getting close to the FINAL line with " << c.get_speed() << " km/h." << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << get_name() << " is getting close to the FINAL line with " << get_speed() << " km/h." << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << c.get_name() << " WINS!" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << c.get_name() << " TIME: "; time(time_B);
		this_thread::sleep_for(chrono::seconds(1));
		cout << get_name() << " TIME: +"; time(time_A - time_B); cout << endl;
	}

	if (time_A == time_B)
	{
		cout << get_name() << " is getting close the FINAL line with " << get_speed() << " km/h." << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << c.get_name() << " is getting close to the FINAL line with " << c.get_speed() << " km/h." << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << get_name() << " and " << c.get_name() << " are EQUAL!" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << "NO WINNER!" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		cout << get_name() << " and " << c.get_name() << " TIME: "; time(time_A);
	}
}