//부모클래스에서 자식클래스 호출하면 오류!! (아마 부모 선언할때 자식은 선언되지 않았는데 호출하려고 하는거 때문인듯?)

#pragma once
#include <string>
#ifndef __Life__H_
#define __Life__H_
using namespace std;

class Life{
protected:
	int money; //골드
	int Exp; //경험치
	double stat[6];	//0 : 최대HP, 1 : 최대MP, 2 : 공격력, 3 : 방어력, 4 : 레벨, 5 : 현재HP
	bool Die = false; //true = 죽음, false = 생존
public:
	string name; //이름

	Life();
	void input_damage(double attack); //데미지 계산
	void full_HP(); //HP 풀 회복

	double get_stat(int i); //get 스텟 (스텟 이용 시)
	void set_Exp(int a); //set 경험치
	int get_Exp(); //get 경험치
	bool get_Die(); //죽음 표현
	void set_money(int a, bool oper); //set 골드
	void set_stat(int i, int b); //i = stat[i], b는 더할 값
};
#endif