#include "TRACK.h"
#include <iostream>
#include <iomanip>
using namespace std;

Track::Track(char* new_name, int new_length, int new_laps)
{
	set_name(new_name);
	set_length(new_length);
	set_laps(new_laps);
}

Track::Track(const Track& t)
{
	copyTrack(t);
}

Track& Track::operator=(const Track& t)
{
	if (this != &t)
	{
		delTrack();
		copyTrack(t);
	}
	return *this;
}

Track::~Track()
{
	delTrack();
}

void Track::set_name(char* new_name)
{
	name = new char[strlen(new_name) + 1];
	strcpy_s(name, strlen(new_name) + 1, new_name);
}

void Track::set_length(int new_length)
{
	if (new_length >= 800)
	{
		length = new_length;
	}

	else
	{
		length = 800;
	}
}

void Track::set_laps(int new_laps)
{
	if (new_laps < 1)
	{
		laps = 1;
	}

	else
	{
		laps = new_laps;
	}
}

const char* Track::get_name()
{
	return name;
}

int Track::get_length() const
{
	return length;
}

int Track::get_laps() const
{
	return laps;
}

void Track::RACE(Car& A, Car& B)
{
	cout << setw(27) << "TRACK: " << get_name() << endl;
	cout << setw(27) << "LENGTH: " << get_length() << " M" << endl;
	cout << setw(27) << "LAPS: " << get_laps() << endl;
	A.race(B, get_length(), get_laps());
}

void Track::copyTrack(const Track& c)
{
	set_name(c.name);
	set_length(c.length);
	set_laps(c.laps);
}

void Track::delTrack()
{
	delete[] name;
}