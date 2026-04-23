#ifndef CONTEST_H
#define CONTEST_H
#include <iostream>

class Contest {
	std::string* teams; // 팀명 배열
	int* scores;   // 팀별 점수 배열, 동점 없음
	int size;      // 팀의 개수
public:
	Contest(int size);           // size 만큼 teams와 scores에 동적 메모리 할당
	Contest(const Contest& src); //복사생성자
	~Contest();                  //할당받은 동적 메모리 반환
	void read();                 // 팀 수만큼 키보드로부터 팀명과 점수 입력
	int getSize() { return size; }
	int getScore(int index) { return scores[index]; }
	std::string getTeam(int index) { return teams[index]; }
};

#endif 