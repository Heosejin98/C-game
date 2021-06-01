#include "Action.h"
#include <windows.h> //ȭ�� ����� ���
#include <cstdlib> // =C�� stdlib.h
#include <ctime> //�ð� ���

#include "Life.h"
#include "Human.h"
#include "Archer.h"
#include "Knight.h"
#include "Wizard.h"
#include "Monster.h"

#include "Accessory.h"
#include "item.h"
#include "Drug.h"

#include <iostream>
using namespace std;



void Action::Run() {
	Human* player = NULL;
	string name;
	int skill;
	int job = 0;
	std::cout << "********** [EvilHunter] **********" << endl;
	std::cout << "�г����� �Է��� �ּ��� :  ";
	cin >> name;

	system("cls"); //ȭ�� �����
	std::cout << "=====" + name + "�� ȯ���մϴ� !!!=====" << '\n' << endl;
	while (1) {
		std::cout << "=====������ �����ϼ���=====" << endl;
		std::cout << "[ (1) ����(2) �ü�(3) ������ ]" << endl;
		std::cout << "���ڸ� �Է��� �ּ��� : ";
		cin >> job;
		if (job < 4) {
			if (job == 1) {
				player = new Knight(name);
				std::cout << "���� - ���� �Ϸ�!" << '\n' << endl;
				Sleep(1000);
				system("cls");
			}
			else if (job == 2) {
				player = new Archer(name);
				std::cout << "�ü� - ���� �Ϸ�!" << '\n' << endl;
				Sleep(1000);
				system("cls");
			}
			else if (job == 3) {
				player = new Wizard(name);
				std::cout << "������ - ���� �Ϸ�!" << '\n' << endl;
				Sleep(1000);
				system("cls");
			}
			break;
		}
		else {
			system("cls");
			std::cout << "ERROR - ��Ȯ�� ���� �Է��ϼ���" << '\n' << endl;
		}
	}

	Show_main(player);
}
void Action::Show_main(Human* P1) {
	int choice;
	while (1) {
		Human* player = P1;
		std::cout << "=====" + player->name + "���� ����ȭ���Դϴ� =====" << '\n' << endl;
		if (player->get_stat(0) != player->get_stat(5) || player->get_Current_MP() != player->get_stat(1)) { //ü�� �ڵ� ȸ��
			player->full_HP();
			player->full_MP();
			std::cout << "-HP�� MP�� ��� ȸ���Ǿ����ϴ�-" << '\n' << endl;
		}
		std::cout << "[ (1)ĳ���� ���� Ȯ�� (2)����� ���� (3)���� (4)�κ��丮 ���� (5)������ ]" << endl;
		std::cout << "���ڸ� �Է��� �ּ��� : ";
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
				if (map != 5)
					fight(player, M1, map);
				break;
			}
			case 3: {
				Shop(player);
				break;
			}
			case 4: {
				show_item(player);
				break;
			}
			}
		}
		else if (choice == 5) {
			std::cout << "*****���������� ������ ����Ǿ����ϴ�*****" << endl;
			delete P1;
			system("PAUSE");
			break;
		}
		else
			std::cout << "ERROR - ��Ȯ�� ���� �Է��ϼ���" << '\n' << endl;
		} //while ����
	}

