#include "Life.h"
#include "Human.h"
#pragma once
#include <string>
#ifndef __Monster__H_
#define __Monster__H_

class Monster : public Life{
	int drop_money; //드랍 머니
public:
	int map; //출연지역, 맵

	Monster();
	Monster(int map); // 1. 숲 / 2. 사막 / 3. 버려진 도시 / 4. 엔드월드

	void Monster_Die(Human* P1); //몬스터 죽음

	int get_monster_skill();
	int get_drop_money();
};

#endif