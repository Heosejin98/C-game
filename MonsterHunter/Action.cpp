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
#include "Accessory.h"
#include "item.h"
#include "Drug.h"

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
		if (player->get_stat(0) != player->get_stat(5) || player->get_Current_MP() != player->get_stat(1)) { //ü�� �ڵ� ȸ��
			player->full_HP();
			player->full_MP();
			cout << "-ü�°� ������ ��� ȸ���Ǿ����ϴ�-" << '\n' << endl;
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
			case 3: {
				Shop();
				break;
			}
			case 4: {
				  cout << "(1) ���� ���� / " << player->Drugs[0] << "��" << endl;
				  cout << "(2) �Ķ� ���� / " << player->Drugs[1] << "��" << endl;
				  cout << "(3) ������ / " << player->Drugs[2] << "��" << endl;}
			}
		}
		else if (choice == 5) {
			cout << "=====���������� ������ ����Ǿ����ϴ�=====" << endl;
			break;
		}
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
	}
	else if (map == 2) {
		cout << "=====[�縷]=====" << endl;
	}
	else if (map == 3) {
		cout << "=====[������ ����]=====" << endl;
	}
	else if (map == 4) {
		cout << "=====[�������]=====" << endl;
	}
	Sleep(500); //0.5�� ������
	cout << M1->name << "��(��) ��Ÿ����!" << endl;
	while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//�÷��̾ ���Ͱ� ������ ���� �ݺ�
		cout << "=============" << endl;
		cout << "--[" + P1->name + "]�� HP : " << P1->get_stat(5) << " / MP : " << P1->get_Current_MP() << " / ���� : " << P1->get_stat(4) << endl;
		cout << "--[" + M1->name + "]�� HP : " << M1->get_stat(5) << " / ���� : " << M1->get_stat(4) << endl;
		cout << "=============" << endl;
		cout << '\n';
		cout << P1->name << "�� ������?" << endl;
		cout << "[ (1)���� (2)��ų (3) ���� ��� (4)�������� ]" << endl;
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
		case 3: //���� ���
			use_Drugs(P1);
			break;
		case 4:
			escape = escape_run(P1, M1, attack, escape);
			break;
		default:
			cout << "ERROR - ��Ȯ�� ���� �Է��ϼ���" << endl;
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
void Action::attack_fight(Human* P1, Monster* M1, double attack) { //�Ϲݰ��� �Լ�
	double Player_attack;
	cout << P1->name + "�� ����!" << endl;
	Player_attack = P1->Damage_Cal(); //�÷��̾� ����
	M1->input_damage(Player_attack); //���� ������ ����
	Sleep(800); //0.8�� ������
	cout << P1->name + "��" << Player_attack << "�� ������ �ߴ�!" << endl;
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
		P1->Player_Die();
	}
	Sleep(800); //0.8�� ������
	cout << '\n';
}
void Action::skill_fight(Human* P1, Monster* M1, double attack) { //��ų �Լ�
	double skill_damage;
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
		P1->Player_Die();
	}
	cout << '\n';
}
bool Action::escape_run(Human* P1, Monster* M1, double attack, bool escape) {
	srand((unsigned)time(0)); //�ð� �ʱ�ȭ
	int i = rand() % 2 + 1; //1~5������ ���� (=1/5Ȯ��)
	cout << "������ �õ���...!" << endl;
	Sleep(800);
	system("cls");
	if (i == 2) //���� ����
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
		P1->Player_Die();
	}
	return escape;
}

void Action::Shop() { //����
	cout << "�������� : � �Ϳ�! �� ���� �;��ٰ��!" << endl;
	cout << "(1) ��ű� ���� (2) ���� ���� (3) ����ȭ������ " << endl;
	int select;
	cin >> select;
	switch (select){
		case 1: // ��ű� ���� ����
			int choice;
			cout << "(1) �������� [���ݷ� : +10 / ���� : +10 / ���� : 1000G]" << endl;
			cout << "(2) ������ [���ݷ� : +10 / ���� : +50/ ���� : 5000G]" << endl;
			cout << "(3) �ݹ��� [���ݷ� : +50 / ���� : +10/ ���� : 5000G]" << endl;
			cout << "(4) ������� [���ݷ� : +1024 / ���� : +50/ ���� : 100000G]" << endl;
			cout << "���� �Ͻ� ��ű��� �����ϼ��� !";
			cin >> choice;
			switch (choice){
					case 1: { // �������� ���� �� 
						if (player->get_money() >= 1000) {
							Accessory* Wood = new Accessory("��������", 10, 10, 1000);
							buy_Accessory(Wood);
							break;
						}
						else
							cout << "��ȭ�� �����մϴ�!" << endl;
						break;
					}
					case 2: { //������ ���� �� ����
						if (player->get_money() <= 5000) {
							Accessory* Silver = new Accessory("������", 10, 50, 5000);
							buy_Accessory(Silver);
							break;
						}
						else
							cout << "��ȭ�� �����մϴ�!";
						break;}
					case 3: {
						if (player->get_money() <= 8000) {
							Accessory* Gold = new Accessory("�ݹ���", 20, 100, 8000);
							buy_Accessory(Gold);
							break;
						}
						else
							cout << "��ȭ�� �����մϴ�!";
						break;}
					case 4: {
						if (player->get_money() >= 10000) {
							Accessory* King = new Accessory("�������", 1024, 50, 100000);
							buy_Accessory(King);
							break;
						}
						else
							cout << "��ȭ�� �����մϴ�!";
						break;}
				} //choice = 1 / switch ����
			break;
		case 2: {
			cout << "(1) �������� [ HP : +10 / ���� : 100G]" << endl;
			cout << "(2) �Ķ����� [MP : +10 / ���� : 80G]" << endl;
			cout << "(3) ������ [HP : +100 / MP : +100 / ���� : 150G]" << endl;
			cout << "���� �Ͻ� ������ �����ϼ��� !";
			cin >> choice;
			switch (choice) {
			case 1:
				if (player->get_money() >= 100) {
					Drug* Red = new Drug("��������", 10, 0, 100);
					buy_Drug(Red);
					break;
				}
				else
					cout << "��ȭ�� �����մϴ�!" << endl;
				break;
			case 2:
				if (player->get_money() >= 80) {
					Drug* Blue = new Drug("�Ķ�����", 10, 0, 80);
					buy_Drug(Blue);
					break;
				}
				else
					cout << "��ȭ�� �����մϴ�!" << endl;
				break;
			case 3:				
				if (player->get_money() >= 80) {
				Drug* Elixir = new Drug("������", 100, 100, 150);
				buy_Drug(Elixir);
				break;
			}
				  else
				cout << "��ȭ�� �����մϴ�!" << endl;
				break;

			}
			break;
			} //switch (select=2) ����

		default:
			break;
		} //switch (select) ����

	system("PAUSE"); //����Ϸ��� �ƹ� Ű�� �����ʽÿ�
	system("cls");
}


