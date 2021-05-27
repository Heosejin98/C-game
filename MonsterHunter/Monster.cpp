#include "Monster.h"
#include "Human.h"
#include <iostream>
using namespace std;

Monster::Monster() {}

Monster::Monster(int map){
	//(1)�� (2)�縷 (3)������ ���� (4)������� (5)���ư���
	this->map = map;
	drop_money = 0;
	switch (this->map) {
	case 1:
		name = "������";
		stat[0] = 20; //�ִ� HP
		stat[1] = 10; //�ִ� MP
		stat[2] = 2; //���ݷ�
		stat[3] = 2; //����
		stat[4] = 1; //����
		stat[5] = 20; //���� HP
		money = 5;
		Exp = 2;
		break;
	case 2:
		name = "��Ʋ��";
		stat[0] = 40; //�ִ� HP
		stat[1] = 40; //�ִ� MP
		stat[2] = 10; //���ݷ�
		stat[3] = 10; //����
		stat[4] = 5; //����
		stat[5] = 40; //���� HP
		money = 20;
		Exp = 10;
		break;
	case 3:
		name = "������ü";
		stat[0] = 100; //�ִ� HP
		stat[1] = 60; //�ִ� MP
		stat[2] = 30; //���ݷ�
		stat[3] = 15; //����
		stat[4] = 10; //����
		stat[5] = 100; //���� HP
		money = 50;
		Exp = 30;
		break;
	case 4:
		name = "����Ÿ�̰�";
		stat[0] = 1024; //�ִ� HP
		stat[1] = 100; //�ִ� MP
		stat[2] = 50; //���ݷ�
		stat[3] = 30; //����
		stat[4] = 30; //����
		stat[5] = 1024; //���� HP
		money = 100;
		Exp = 50;
		break;
	}
}
void Monster::Monster_Die(Human* P1) {
	cout << "-----" << name << "��(��) �׾����ϴ�!-----" << endl;
	P1->set_money(money, true); //Human�� money += ������ money
	P1->set_Exp(Exp);
	cout << money << "�� �� ȹ��!" << endl;
	cout << Exp << "�� ����ġ ȹ��!" << endl;

	if (P1->get_Exp() >= P1->get_Max_Exp()) {
		P1->Level_Up();
		cout << "-----������!!-----" << endl;
		cout << "Lv." << P1->get_stat(4) - 1 << " -> LV." << P1->get_stat(4) << endl;
		cout << "----------------" << endl;
	}

	Die = true; //������ true
}