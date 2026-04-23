#pragma once
#include<iostream>

class coffeeMachine {
	int coffee;
	int water;
	int sugar;
public:
	coffeeMachine(int c, int w, int s);
	int menu();
	void show();
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void fill();
	void wash();
};