void Action::fight(Human* P1, Monster* M1, int map) {

	int choice; //���� ����
	bool escape = false; //���� (true = ����, false = ����)
	if (map == 1) {
		std::cout << "=====[��]=====" << endl;
	}
	else if (map == 2) {
		std::cout << "=====[�縷]=====" << endl;
	}
	else if (map == 3) {
		std::cout << "=====[������ ����]=====" << endl;
	}
	else if (map == 4) {
		std::cout << "=====[�������]=====" << endl;
	}
	Sleep(500); //0.5�� ������
	std::cout << M1->name << "��(��) ��Ÿ����!" << endl;
	std::cout << "==============" << endl;
	while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//�÷��̾ ���Ͱ� ������ ���� �ݺ�
		system("PAUSE");
		system("cls");
		choice = UI::fight_main(P1, M1);
		system("cls");
		switch (choice) {
		case 1: //�Ϲ� ����
			attack_fight(P1, M1);
			break;
		case 2: //��ų
			skill_fight(P1, M1);
			break;
		case 3: //���� ���
			use_Drugs(P1);
			break;
		case 4:
			escape = escape_run(P1, M1, escape);
			break;
		default:
			std::cout << "ERROR - ��Ȯ�� ���� �Է��ϼ���" << endl;
		}
	} // while�� ��

	if (M1->get_Die() == true)
		std::cout << "���� �¸�!" << endl;
	else if (escape == true)
		std::cout << "=====�������� ���������ϴ�=====" << endl;
	std::cout << '\n';
	system("PAUSE"); //����Ϸ��� �ƹ� Ű�� �����ʽÿ�
	system("cls");
}
void Action::attack_fight(Human* P1, Monster* M1) { //�Ϲݰ��� �Լ�
	double Player_attack;
	std::cout << P1->name + "�� ����!" << endl;
	Player_attack = P1->Damage_Cal(); //�÷��̾� ����
	M1->input_damage(Player_attack); //���� ������ ����
	Sleep(800); //0.8�� ������
	std::cout << P1->name + "��" << Player_attack << "�� ������ �ߴ�!" << endl;
	std::cout << '\n';

	if (M1->get_stat(5) <= 0) //���� ü���� 0 ���ϰ� �Ǹ� ���� ����
		M1->Monster_Die(P1, M1);
	else {
		Sleep(800);
		double attack = M1->get_stat(2); //���� ����
		P1->input_damage(attack);
		std::cout << M1->name + "�� ����!" << endl;
		std::cout << P1->name + "�� " << M1->get_stat(2) << "�� �������� �Ծ���!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //�÷��̾� ����
		Sleep(800); //0.8�� ������
		P1->Player_Die(P1);
	}
	Sleep(800); //0.8�� ������
	std::cout << '\n';
}
void Action::skill_fight(Human* P1, Monster* M1) { //��ų �Լ�
	double skill_damage;
	Human* player = P1;
	Sleep(500);
	cout << "���� ���� : " << "LV." << player->get_stat(4) << " / MP : " << player->get_Current_MP()  << endl;
	cout << "-----------------------------" << endl;
	skill_damage = player->job_skill(player->get_powerstat());
	M1->input_damage(skill_damage); //����(��ų) ������ ����
	Sleep(800);
	std::cout << P1->name + "�� " << skill_damage << "�� ������ �ߴ�!" << endl;
	
	if (M1->get_stat(5) <= 0) //���� ü���� 0 ���ϰ� �Ǹ� ���� ����
		M1->Monster_Die(P1, M1);
	else {
		Sleep(500);
		std::cout << '\n';
		double attack = M1->get_stat(2); //���� ����
		P1->input_damage(attack);
		std::cout << M1->name + "�� ����!" << endl;
		Sleep(800);
		std::cout << P1->name + "�� " << attack << "�� �������� �Ծ���!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //�÷��̾� ����
		Sleep(800);
		P1->Player_Die(P1);
	}
	std::cout << '\n';
}
bool Action::escape_run(Human* P1, Monster* M1, bool escape) {
	srand((unsigned)time(0)); //�ð� �ʱ�ȭ
	int i = rand() % 5 + 1; //1~5������ ���� (=1/5Ȯ��)
	std::cout << "������ �õ���...!" << endl;
	Sleep(800);
	system("cls");
	if (i == 5) //���� ����
		escape = true;
	else {
		std::cout << "===���� ����!===" << endl;
		std::cout << '\n';
		Sleep(800);
		double attack = M1->get_stat(2); //���� ����
		P1->input_damage(attack);
		std::cout << M1->name + "�� ����!" << endl;
		Sleep(800);
		std::cout << P1->name + "��" << attack << "�� �������� �Ծ���!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //�÷��̾� ����
		Sleep(800);
		P1->Player_Die(P1);
	}
	return escape;
}

