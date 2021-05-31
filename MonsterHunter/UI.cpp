#include "UI.h"

#include <iostream>
using namespace std;

int UI::Shop_main() {

	std::cout << "�������� : � �Ϳ�! �� ���� �;��ٰ��!" << '\n' << endl;
	std::cout << "[ (1)��ű� ���� (2)���� ���� (3)������  ]" << endl;
	std::cout << "���ڸ� �Է��� �ּ��� : ";
	
	int select;
	std::cin >> select;

	return select;
}

int UI::Shop_Accessory(Human* P1) {

	int choice;
	std::cout << "�������� : ���� �׻� ������ �۰� ����!" << '\n' << endl;
	std::cout << "��� : " << P1->get_money() << '\n' << endl;
	std::cout << "(1) �������� [���ݷ� : +5 / ���� : +5 / ���� : 30G]" << endl;
	std::cout << "(2) ������ [���ݷ� : +10 / ���� : +20/ ���� : 140G]" << endl;
	std::cout << "(3) �ݹ��� [���ݷ� : +25 / ���� : +15/ ���� : 250G]" << endl;
	std::cout << "(4) ������� [���ݷ� : +200 / ���� : +100/ ���� : 400G]" << endl;
	std::cout << "------------------------------------------" << endl;
	std::cout << "���ڸ� �Է��� �ּ��� : ";
	cin >> choice;

	return choice;
}

int UI::Shop_Drug(Human* P1) {
	int choice;
	std::cout << "�������� : ������ ������ ���ۿ�� �Բ� ��ü �ɷ��� �÷�����!" << '\n' << endl;
	std::cout << "��� : " << P1->get_money() << '\n' << endl;
	std::cout << "(1) �������� [ HP : +10 / ���� : 15G]" << endl;
	std::cout << "(2) �Ķ����� [MP : +10 / ���� : 10G]" << endl;
	std::cout << "(3) ������ [HP : +100 / MP : +100 / ���� : 150G]" << endl;
	std::cout << "------------------------------------------" << endl;
	std::cout << "���ڸ� �Է��� �ּ��� : ";
	cin >> choice;

	return choice;
}

int UI::fight_main(Human* P1, Monster* M1) {
	int choice;
	std::cout << "==============" << endl;
	std::cout << "--[" + P1->name + "]�� HP : " << P1->get_stat(5) << " / MP : " << P1->get_Current_MP() << " / ���� : " << P1->get_stat(4) << endl;
	std::cout << "--[" + M1->name + "]�� HP : " << M1->get_stat(5) << " / ���� : " << M1->get_stat(4) << endl;
	std::cout << "==============" << endl;
	std::cout << '\n';
	std::cout << P1->name << "�� ������?" << endl;
	std::cout << "[ (1)���� (2)��ų (3) ���� ��� (4)�������� ]" << endl;
	std::cout << "���ڸ� �Է��� �ּ��� : ";
	cin >> choice;
	std::cout << '\n';
	return choice;
}


