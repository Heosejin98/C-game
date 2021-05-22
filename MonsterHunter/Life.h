#pragma once
#include <string>
using namespace std;
#ifndef __Life__H_
#define __Life__H_

class Life{
protected:
	double stat[9];
	//0 : HP, 1 : MP, 2 : 공격력, 3 : 방어력, 4 : 레벨, 5 : 경험치, 6 : 최대 경험치, 7 : 현재 HP, 8 : 현재 MP
public:
	string name; //이름

	Life();
	void Die(); //죽음
};
#endif // !Life