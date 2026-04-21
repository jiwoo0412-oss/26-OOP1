#include "Player.h"
#include "FourSumGame.h"
#include <iostream>

using namespace std;

FourSumGame::FourSumGame(int n) {
	numPlayers = n;
	players = new Player[n];
	srand((unsigned int)time(0));
}
FourSumGame::~FourSumGame() {
	delete[] players;
}
void FourSumGame::run() {
	cout << numPlayers << "명이 Four Sum 게임을 시작합니다." << endl;
	for (int i = 0; i < numPlayers; i++) {
		string name;
		cout << "선수 이름>> ";
		cin >> name;
		(players + i)->setName(name);
	}

	int turn = 0;
	while (1) {
		Player& currentPlayer = players[turn % numPlayers];
		int predictedSum, userSum;

		cout << currentPlayer.getName() << "님, 예상 합과 수를 입력하세요>> ";
		cin >> predictedSum >> userSum;

		int com = rand() % 3;
		int realSum = userSum + com;

		cout << "에상 합 " << predictedSum << ", " << currentPlayer.getName() << ' ' << userSum << ", " << "컴 " << com << " : ";
		if (predictedSum == realSum) {
			cout << currentPlayer.getName() << "님 승리!!" << endl;
			break;
		}
		else {
			cout << "실패!!" << endl;
		}
		turn++;
	}

}