void Action::Shop(Human* P1) { //����
	Human* player = P1;
	int choice = 0;
	int select = UI::Shop_main();
	system("cls");
	switch (select){
		case 1: // ��ű� ���� ����
			choice = UI::Shop_Accessory(player);
			switch (choice){
					case 1: { // �������� ���� �� 
						if (player->get_money() >= 30) {
							Accessory* Wood = new Accessory("��������", 5, 5, 30);
							buy_Accessory(Wood, player);
							break;
						}
						else
							std::cout << "===��尡 �����մϴ�!===" << endl;
						system("PAUSE");
						break;
					}
					case 2: { //������ ���� �� ����
						if (player->get_money() >= 140) {
							Accessory* Silver = new Accessory("������", 10, 20, 140);
							buy_Accessory(Silver, player);
							break;
						}
						else
							std::cout << "===��尡 �����մϴ�!===" << endl;
						system("PAUSE");
						break;}
					case 3: {
						if (player->get_money() >= 250) {
							Accessory* Gold = new Accessory("�ݹ���", 25, 15, 250);
							buy_Accessory(Gold, player);
							break;
						}
						else
							std::cout << "===��尡 �����մϴ�!===" << endl;
						system("PAUSE");
						break;}
					case 4: {
						if (player->get_money() >= 400) {
							Accessory* King = new Accessory("�������", 200, 100, 400);
							buy_Accessory(King, player);
							break;
						}
						else
							std::cout << "===��尡 �����մϴ�!===" << endl;
						system("PAUSE");
						break;}
				} //choice = 1 / switch ����
			break;
		case 2: {
			int choice = UI::Shop_Drug(player);
			int cnt;
			std::cout << "���� �� ������ �Է��ϼ��� �ּ��� : ";
			cin >> cnt;

			switch (choice) {
			case 1:
				if (player->get_money() >= 15) {
					Drug* Red = new Drug("��������", 10, 0, 15);
					buy_Drug(Red, player, cnt);
					break;
				}
				else
					std::cout << "===��尡 �����մϴ�!===" << endl;
				system("PAUSE");
				break;
			case 2:
				if (player->get_money() >= 10) {
					Drug* Blue = new Drug("�Ķ�����", 0, 10, 10);
					buy_Drug(Blue, player, cnt);
					break;
				}
				else
					std::cout << "===��尡 �����մϴ�!===" << endl;
				system("PAUSE");
				break;
			case 3:				
				if (player->get_money() >= 150) {
				Drug* Elixir = new Drug("������", 100, 100, 150);
				buy_Drug(Elixir, player, cnt);
				break;
			}
				  else
				std::cout << "===��尡 �����մϴ�!===" << endl;
				system("PAUSE");
				break;

			}
			break;
			} //switch (select=2) ����

		default:
			break;
		} //switch (select) ����
	//system("PAUSE");
	system("cls");
}
void Action::buy_Accessory(Accessory* a, Human* P1) {
	system("cls");
	Human* player = P1;
	player->set_money(a->price, false); // false ����
	player->item_stat[0] = a->power;
	player->item_stat[1] = a->defense;
	player->equipment = a->itemname;
	std::cout << "�������� : ��, ����! �Ǹ��� ��ȭ��������!" << '\n' << endl;
	std::cout << '['+a->itemname+']'+" ���� ����!" << endl;
	std::cout << "��� ���ݷ� : " << player->item_stat[0] << endl;
	std::cout << "��� ���� : " << player->item_stat[0] << endl;
	system("PAUSE");
}
void Action::buy_Drug(Drug* a, Human* P1, int cnt) {
	system("cls");
	Human* player = P1;
	std::cout << "�������� : �ڷδ� ���Ǽ� �����ϱ� ������!" << '\n' << endl;
	if (a->itemname == "��������") {
		if(cnt==1)
			add_Drug(0, player, a);
		else
			add_Drug(0, player, a, cnt);
	}
	else if (a->itemname == "�Ķ�����") {
		if (cnt == 1)
			add_Drug(1, player, a);
		else
			add_Drug(1, player, a, cnt);
	}
	else {
		if (cnt == 1)
			add_Drug(2, player, a);
		else
			add_Drug(1, player, a, cnt);
	}
	system("PAUSE");
}	
void  Action::add_Drug(int inven_idx, Human* P1, Drug* a) {
	Human* player = P1;
	player->set_money(a->price, false); // false ����
	player->Drugs[inven_idx][0]++; //���� ������ �߰�
	player->Drugs[inven_idx][1] = a->plus_HP;
	player->Drugs[inven_idx][2] = a->plus_MP;
	std::cout << "["<<a->itemname <<"] ���� ����!" << endl;

	delete a;
}
void  Action::add_Drug(int inven_idx, Human* P1, Drug* a, int cnt) {
	Human* player = P1;
	player->set_money(a->price * cnt, false); // false ����
	player->Drugs[inven_idx][0] = cnt; //���� ������ �߰�
	player->Drugs[inven_idx][1] = a->plus_HP;
	player->Drugs[inven_idx][2] = a->plus_MP;
	std::cout << "[" << a->itemname << "] " << cnt <<"�� ���� ����!" << endl;
	delete a;
}

