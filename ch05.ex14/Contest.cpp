#include "Contest.h"
using namespace std;

Contest::Contest(int size) {
	this->size = size;
	this->teams = new string[size];
	this->scores = new int[size];
}
Contest::Contest(const Contest& src) {
	this->size = src.size;
	this->teams = new string[size];
	this->scores = new int[size];
	for (int i = 0; i < size; i++) {
		this->teams[i] = src.teams[i];
		this->scores[i] = src.scores[i];
	}
}
Contest::~Contest() {
	if (teams) delete[] teams;
	if (scores) delete[] scores;
}
void Contest::read() {
	cout << size << "°³ ÀÔ·Â>> ";
	for (int i = 0; i < size; i++) {
		cin >> teams[i] >> scores[i];
	}
}