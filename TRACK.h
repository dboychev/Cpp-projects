#ifndef TRACK_H
#define TRACK_H
#include "Car.h"
#include "Sports.h"
#include "Luxury.h"
#include "Family.h"

class Track
{
private:
	char* name;
	int length;
	int laps;

	void copyTrack(const Track& c);
	void delTrack();

public:
	Track(char* new_name = "TRACK", int new_length = 800, int new_laps = 1);
	Track(const Track& t);
	Track& operator=(const Track& t);
	~Track();

	void set_name(char* new_name);
	void set_length(int new_length);
	void set_laps(int new_laps);

	const char* get_name();
	int get_length() const;
	int get_laps() const;

	void RACE(Car& A, Car& B);
};

#endif