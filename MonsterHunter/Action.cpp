#include <windows.h> //ȭ�� ����� ���
#include "Action.h"
#include "Human.h"
#include "Monster.h"
#include "Archer.h"
#include "Knight.h"
#include "Wizard.h"
#include <iostream>
using namespace std;

Human * player;

void Action::Run() {
	string name;
	int skill;
	int job = 0;
	cout << "[EvilHunter]" << endl;
	cout << "********** ȯ���մϴ� !!!  **********" << endl;
	cout << "�̸��� �Է��ϼ��� :  ";
	cin >> name;

	system("cls"); //ȭ�� �����
	cout << '-' + name + "�� ������ �����ϼ���-" << endl;
	cout << "[ (1) ����(2) �ü�(3) ������ ]" << endl;
	cout << "���ڸ� �Է��� �ּ��� : ";
	cin >> job;

	system("cls");
	if (job == 1)
		player = new Knight(name);
	else if (job == 2)
		player = new Archer(name);
	else if (job == 3)
		player = new Wizard(name);

	Show_main(name);
}

void Action::Show_main(string name) {
	int choice;

	cout << "=====" + name + "���� ����ȭ���Դϴ� =====" << endl;
	cout << "[ (1)ĳ���� ���� Ȯ�� (2)����� ���� (3)���� (4)�κ��丮 ���� (5)������ ]" << endl;
	cout << "���ڸ� �Է��� �ּ��� : ";
	cin >> choice;
	system("cls");

	switch (choice) {
	case 1:
		player->State(); //ĳ���� ���� Ȯ��
		break;
	case 2:
		int map = player->move_map();
		Monster* M1 = new Monster(map); //int�� string����
		fight(player, M1, map);
		break;
	}
}

void Action::fight(Human* P1, Monster* M1, int map) {
	int choice;
	if (map == 1) {
		cout << "=====[��]=====" << endl;
		cout << M1->name << "��(��) ��Ÿ����!" << endl;
		cout << "=============" << endl;
		cout << P1->name << "�� ������?" << endl;
		cout << "[ (1)���� (2)��ų (3)�������� ]" << endl;
		cout << "���ڸ� �Է��� �ּ��� : ";
		cin >> choice;
		cout << '\n';
		switch (choice) {
		case 1:
			break;
		case 2:
			cout << P1->name + " ���� ��ų ���!" << endl;
			double skill_damage = player->job_skill(player->get_powerstat());
			cout << "��ų���" << skill_damage << endl;
		}
	}
	else if (map == 2) {
		cout << "=====[�縷]=====" << endl;
		cout << M1->name << "��(��) ��Ÿ����!" << endl;
		cout << "=============" << endl;
		cout << "����� ������?" << endl;
		cout << "[ (1)���� (2)��ų (3)�������� ]" << endl;
		cout << "���ڸ� �Է��� �ּ��� : ";
		cin >> choice;
	}
	else if (map == 3) {
		cout << "=====[������ ����]=====" << endl;
		cout << M1->name << "��(��) ��Ÿ����!" << endl;
		cout << "=============" << endl;
		cout << "����� ������?" << endl;
		cout << "[ (1)���� (2)��ų (3)�������� ]" << endl;
		cout << "���ڸ� �Է��� �ּ��� : ";
		cin >> choice;
	}
	else if (map == 4) {
		cout << "=====[�������]=====" << endl;
		cout << M1->name << "��(��) ��Ÿ����!" << endl;
		cout << "=============" << endl;
		cout << "����� ������?" << endl;
		cout << "[ (1)���� (2)��ų (3)�������� ]" << endl;
		cout << "���ڸ� �Է��� �ּ��� : ";
		cin >> choice;
	}
}