#pragma once
#include "Monster.h"
#include "Human.h"

class Action{
	void Show_main(string name); //����ȭ�� ����
	void fight(Human* P1, Monster* M1, int map); //���� �ý��� (�������̽�)
	void attack_fight(Human* P1, Monster* M1, double attack); //�Ϲ� ����
	void skill_fight(Human* P1, Monster* M1, double attack); //��ų ����
	bool escape_run(Human* P1, Monster* M1, double attack, bool escape); //����
	void Exit(); //������
	void Shop(); //���� ����
public:
	Action() {};
	void Run(); //���� �Լ�
};