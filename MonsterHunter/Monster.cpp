#include "Monster.h"
#include "Human.h"
#include <iostream>
using namespace std;

Monster::Monster() {}

Monster::Monster(int map){
	//(1)숲 (2)사막 (3)버려진 도시 (4)엔드월드 (5)돌아가기
	this->map = map;
	drop_money = 0;
	switch (this->map) {
	case 1:
		name = "슬라임";
		stat[0] = 20; //최대 HP
		stat[1] = 10; //최대 MP
		stat[2] = 2; //공격력
		stat[3] = 2; //방어력
		stat[4] = 1; //레벨
		stat[5] = 20; //현재 HP
		money = 5;
		Exp = 2;
		break;
	case 2:
		name = "꿈틀이";
		stat[0] = 40; //최대 HP
		stat[1] = 40; //최대 MP
		stat[2] = 10; //공격력
		stat[3] = 10; //방어력
		stat[4] = 5; //레벨
		stat[5] = 40; //현재 HP
		money = 20;
		Exp = 10;
		break;
	case 3:
		name = "기계생명체";
		stat[0] = 100; //최대 HP
		stat[1] = 60; //최대 MP
		stat[2] = 30; //공격력
		stat[3] = 15; //방어력
		stat[4] = 10; //레벨
		stat[5] = 100; //현재 HP
		money = 50;
		Exp = 30;
		break;
	case 4:
		name = "엔더타이거";
		stat[0] = 1024; //최대 HP
		stat[1] = 100; //최대 MP
		stat[2] = 50; //공격력
		stat[3] = 30; //방어력
		stat[4] = 30; //레벨
		stat[5] = 1024; //현재 HP
		money = 100;
		Exp = 50;
		break;
	}
}
void Monster::Monster_Die(Human* P1) {
	cout << "-----" << name << "이(가) 죽었습니다!-----" << endl;
	P1->set_money(money, true); //Human의 money += 몬스터의 money
	P1->set_Exp(Exp);
	cout << money << "의 돈 획득!" << endl;
	cout << Exp << "의 경험치 획득!" << endl;

	if (P1->get_Exp() >= P1->get_Max_Exp()) {
		P1->Level_Up();
		cout << "-----레벨업!!-----" << endl;
		cout << "Lv." << P1->get_stat(4) - 1 << " -> LV." << P1->get_stat(4) << endl;
		cout << "----------------" << endl;
	}

	Die = true; //죽으면 true
}