#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	char* name;
	int number;

	void copyPlayer(const Player& p);
	void delPlayer();
public:
	Player();
	Player(const Player& p);
	Player& operator= (const Player& p);
	~Player();

	void set_name(char* new_name);
	void set_number(int new_number);

	char* get_name();
	int get_number();

	void PLAY(Player& p);
	
};

#endif
