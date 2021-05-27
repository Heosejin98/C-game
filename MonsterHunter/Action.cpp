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
	while (1) {
		cout << '-' + name + "�� ������ �����ϼ���-" << endl;
		cout << "[ (1) ����(2) �ü�(3) ������ ]" << endl;
		cout << "���ڸ� �Է��� �ּ��� : ";
		cin >> job;
		system("cls");
		if (job < 4) {
			if (job == 1)
				player = new Knight(name);
			else if (job == 2)
				player = new Archer(name);
			else if (job == 3)
				player = new Wizard(name);
			break;
		}
		else
			cout << "ERROR - ��Ȯ�� ���� �Է��ϼ���" << '\n' << endl;
	}

	Show_main(name);
}

void Action::Show_main(string name) {
	int choice;
	//stat[6] = 0 : �ִ�HP, 1 : �ִ�MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����HP
	while (1) {
		cout << "=====" + name + "���� ����ȭ���Դϴ� =====" << endl;
		if (player->get_stat(0) != player->get_stat(5)) { //ü�� �ڵ� ȸ��
			player->set_stat(5, player->get_stat(0)); //����HP�� �ִ� HP�� ����
			cout << "-ü���� ��� ȸ���Ǿ����ϴ�-" << '\n' << endl;
		}
		cout << "[ (1)ĳ���� ���� Ȯ�� (2)����� ���� (3)���� (4)�κ��丮 ���� (5)������ ]" << endl;
		cout << "���ڸ� �Է��� �ּ��� : ";
		cin >> choice;
		system("cls");
		if (choice < 5) {
			switch (choice) {
			case 1:
				player->State(); //ĳ���� ���� Ȯ��
				break;
			case 2: {
				int map = player->move_map();
				Monster* M1 = new Monster(map); //int�� string����
				fight(player, M1, map);
				break;
			}
			}
		}
		else if (choice == 5)
			break;
		else
			cout << "ERROR - ��Ȯ�� ���� �Է��ϼ���" << '\n' << endl;
	} //while ����
}

