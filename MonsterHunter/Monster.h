#include "Life.h"
#pragma once
#include <string>
#ifndef __Monster__H_
#define __Monster__H_
using namespace std;

class Monster : public Life{
	int drop_money; //드랍 머니
	// accessory : accessory; //나오는 악세서리 / 구현 안 해서 오류나니까 보류 
	int monster_skill;
public:
	int map; //출연지역, 맵
	int get_monster_skill();
	// accessory get_accessory(); / 위와 같은 이유
	int get_drop_money(); 
	Monster();
	Monster(int map); // 1. 숲 / 2. 사막 / 3. 버려진 도시 / 4. 엔드월드
};

#endif