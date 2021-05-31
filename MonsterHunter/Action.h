#pragma once
#include "Monster.h"
#include "Human.h"
#include "Accessory.h"
#include "Drug.h"
#include "UI.h"
using namespace std;

class Action{
	void Show_main(Human* P1); //����ȭ�� ����
	void fight(Human* P1, Monster* M1, int map); //���� �ý��� (�������̽�)
	void attack_fight(Human* P1, Monster* M1); //�Ϲ� ����
	void skill_fight(Human* P1, Monster* M1); //��ų ����
	bool escape_run(Human* P1, Monster* M1, bool escape); //����
	void Shop(Human* P1); //����
	void buy_Accessory(Accessory* a, Human* P1); //��ű� ����
	void buy_Drug(Drug* a, Human* P1, int cnt); //���� ����
	void use_Drugs(Human* P1); //���� ���
	void add_Drug(int inven_idx, Human* P1, Drug* a);
	void add_Drug(int inven_idx, Human* P1, Drug* a, int cnt);
	void show_item(Human* P1); //�κ��丮 ����
	friend bool Human::operator!();

public:
	Action() {};
	void Run(); //���� �Լ�
};