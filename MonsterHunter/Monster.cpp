#include "Monster.h"
#include <iostream>
using namespace std;

Monster::Monster() {}
//double stat[6];
//0 : 최대HP, 1 : 최대MP, 2 : 공격력, 3 : 방어력, 4 : 레벨, 5 : 현재HP / 최대 경험치, 7 : 현재 HP, 8 : 현재 MP
//stat[0] = 50; // 최대HP
//stat[1] = 50; // 최대MP
//stat[2] = 10; //공격력
//stat[3] = 10; //방어력
//stat[4] = 1; //레벨
//stat[5] = 50; //현재 HP

Monster::Monster(int map){
	//(1)숲 (2)사막 (3)버려진 도시 (4)엔드월드 (5)돌아가기
	this->map = map;
	drop_money = 0;
	switch (this->map) {
	case 1:
		name = "슬라임";
		stat[0] = 10; //최대 HP
		stat[1] = 10; //최대 MP
		stat[2] = 2; //공격력
		stat[3] = 2; //방어력
		stat[4] = 1; //레벨
		stat[5] = 10; //현재 HP
		break;
	case 2:
		name = "꿈틀이";
		break;
	case 3:
		name = "기계생명체";
		break;
	case 4:
		name = "엔더타이거";
		break;
	}
}