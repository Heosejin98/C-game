#pragma once
#include "Monster.h"
#include "Human.h"

class Action{
	void Show_main(string name); //메인화면 제어
	void fight(Human* P1, Monster* M1, int map); //전투 시스템
	void Exit(); //나가기
public:
	Action() {};
	void Run(); //실행 함수
};