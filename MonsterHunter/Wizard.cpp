#include "Wizard.h"
#include <string>
#include <iostream>
using namespace std;


double Wizard::job_skill(const double stat[]) {
	int skill_num;
	cout << "[ (1)���� �� (2)���� �� (3)���ο� ���� (4)���̳� �� ]" << endl;
	cout << "���ڸ� �Է��� �ּ��� : ";
	cin >> skill_num;
	double skill_dmg = 0;
	switch (skill_num)
	{
	case 1: {
		cout << "���� �� ��� !!" << endl;
		skill_dmg = stat[2] * 1.5;
	}
	case 2: {
		if (stat[4] == 3) {
			cout << "���� �� ��� !!" << endl;
			skill_dmg = stat[2] * 2;
			break;
		}
		else {
			cout << "���� ���� 3���� ���� ��밡���մϴ�!" << endl;
			break;
		}
	}
	case 3: {
		if (stat[4] == 5) {
			cout << "���ο� ���� ��� !!" << endl;
			skill_dmg = stat[2] * 3;
			break;
		}
		else {
			cout << "���ο� ������ 5���� ���� ��밡���մϴ�!" << endl;
			break;
		}
	}
	case 4: {
		if (stat[4] == 10) {
			cout << "���̳� �� ��� !!" << endl;
			skill_dmg = stat[2] * 5;
			break;
		}
		else {
			cout << "���ο� ������ 10���� ���� ��밡���մϴ�!" << endl;
			break;
		}
	}
	default:
		cout << "1~4 ������ ���ڸ� �Է��ϼ���" << endl;
		break;
	}
	return skill_dmg;
}