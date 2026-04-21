#ifndef CHART_H
#define CHART_H

using namespace std;

class Chart {
	string title;
	int data[3] = { 0 };
	string color[3] = { "»¡°­", "ÆÄ¶û", "³ë¶û" };
public:
	Chart();
	Chart(string t);
	int getNumberOfColors() { return 3; };
	string getColor(int i);
	void add(int i, int count);
	void draw();
	~Chart();
};

#endif
