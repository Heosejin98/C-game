#include <windows.h> //ȭ�� ����� ���
#include <cstdlib> // =C�� stdlib.h
#include <ctime> //�ð� ���
#include "Action.h"
#include "Human.h"
#include "Monster.h"
#include "Archer.h"
#include "Knight.h"
#include "Wizard.h"
#include <iostream>
#include "Life.h"
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
	double attack; //������
	int choice; //���� ����
	bool escape = false; //���� (true = ����, false = ����)
	//stat[6] = 0 : �ִ�HP, 1 : �ִ�MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����HP
	if (map == 1) {
		cout << "=====[��]=====" << endl;
		cout << M1->name << "��(��) ��Ÿ����!" << endl;
		cout << "=============" << endl;
		while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//�÷��̾ ���Ͱ� ������ ���� �ݺ�
			cout << "--[" + P1->name + "]�� ü�� : " << P1->get_stat(5) << endl;
			cout << "--[" + M1->name + "]�� ü�� : " << M1->get_stat(5) << endl;
			cout << '\n';
			cout << P1->name << "�� ������?" << endl;
			cout << "[ (1)���� (2)��ų (3)�������� ]" << endl;
			cout << "���ڸ� �Է��� �ּ��� : ";
			cin >> choice;
			cout << '\n';
			system("cls");

				switch (choice) {
				case 1: //�Ϲ� ����
					cout << P1->name + "�� ����!" << endl;
					attack = P1->get_stat(2);
					M1->input_damage(attack); //���� ������ ����

					if (M1->get_stat(5) <= 0) //���� ü���� 0 ���ϰ� �Ǹ� ���� ����
						M1->Monster_Die();
					break;
				case 2: //��ų
					cout << P1->name + " ���� ��ų ���!" << endl;
					attack = player->job_skill(player->get_powerstat());
					M1->input_damage(attack); //����(��ų) ������ ����

					if (M1->get_stat(5) <= 0)
						M1->Monster_Die();
					break;
				case 3:
					srand((unsigned)time(0)); //�ð� �ʱ�ȭ
					int i = rand() % 5 + 1; //1~5������ ���� (=1/5Ȯ��)
					cout << i << endl;
					if (i == 5) //���� ����
						escape = true;
					else
						cout << "���� ����!" << endl;
					break;
				}
		} // while�� ��
		if (M1->get_Die() == true)
			cout << "���� �¸�!" << endl;
		else if (escape == true)
			cout << "�������� ���������ϴ�" << endl;
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
/*
stat[6] = 0 : �ִ�HP, 1 : �ִ�MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����HP
map = (1)�� (2)�縷 (3)������ ���� (4)������� (5)���ư���
*/