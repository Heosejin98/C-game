#include "Life.h"
#include "Human.h"
#pragma once
#include <string>
#ifndef __Monster__H_
#define __Monster__H_

class Monster : public Life{
	int drop_money; //��� �Ӵ�
public:
	int map; //�⿬����, ��

	Monster();
	Monster(int map); // 1. �� / 2. �縷 / 3. ������ ���� / 4. �������

	void Monster_Die(Human* P1); //���� ����

	int get_monster_skill();
	int get_drop_money();
};

#endif