void Action::fight(Human* P1, Monster* M1, int map) {
	double attack=0.0; //������
	int choice; //���� ����
	bool escape = false; //���� (true = ����, false = ����)
	if (map == 1) {
		cout << "=====[��]=====" << endl;
		Sleep(500); //0.5�� ������
		cout << M1->name << "��(��) ��Ÿ����!" << endl;
		while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//�÷��̾ ���Ͱ� ������ ���� �ݺ�
			cout << "=============" << endl;
			cout << "--[" + P1->name + "]�� HP : " << P1->get_stat(5) <<" / MP : " << P1->get_Current_MP() << " / ���� : " << M1->get_stat(4) << endl;
			cout << "--[" + M1->name + "]�� HP : " << M1->get_stat(5) << " / ���� : " << M1->get_stat(4) << endl;
			cout << "=============" << endl;
			cout << '\n';
			cout << P1->name << "�� ������?" << endl;
			cout << "[ (1)���� (2)��ų (3)�������� ]" << endl;
			cout << "���ڸ� �Է��� �ּ��� : ";
			cin >> choice;
			cout << '\n';
			system("cls");
				switch (choice) {
				case 1: //�Ϲ� ����
					attack_fight(P1, M1, attack);
					break;

				case 2: //��ų
					skill_fight(P1, M1, attack);
					break;
				case 3:
					escape_run(P1, M1, attack, escape);
					break;
				}
		} // while�� ��

		if (M1->get_Die() == true)
			cout << "���� �¸�!" << endl;
		else if (escape == true)
			cout << "=====�������� ���������ϴ�=====" << endl;
		cout << '\n';
		system("PAUSE"); //����Ϸ��� �ƹ� Ű�� �����ʽÿ�
		system("cls");
	}
	else if (map == 2) {
		cout << "=====[�縷]=====" << endl;
		Sleep(500); //0.5�� ������
		cout << M1->name << "��(��) ��Ÿ����!" << endl;
		while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//�÷��̾ ���Ͱ� ������ ���� �ݺ�
			cout << "=============" << endl;
			cout << "--[" + P1->name + "]�� HP : " << P1->get_stat(5) << " / MP : " << P1->get_Current_MP() << " / ���� : " << M1->get_stat(4) << endl;
			cout << "--[" + M1->name + "]�� HP : " << M1->get_stat(5) << " / ���� : " << M1->get_stat(4) << endl;
			cout << "=============" << endl;
			cout << '\n';
			cout << P1->name << "�� ������?" << endl;
			cout << "[ (1)���� (2)��ų (3)�������� ]" << endl;
			cout << "���ڸ� �Է��� �ּ��� : ";
			cin >> choice;
			cout << '\n';
			system("cls");
			switch (choice) {
			case 1: //�Ϲ� ����
				attack_fight(P1, M1, attack);
				break;

			case 2: //��ų
				skill_fight(P1, M1, attack);
				break;
			case 3:
				escape_run(P1, M1, attack, escape);
				break;
			}
		} // while�� ��

		if (M1->get_Die() == true)
			cout << "���� �¸�!" << endl;
		else if (escape == true)
			cout << "=====�������� ���������ϴ�=====" << endl;
		cout << '\n';
		system("PAUSE"); //����Ϸ��� �ƹ� Ű�� �����ʽÿ�
		system("cls");

	}
	else if (map == 3) {
		cout << "=====[������ ����]=====" << endl;
		Sleep(500); //0.5�� ������
		cout << M1->name << "��(��) ��Ÿ����!" << endl;
		while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//�÷��̾ ���Ͱ� ������ ���� �ݺ�
			cout << "=============" << endl;
			cout << "--[" + P1->name + "]�� HP : " << P1->get_stat(5) << " / MP : " << P1->get_Current_MP() << " / ���� : " << M1->get_stat(4) << endl;
			cout << "--[" + M1->name + "]�� HP : " << M1->get_stat(5) << " / ���� : " << M1->get_stat(4) << endl;
			cout << "=============" << endl;
			cout << '\n';
			cout << P1->name << "�� ������?" << endl;
			cout << "[ (1)���� (2)��ų (3)�������� ]" << endl;
			cout << "���ڸ� �Է��� �ּ��� : ";
			cin >> choice;
			cout << '\n';
			system("cls");
			switch (choice) {
			case 1: //�Ϲ� ����
				attack_fight(P1, M1, attack);
				break;

			case 2: //��ų
				skill_fight(P1, M1, attack);
				break;
			case 3:
				escape_run(P1, M1, attack, escape);
				break;
			}
		} // while�� ��

		if (M1->get_Die() == true)
			cout << "���� �¸�!" << endl;
		else if (escape == true)
			cout << "=====�������� ���������ϴ�=====" << endl;
		cout << '\n';
		system("PAUSE"); //����Ϸ��� �ƹ� Ű�� �����ʽÿ�
		system("cls");

	}
	else if (map == 4) {
		cout << "=====[�������]=====" << endl;
		Sleep(500); //0.5�� ������
		cout << M1->name << "��(��) ��Ÿ����!" << endl;
		while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//�÷��̾ ���Ͱ� ������ ���� �ݺ�
			cout << "=============" << endl;
			cout << "--[" + P1->name + "]�� HP : " << P1->get_stat(5) << " / MP : " << P1->get_Current_MP() << " / ���� : " << M1->get_stat(4) << endl;
			cout << "--[" + M1->name + "]�� HP : " << M1->get_stat(5) << " / ���� : " << M1->get_stat(4) << endl;
			cout << "=============" << endl;
			cout << '\n';
			cout << P1->name << "�� ������?" << endl;
			cout << "[ (1)���� (2)��ų (3)�������� ]" << endl;
			cout << "���ڸ� �Է��� �ּ��� : ";
			cin >> choice;
			cout << '\n';
			system("cls");
			switch (choice) {
			case 1: //�Ϲ� ����
				attack_fight(P1, M1, attack);
				break;

			case 2: //��ų
				skill_fight(P1, M1, attack);
				break;
			case 3:
				escape_run(P1, M1, attack, escape);
				break;
			}
		} // while�� ��

		if (M1->get_Die() == true)
			cout << "���� �¸�!" << endl;
		else if (escape == true)
			cout << "=====�������� ���������ϴ�=====" << endl;
		cout << '\n';
		system("PAUSE"); //����Ϸ��� �ƹ� Ű�� �����ʽÿ�
		system("cls");
	}
}
void Action::attack_fight(Human* P1, Monster* M1, double attack) { //�Ϲݰ��� �Լ�
	cout << P1->name + "�� ����!" << endl;
	attack = P1->get_stat(2); //�÷��̾� ����
	M1->input_damage(attack); //���� ������ ����
	Sleep(800); //0.8�� ������
	cout << P1->name + "��" << P1->get_stat(2) << "�� ������ �ߴ�!" << endl;
	cout << '\n';

	if (M1->get_stat(5) <= 0) //���� ü���� 0 ���ϰ� �Ǹ� ���� ����
		M1->Monster_Die(P1);
	else {
		Sleep(800);
		attack = M1->get_stat(2); //���� ����
		P1->input_damage(attack);
		cout << M1->name + "�� ����!" << endl;
		cout << P1->name + "�� " << M1->get_stat(2) << "�� �������� �Ծ���!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //�÷��̾� ����
		Sleep(800); //0.8�� ������
		cout << P1->name + "��" << attack << "�� �������� �Ծ���!" << endl;
		Sleep(300);
		P1->Player_Die();
	}
	Sleep(800); //0.8�� ������
	cout << '\n';
}
void Action::skill_fight(Human* P1, Monster* M1, double attack) { //��ų �Լ�
	double skill_damage;
	cout << P1->name + "�� ��ų ���!" << endl;
	Sleep(500);
	skill_damage = player->job_skill(player->get_powerstat());
	M1->input_damage(skill_damage); //����(��ų) ������ ����
	Sleep(800);
	cout << P1->name + "�� " << skill_damage << "�� ������ �ߴ�!" << endl;

	if (M1->get_stat(5) <= 0) //���� ü���� 0 ���ϰ� �Ǹ� ���� ����
		M1->Monster_Die(P1);
	else {
		Sleep(500);
		cout << '\n';
		attack = M1->get_stat(2); //���� ����
		P1->input_damage(attack);
		cout << M1->name + "�� ����!" << endl;
		Sleep(800);
		cout << P1->name + "�� " << attack << "�� �������� �Ծ���!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //�÷��̾� ����
		Sleep(800);
		cout << P1->name + "�� " << attack << "�� �������� �Ծ���!" << endl;
		P1->Player_Die();
	}
	cout << '\n';
}
void Action::escape_run(Human* P1, Monster* M1, double attack, bool escape) {
	srand((unsigned)time(0)); //�ð� �ʱ�ȭ
	int i = rand() % 5 + 1; //1~5������ ���� (=1/5Ȯ��)
	cout << "������ �õ���...!" << endl;
	Sleep(800);
	system("cls");
	if (i == 5) //���� ����
		escape = true;
	else {
		cout << "���� ����!" << endl;
		cout << '\n';
		Sleep(800);
		attack = M1->get_stat(2); //���� ����
		P1->input_damage(attack);
		cout << M1->name + "�� ����!" << endl;
		Sleep(800);
		cout << P1->name + "��" << attack << "�� �������� �Ծ���!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //�÷��̾� ����
		Sleep(800);
		cout << P1->name + "��" << attack << "�� �������� �Ծ���!" << endl;
		P1->Player_Die();
	}
}
/*
stat[6] = 0 : �ִ�HP, 1 : �ִ�MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����HP
map = (1)�� (2)�縷 (3)������ ���� (4)������� (5)���ư���
*/