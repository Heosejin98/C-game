#pragma once
#include "Monster.h"
#include "Human.h"

class Action{
	void Show_main(string name); //����ȭ�� ����
	void fight(Human* P1, Monster* M1, int map); //���� �ý���
	void Exit(); //������
public:
	Action() {};
	void Run(); //���� �Լ�
};