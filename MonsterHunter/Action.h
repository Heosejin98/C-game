#pragma once
#include "Monster.h"
#include "Human.h"
#include "Accessory.h"
#include "Drug.h"

class Action{
	void Show_main(string name); //����ȭ�� ����
	void fight(Human* P1, Monster* M1, int map); //���� �ý��� (�������̽�)
	void attack_fight(Human* P1, Monster* M1, double attack); //�Ϲ� ����
	void skill_fight(Human* P1, Monster* M1, double attack); //��ų ����
	bool escape_run(Human* P1, Monster* M1, double attack, bool escape); //����
	void Exit(); //������
	void Shop(); //���� ����
	void buy_Accessory(Accessory* a);
	void buy_Drug(Drug* a);
	void use_Drugs(Human* P1); //���� ���
public:
	Action() {};
	void Run(); //���� �Լ�
};