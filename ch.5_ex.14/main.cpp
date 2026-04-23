#include <iostream>
#include <cstring>
using namespace std;

#include "Contest.h"

string decideGoldAward(Contest codingTest) {
	int bestTeam = 0;
	int bestScore = codingTest.getScore(0);
	for (int i = 0; i < codingTest.getSize(); i++) {
		if (codingTest.getScore(i) > bestScore)
			bestScore = codingTest.getScore(i);
		bestTeam = i;
	}
	return codingTest.getTeam(bestTeam);
}

int main() {
	Contest codingTest(6);
	codingTest.read();
	string team = decideGoldAward(codingTest);
	cout << "금상은 " << team << "팀입니다." << endl;
}