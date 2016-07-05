#ifndef MONSTER_H
#define MONSTER_H
#include <fstream>
#include <cstring>
using namespace std;
using std::ofstream;
using std::ifstream;

class Monster
{
private:
	char* name;
	int health;
	int damage;
	float dc;
	void copyMonster(const Monster& m);
	void delMonster();

public:
	Monster(char* new_name = "", int new_health = 0, int new_damage = 0, float new_dc = 0);
	Monster(const Monster& m);
	Monster& operator=(const Monster& m);
	~Monster();

	void set_name(char* new_name);
	void set_health(int new_health);
	void set_damage(int new_damage);
	void set_dc(float new_dc);

	const char* get_name();
	int get_health() const;
	int get_damage() const;
	float get_dc() const;

	bool alive() const;
	void print() const;
	virtual void Attack(Monster& m) = 0;
	void Combat(Monster& m);
	
	friend ostream& operator<<(ostream& out, const Monster& m);
};

#endif