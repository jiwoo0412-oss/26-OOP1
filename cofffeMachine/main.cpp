#include <iostream>
using namespace std;

#include "coffeeMachine.h"

int main(void) {
	coffeeMachine java(5, 10, 3);
	int choice;
	int run = 0;
	while (1) {
		choice = java.menu();
		if (choice == 1) {
			java.drinkEspresso();
			java.show();
			run++;
		}
		else if (choice == 2) {
			java.drinkAmericano();
			java.show();
			run++;
		}
		else if (choice == 3) {
			java.drinkSugarCoffee();
			java.show();
			run++;
		}
		else {
			cout << "시스템을 종료합니다" << endl;
			break;
		}
		if (run > 10) {
			java.wash();
			run = 0;
		}
	}
}