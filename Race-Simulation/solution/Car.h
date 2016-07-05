#ifndef CAR_H
#define CAR_H

class Car
{
private:
	char* name;
	int hp;
	int seats;
	int maxSpeed;
	int safety;
	double speed;

	void copyCar(const Car& c);
	void delCar();

public:
	Car(char* new_name = "", int new_hp = 0, int new_maxSpeed = 0);
	Car(const Car& c);
	Car& operator=(const Car& c);
	~Car();

	void set_name(char* new_name);
	void set_hp(int new_hp);
	void set_seats(int new_seats);
	void set_maxSpeed(int new_maxSpeed);
	void set_safety(int new_safety);
	void set_speed(double new_speed);
	
	const char* get_name();
	int get_hp() const;
	int get_seats() const;
	int get_maxSpeed() const;
	int get_safety() const;
	double get_speed() const;

	void print() const;

	double acceleration() const;
	double cur_speed(int second);
	void up_speed(double second);
	double meters_passed(int second);
	double lap(int meters);

	virtual void bonus();
	void turn(int meters);
	void slow_down(double seconds);
	void time(double seconds) const;

	virtual void race(Car& c, int length, int laps);
};

#endif 
