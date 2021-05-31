#pragma once
#include "Monster.h"
#include "Human.h"
#include "Accessory.h"
#include "Drug.h"
#include "UI.h"
using namespace std;

class Action{
	void Show_main(Human* P1); //메인화면 제어
	void fight(Human* P1, Monster* M1, int map); //전투 시스템 (인터페이스)
	void attack_fight(Human* P1, Monster* M1); //일반 공격
	void skill_fight(Human* P1, Monster* M1); //스킬 공격
	bool escape_run(Human* P1, Monster* M1, bool escape); //도망
	void Shop(Human* P1); //상점
	void buy_Accessory(Accessory* a, Human* P1); //장신구 구매
	void buy_Drug(Drug* a, Human* P1, int cnt); //물약 무개
	void use_Drugs(Human* P1); //물약 사용
	void add_Drug(int inven_idx, Human* P1, Drug* a);
	void add_Drug(int inven_idx, Human* P1, Drug* a, int cnt);
	void show_item(Human* P1); //인벤토리 열람
	friend bool Human::operator!();

public:
	Action() {};
	void Run(); //실행 함수
};