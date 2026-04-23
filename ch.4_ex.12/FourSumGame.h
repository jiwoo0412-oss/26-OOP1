#pragma once
#include "Player.h"

class FourSumGame {
	int numPlayers;
	Player* players;
public:
	FourSumGame(int n);
	~FourSumGame();
	void run();
};