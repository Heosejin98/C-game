#include "Action.h"
#include "Human.h"
#include "Archer.h"
#include "Knight.h"
#include "Wizard.h"
#include <iostream>
using namespace std;

void Action::Run() {
	string name;
	Human player;
	int job = 0;
	cout << "********** ȯ���մϴ� !!!  **********" << endl;
	cout << "�̸��� �Է��ϼ��� :  ";
	cin >> name;
	cout << name + "�� ������ �����ϼ��� (1) ���� (2) �ü� (3) ������    ";
	cin >> job;
	if (job == 1)
		player = Knight(name);
	else if (job == 2)
		player = Archer(name);
	else if (job == 3)
		player = Wizard(name);

	Show_main(name);

}


void Action::Show_main(string name) {
	int choice;

	cout << name + "���� ����ȭ���Դϴ�";
	cout << "(1)ĳ���� ���� Ȯ�� (2)����� ���� (3)���� (4)�κ��丮 ���� (5)������" << endl;
	cout << "���ڸ� �Է��� �ּ��� : ";
	cin >> choice;



	
}