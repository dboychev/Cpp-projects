#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
	if (name == nullptr)
	{
		set_name("Player 1");
	}

	if (number == NULL)
	{
		set_number(1234);
	}
}

Player::Player(const Player& p)
{
	copyPlayer(p);
}

Player& Player::operator=(const Player& p)
{
	if (this != &p)
	{
		delPlayer();
		copyPlayer(p);
	}
	return *this;
}

Player::~Player()
{
	delPlayer();
}

void Player::set_name(char* new_name)
{
	name = new char[strlen(new_name) + 1];
	strcpy_s(name, strlen(new_name) + 1, new_name);
}

void Player::set_number(int new_number)
{
	number = new_number;
}

char* Player::get_name()
{
	return name;
}

int Player::get_number()
{
	return number;
}

void Player::PLAY(Player& p)
{
	cout << "Welcome to 'Bulls & Cows'!" << endl;
	char* nameA;
	char* nameB;

	cout << "Enter your name: " << endl;
	cin >> nameA;
	set_name(nameA);

	cout << "Enter name of 2nd player: " << endl;
	cin >> nameB;
	p.set_name(nameB);

	delete[] nameA;
	delete[] nameB;

	int numA, numB;

	while (numA < 1023 || numA > 9876 || numA / 1000 == numA / 100 % 10
		|| numA / 1000 == numA / 10 % 10 || numA % 10 || numA / 100 % 10 == numA / 10 % 10
		|| numA / 100 % 10 == numA % 10 || numA / 10 % 10 == numA % 10)
	{
		cout << "Hallo, " << get_name() << "! Enter your number: " << endl;
		cin >> numA;
	}
	set_number(numA);

	while (numB < 1023 || numB > 9876 || numB / 1000 == numB / 100 % 10
		|| numB / 1000 == numB / 10 % 10 || numB % 10 || numB / 100 % 10 == numB / 10 % 10
		|| numB / 100 % 10 == numB % 10 || numB / 10 % 10 == numB % 10)
	{
		cout << "Hallo, " << p.get_name() << "! Enter your number: " << endl;
		cin >> numB;
	}
	p.set_number(numB);
}

void Player::copyPlayer(const Player& p)
{
	set_name(p.name);
	set_number(p.number);
}

void Player::delPlayer()
{
	delete[] name;
}