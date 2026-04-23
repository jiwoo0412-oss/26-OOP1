#include "coffeeMachine.h"
#include<iostream>
#include <Windows.h>
using namespace std;

coffeeMachine::coffeeMachine(int c, int w, int s) {
	coffee = c;
	water = w;
	sugar = s;
}
int coffeeMachine::menu() {
	int choice;
	cout << "--- 메뉴 ---" << endl << "1. Espresso" << endl << "2. Americano" << endl << "3. Sugar Coffee" << endl << "4. System Exit" << endl;
	cout << "*메뉴를 선택하세요: ";
	cin >> choice;
	return choice;
}
void coffeeMachine::show() {
	cout << "커피머신 상태, 커피:" << coffee << "  물: " << water << "  설탕: " << sugar << endl << endl;
}
void coffeeMachine::drinkEspresso() {
	coffee -= 1;
	water -= 1;
	if (coffee <= 0 || water <= 0) {
		coffeeMachine::fill();
	}
	cout << "[에스프레소] 나왔습니다~" << endl;
}
void coffeeMachine::drinkAmericano() {
	coffee -= 1;
	water -= 2;
	if (coffee <= 0 || water <= 0) {
		coffeeMachine::fill();
	}
	cout << "[아메리카노] 나왔습니다~" << endl;
}
void coffeeMachine::drinkSugarCoffee() {
	coffee -= 1;
	water -= 2;
	sugar -= 1;
	if (coffee <= 0 || water <= 0 || sugar <= 0) {
		coffeeMachine::fill();
	}
	cout << "[설탕커피] 나왔습니다~" << endl;
}
void coffeeMachine::fill() {
	cout << "재료를 채우고 있습니다. 잠시 기다려주세요!" << endl;
	coffee = water = sugar = 10;
	Sleep(3000);
}
void coffeeMachine::wash() {
	cout << "세척이 필요합니다" << endl;
	cout << "세척중... 잠시 기다려주세요" << endl << endl;
	Sleep(5000);
}