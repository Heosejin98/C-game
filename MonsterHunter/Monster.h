#include "Life.h"
#pragma once
#include <string>
#ifndef __Monster__H_
#define __Monster__H_
using namespace std;

class Monster : public Life{
	int drop_money; //��� �Ӵ�
	// accessory : accessory; //������ �Ǽ����� / ���� �� �ؼ� �������ϱ� ���� 
	int monster_skill;
public:
	int map; //�⿬����, ��
	int get_monster_skill();
	// accessory get_accessory(); / ���� ���� ����
	int get_drop_money(); 
	Monster();
	Monster(int map); // 1. �� / 2. �縷 / 3. ������ ���� / 4. �������
};

#endif