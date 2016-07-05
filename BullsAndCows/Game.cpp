#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	int turns = 0;
	winner = 0;
}

Game::Game(const Game& g)
{
	copyGame(g);
}

Game& Game::operator=(const Game& g)
{
	if (this != &g)
	{
		delGame();
		copyGame(g);
	}
	return *this;
}

Game::~Game()
{
	delGame();
}

void Game::PLAY(Player& pA, Player& pB)
{
	cout << "######################################\n##### Welcome to 'Bulls & Cows'! #####\n######################################" << endl << endl;
	
	enterNames(pA, pB);
	enterNumbers(pA, pB);
	
	while (winner == 0)
	{
		turn(pA, pB);
		if (winner == 1)
		{
			cout << "##### " << pA.get_name() << " WON!!! #####" << endl
				<< "##### " << pB.get_name() << "'s number: " << pB.get_number() << endl
				<< "##### " << pA.get_name() << "'s number: " << pA.get_number() << endl;
		}
		else
		{
			turn(pB, pA);
			if (winner == 1)
			{
				cout << "##### " << pB.get_name() << " WON!!! #####" << endl
					<< "##### " << pA.get_name() << "'s number: " << pA.get_number() << endl
					<< "##### " << pB.get_name() << "'s number: " << pB.get_number() << endl;
			}
		}
	}

}

bool Game::check(int number)
{
	int a, b, c, d;
	if (number < 1023 || number > 9876)
	{
		return 0;
	}

	else
	{
		a = number / 1000;
		b = number / 100 % 10;
		c = number / 10 % 10;
		d = number % 10;

		if (a == b || a == c || a == d || b == c || b == d || c == d)
		{
			return 0;
		}

		else
		{
			return 1;
		}
	}
}

void Game::enterNames(Player& pA, Player& pB)
{
	char* nameA = new char[15];
	char* nameB = new char[15];

	cout << endl << "Enter your name: " << endl;
	cin >> nameA;
	pA.set_name(nameA);

	cout << endl << "Enter name of second player: " << endl;
	cin >> nameB;
	pB.set_name(nameB);
	cout << endl;

	delete[] nameA;
	delete[] nameB;
}

void Game::enterNumbers(Player& pA, Player& pB)
{
	int numA = 1, numB = 1;

	while (check(numA) == 0)
	{
		cout << "Hallo, " << pA.get_name() << "! Enter your number: " << endl;
		cin >> numA;
		for (int i = 0; i < 25; i++)
		{
			cout << endl;
		}
	}
	pA.set_number(numA);

	while (check(numB) == 0)
	{
		cout << "Hallo, " << pB.get_name() << "! Enter your number: " << endl;
		cin >> numB;
		for (int i = 0; i < 25; i++)
		{
			cout << endl;
		}
	}
	pB.set_number(numB);
}

void Game::turn(Player& pA, Player& pB)
{
	int num = 1;
	while (check(num) == 0)
	{
		cout << pA.get_name() << ", it's your turn! Enter your prediction for "
			<< pB.get_name() << "'s 4-digit number: " << endl << "##### ";
		cin >> num;
		cout << endl;
	}

	guess(num, pB.get_number());
}

void Game::guess(int pred, int number)
{
	int bulls = 0, cows = 0;
	int a, b, c, d, _a, _b, _c, _d;
	a = pred / 1000;
	_a = number / 1000;
	b = pred / 100 % 10;
	_b = number / 100 % 10;
	c = pred / 10 % 10;
	_c = number / 10 % 10;
	d = pred % 10;
	_d = number % 10;

	if (a == _a)
	{
		bulls++;
	}

	if (b == _b)
	{
		bulls++;
	}

	if (c == _c)
	{
		bulls++;
	}

	if (d == _d)
	{
		bulls++;
	}

	if (a == _b || a == _c || a == _d)
	{
		cows++;
	}

	if (b == _a || b == _c || b == _d)
	{
		cows++;
	}

	if (c == _a || c == _b || c == _d)
	{
		cows++;
	}

	if (d == _a || d == _b || d == _c)
	{
		cows++;
	}

	if (bulls == 4)
	{
		winner = 1;
	}

	else
	{
		cout << "##### " << bulls << " BULLS, " << cows << " COWS" << " #####" << endl << endl;
	}
}

void Game::copyGame(const Game& g)
{
	
}

void Game::delGame()
{

}