#include <iostream>
#include "Chart.h"

using namespace std;

Chart::Chart() {
	title = "차트";
}
Chart::Chart(string t) {
	title = t;
}
string Chart::getColor(int i) {
	return color[i];
}
void Chart::add(int i, int count) {
	data[i] = count;
}
void Chart::draw() {
	int total = 0;
	for (int i = 0; i < 3; i++) {
		total += data[i];
	}
	cout << title << "**********" << endl;
	for (int i = 0; i < 3; i++) {
		double percentage = (double)data[i] / total * 100;
		cout << color[i] << ": " << percentage << '%' << endl;
	}
	cout << "********************************" << endl;
}
Chart::~Chart() {
	for (int i = 0; i < 3; i++) {
		data[i] = 0;
	}
	cout << "차트 데이터는 저장되지 않고 사라집니다." << endl;
}
