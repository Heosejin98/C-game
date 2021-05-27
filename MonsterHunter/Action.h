#pragma once
#include "Monster.h"
#include "Human.h"

class Action{
	void Show_main(string name); //메인화면 제어
	void fight(Human* P1, Monster* M1, int map); //전투 시스템 (인터페이스)
	void attack_fight(Human* P1, Monster* M1, double attack); //일반 공격
	void skill_fight(Human* P1, Monster* M1, double attack); //스킬 공격
	bool escape_run(Human* P1, Monster* M1, double attack, bool escape); //도망
	void Exit(); //나가기
	void Shop(); //상점 열람
public:
	Action() {};
	void Run(); //실행 함수
};