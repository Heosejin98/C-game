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
		stat[2] = 13; //���ݷ�
		stat[3] = 2; //����
		stat[4] = 1; //����
		stat[5] = 20; //���� HP
		money = 5;
		Exp = 3;
		break;
	case 2:
		name = "��Ʋ��";
		stat[0] = 30; //�ִ� HP
		stat[2] = 18; //���ݷ�
		stat[3] = 5; //����
		stat[4] = 5; //����
		stat[5] = 30; //���� HP
		money = 15;
		Exp = 10;
		break;
	case 3:
		name = "������ü";
		stat[0] = 100; //�ִ� HP
		stat[2] = 35; //���ݷ�
		stat[3] = 15; //����
		stat[4] = 12; //����
		stat[5] = 100; //���� HP
		money = 40;
		Exp = 30;
		break;
	case 4:
		name = "����Ÿ�̰�";
		stat[0] = 1024; //�ִ� HP
		stat[2] = 70; //���ݷ�
		stat[3] = 30; //����
		stat[4] = 30; //����
		stat[5] = 1024; //���� HP
		money = 100;
		Exp = 70;
		break;
	}
}
void Monster::Monster_Die(Human* P1) {
	std::cout << "-----" << name << "��(��) �׾����ϴ�!-----" << endl;
	P1->set_money(money, true); //Human�� money += ������ money
	P1->set_Exp(Exp);
	std::cout << money << "�� ��� ȹ��!" << endl;
	std::cout << Exp << "�� ����ġ ȹ��!" << endl;
	std::cout << "Lv." << P1->get_stat(4) - 1 << " -> LV." << P1->get_stat(4) << endl;

	if (P1->get_Exp() >= P1->get_Max_Exp()) {
		++P1;
		std::cout << "-----������!!-----" << endl;
		std::cout << "Lv." << P1->get_stat(4) - 1 << " -> LV." << P1->get_stat(4) << endl;
		std::cout << "----------------" << endl;
	}

	Die = true; //������ true
}