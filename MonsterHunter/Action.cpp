#include <windows.h> //ȭ�� ����� ���
#include "Action.h"
#include "Human.h"
#include "Archer.h"
#include "Knight.h"
#include "Wizard.h"
#include <iostream>
using namespace std;

Human * player;

void Action::Run() {
	string name;
	
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

	switch(choice)
		case 1:
			player->State(); //ĳ���� ���� Ȯ��

}