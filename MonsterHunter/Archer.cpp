#include "Archer.h"
#include <windows.h>
#include <string>
#include <iostream>
using namespace std;


double Archer::job_skill(const double stat[]) {
	int skill_num;
	double skill_dmg = 0;
	double Use_MP[] = { 10, 15, 30, 50 }; //���Ǵ� MP
	while (1) {
		cout << "- (1)���� �� / LV.1 / MP 10" << endl;
		cout << "- (2)���� ��� / LV.3 / MP 15" << endl;
		cout << "- (3)�ַο� ���� / LV.5 / MP 30" << endl;
		cout << "- (4)���̾� �� / LV.10 / MP 50" << endl;
		cout << "���ڸ� �Է��� �ּ��� : ";
		cin >> skill_num;
		cout << '\n';
		if (skill_num < 5) {
			switch (skill_num) {
			case 1: {
				if (Current_MP >= Use_MP[0]) { //MP Ȯ��
					cout << "[���� ��] ��� !" << endl;
					skill_dmg = stat[2] * 1.5;
					Current_MP -= 10; //MP ����
				}
				else
					cout << "MP�� �����մϴ�!" << endl;
				break;
			}
			case 2: {
				if (Current_MP >= Use_MP[1]) {
					if (stat[4] >= 3) {
						cout << "[���� ���]  ��� !" << endl;
						skill_dmg = stat[2] * 2;
						Current_MP -= 15;
						break;
					}
					else
						cout << "[���� ���]�� 3���� ���� ��밡���մϴ�!" << endl;
					break;
				}
				else
					cout << "MP�� �����մϴ�!" << endl;
					break;
				}
			case 3: {
				if (Current_MP >= Use_MP[2]) {
					if (stat[4] >= 5) {
						cout << "[�ַο� ����] ��� !" << endl;
						skill_dmg = stat[2] * 3;
						Current_MP -= 30;
						break;
					}
					else 
						cout << "[�ַο� ����]�� 5���� ���� ��밡���մϴ�!" << endl;
						break;
					}
				else
					cout << "MP�� �����մϴ�!" << endl;
				break;
				}
			case 4: {
				if (Current_MP >= Use_MP[3]) {
					if (stat[4] >= 10) {
						cout << "[���̾� ��] ��� !!" << endl;
						skill_dmg = stat[2] * 5;
						Current_MP -= 50;
						break;
					}
					else 
						cout << "[���̾� ��]�� 10���� ���� ��밡���մϴ�!" << endl;
						break;
					}
				else
					cout << "MP�� �����մϴ�!" << endl;
				break;
			}

			}//swhich ����
			break;
		}//if ����
		else
			cout << "ERROR - ��Ȯ�� ���� �Է��ϼ���" << '\n' << endl;
	} //while ����
	return skill_dmg;
}