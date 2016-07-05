#ifndef GAME_H
#define GAME_H
#include "Player.h"


class Game
{
private:
	int turns;
	bool winner = 0;

	void copyGame(const Game& g);
	void delGame();

public:
	Game();
	Game(const Game& g);
	Game& operator=(const Game& g);
	~Game();

	void PLAY(Player& pA, Player& pB);
	bool check(int number);
	void enterNames(Player& pA, Player& pB);
	void enterNumbers(Player& pA, Player& pB);
	void turn(Player& pA, Player& pB);
	void guess(int pred, int number);
};

#endif