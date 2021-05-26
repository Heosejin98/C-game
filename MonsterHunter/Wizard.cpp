#include "Wizard.h"
#include <string>
#include <iostream>
using namespace std;


double Wizard::job_skill(const double stat[]) {
	int skill_num;
	cout << "[ (1)법사 임 (2)더블 샷 (3)에로우 레인 (4)파이널 샷 ]" << endl;
	cout << "숫자를 입력해 주세요 : ";
	cin >> skill_num;
	double skill_dmg = 0;
	switch (skill_num)
	{
	case 1: {
		cout << "법사 임 사용 !!" << endl;
		skill_dmg = stat[2] * 1.5;
	}
	case 2: {
		if (stat[4] == 3) {
			cout << "더블 샷 사용 !!" << endl;
			skill_dmg = stat[2] * 2;
			break;
		}
		else {
			cout << "더블 샷은 3레벨 부터 사용가능합니다!" << endl;
			break;
		}
	}
	case 3: {
		if (stat[4] == 5) {
			cout << "에로우 레인 사용 !!" << endl;
			skill_dmg = stat[2] * 3;
			break;
		}
		else {
			cout << "에로우 레인은 5레벨 부터 사용가능합니다!" << endl;
			break;
		}
	}
	case 4: {
		if (stat[4] == 10) {
			cout << "파이널 샷 사용 !!" << endl;
			skill_dmg = stat[2] * 5;
			break;
		}
		else {
			cout << "에로우 레인은 10레벨 부터 사용가능합니다!" << endl;
			break;
		}
	}
	default:
		cout << "1~4 사이의 숫자를 입력하세요" << endl;
		break;
	}
	return skill_dmg;
}