void Action::buy_Accessory(Accessory* a) {
	player->set_money(a->price, false); // false ����
	player->item_stat[0] = a->power;
	player->item_stat[1] = a->defense;
	cout << '['+a->itemname+']'+" ���� ����!" << endl;
	cout << "��� ���ݷ� : " << player->item_stat[0] << endl;
	cout << "��� ���� : " << player->item_stat[0] << endl;
}

void Action::buy_Drug(Drug* a) {
	player->set_money(a->price, false); // false ����
	if (a->itemname == "��������") {
		player->Drugs[0]++; //���� ������ �߰�
		cout << "[���� ����] ���� ����!" << endl;
	}
	else if (a->itemname == "�Ķ�����") {
		player->Drugs[1]++;
		cout << "[�Ķ� ����] ���� ����!" << endl;
	}
	else {
		player->Drugs[2]++;
		cout << "[������] ���� ����!" << endl;
	}
}

void Action::use_Drugs(Human* P1) {
	while (1) {
		int choice;
		cout << "(1) ���� ���� / "<< P1->Drugs[0] << "��" << endl;
		cout << "(2) �Ķ� ���� / " << P1->Drugs[1] << "��" << endl;
		cout << "(3) ������ / " << P1->Drugs[2] << "��" << endl;
		cout << "���ڸ� �Է��� �ּ��� : ";
		cin >> choice;
		system("cls");
		if (choice <= 3) {
			if (choice == 1) { //��������
				if (P1->Drugs[0] <= 0)
					cout << "[���� ����]�� �����ϴ�!" << endl;
				else {
					cout << "[���� ����] ���!" << endl;
					cout << "HP : " << P1->get_stat(5);
					P1->Drugs[0] --;
					if (P1->get_stat(5) + 10 > P1->get_stat(1))//����ü��+10 > ����ü�� 55 > 50
					{
						P1->full_HP();
					}
					else {
						P1->set_stat(5, 10); //stat[5] += 10
					}
					cout << " -> " << P1->get_stat(5);
				}
			} //if (choice == 1) ����
			else if (choice == 2) { //�Ķ� ����
				if (P1->Drugs[1] <= 0)
					cout << "[�Ķ� ����]�� �����ϴ�!" << endl;
				else {
					cout << "[�Ķ� ����] ���!" << endl;
					cout << "MP : " << P1->get_Current_MP();
					P1->Drugs[1] --;
					if (P1->get_Current_MP() + 10 > P1->get_stat(2))//����ü��+10 > ���� ���� 
					{
						P1->full_MP();
					}
					else {
						P1->set_Current_MP(10); //stat[5] += 10
					}

					cout << " -> " << P1->get_Current_MP();
				}
			}
			else if (choice == 3) { //������
				if (P1->Drugs[2] <= 0)
					cout << "[������]�� �����ϴ�!" << endl;
				else {
					cout << "[������] ���!" << endl;
					P1->Drugs[2] --;
					cout << "HP : " << P1->get_stat(5);
					if (P1->get_stat(5) + 10 > P1->get_stat(1))//����ü��+10 > ����ü��
					{
						P1->full_HP();
					}
					else {
						P1->set_stat(5, 100); //stat[5] += 10
					}
					cout << " -> " << P1->get_stat(5);
					cout << "/ MP : " << P1->get_Current_MP();
					if (P1->get_Current_MP() + 100 > P1->get_stat(2))//����ü��+10 > ���縶��
					{
						P1->full_MP();
					}
					else {						P1->set_Current_MP(100); //stat[5] += 10] += 10					}
					cout << " -> " << P1->get_Current_MP();
				}
			} //if (choice <= 3) ����
			break;
		}
		else {
			cout << "ERROR - ��Ȯ�� ���� �Է��ϼ���" << '\n' << endl;
		}
	} //while�� ����
}

	
/*
stat[6] = 0 : �ִ�HP, 1 : �ִ�MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����HP
map = (1)�� (2)�縷 (3)������ ���� (4)������� (5)���ư���
*/