void Action::use_Drugs(Human* P1) {
	while (1) {
		int choice;
		std::cout << "(1) ���� ���� / "<< P1->Drugs[0][0] << "��" << endl;
		std::cout << "(2) �Ķ� ���� / " << P1->Drugs[1][0] << "��" << endl;
		std::cout << "(3) ������ / " << P1->Drugs[2][0] << "��" << endl;
		std::cout << "���ڸ� �Է��� �ּ��� : ";
		cin >> choice;
		system("cls");
		if (choice <= 3) {
			if (choice == 1) { //��������
				if (P1->Drugs[0] <= 0)
					std::cout << "===[���� ����]�� �����ϴ�!===" << endl;
				else {
					std::cout << "[���� ����] ���!" << endl;
					std::cout << "HP : " << P1->get_stat(5);
					P1->Drugs[0][0] --;
					if (P1->get_stat(5) + 10 > P1->get_stat(1))//����ü��+10 > ����ü�� 55 > 50
					{
						P1->full_HP();
					}
					else {
						P1->set_stat(5, 10); //stat[5] += 10
					}
					std::cout << " -> " << P1->get_stat(5) << endl;
				}
			} //if (choice == 1) ����
			else if (choice == 2) { //�Ķ� ����
				if (P1->Drugs[1][0] <= 0)
					std::cout << "===[�Ķ� ����]�� �����ϴ�!===" << endl;
				else {
					std::cout << "[�Ķ� ����] ���!" << endl;
					std::cout << "MP : " << P1->get_Current_MP();
					P1->Drugs[1][0] --;
					if (P1->get_Current_MP() + 10 > P1->get_stat(2))//����ü��+10 > ���� ���� 
					{
						P1->full_MP();
					}
					else {
						P1->set_Current_MP(10); //stat[5] += 10
					}

					std::cout << " -> " << P1->get_Current_MP() << endl;
				}
			}
			else if (choice == 3) { //������
				if (P1->Drugs[2][0] <= 0)
					std::cout << "===[������]�� �����ϴ�!===" << endl;
				else {
					std::cout << "[������] ���!" << endl;
					P1->Drugs[2][0] --;
					std::cout << "HP : " << P1->get_stat(5);
					if (P1->get_stat(5) + 10 > P1->get_stat(1))//����ü��+10 > ����ü��
					{
						P1->full_HP();
					}
					else {
						P1->set_stat(5, 100); //stat[5] += 10
					}
					std::cout << " -> " << P1->get_stat(5);
					std::cout << "/ MP : " << P1->get_Current_MP();
					if (P1->get_Current_MP() + 100 > P1->get_stat(2))//����ü��+10 > ���縶��
					{
						P1->full_MP();
					}
					else {
						P1->set_Current_MP(100); //stat[5] += 10] += 10
					}
					std::cout << " -> " << P1->get_Current_MP() << endl;
				}
			} //if (choice <= 3) ����
			break;
		}
		else {
			std::cout << "ERROR - ��Ȯ�� ���� �Է��ϼ���" << '\n' << endl;
		}
	} //while�� ����
}
void Action::show_item(Human* P1) {
	Human* player = P1;
	std::cout << "- ��� : " << player->get_money() << "G" << endl;
	if(player->Drugs[0][0] >0)
		std::cout << "- ���� ���� / " << player->Drugs[0][0] << "��" << endl;
	if (player->Drugs[1][0] > 0)
		std::cout << "- �Ķ� ���� / " << player->Drugs[1][0] << "��" << endl;
	if (player->Drugs[2][0] > 0)
		std::cout << "- ������ / " << player->Drugs[2][0] << "��" << endl;
	system("PAUSE");
	system("cls");
}
/*
stat[6] = 0 : �ִ�HP, 1 : �ִ�MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����HP
map = (1)�� (2)�縷 (3)������ ���� (4)������� (5)���ư���
*/

