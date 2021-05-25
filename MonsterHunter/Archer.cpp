#include "Archer.h"
#include <string>
#include <iostream>
using namespace std;


double Archer::job_skill(const double stat[], int skill_num) {
	double skill_dmg = 0;
	switch (skill_num)
	{
	case 1: {
		cout << "더블 샷 사용 !!" << endl;
		skill_dmg = stat[2] * 1.5;
		break;
	}
	case 2: {
		if (stat[4] >= 3) {
			cout << "애로우 레인  사용 !! 111111" << endl;
			skill_dmg = stat[2] * 2;
			break;
		}
		else {
			cout << "애로우 레인은 3레벨 부터 사용가능합니다!" << endl;
			break;
		}
	}
	case 3: {
		if (stat[4] >= 5) {
			cout << "파이어 샷 사용 !!" << endl;
			skill_dmg = stat[2] * 3;
			break;
		}
		else {
			cout << "파이어 샷은 5레벨 부터 사용가능합니다!" << endl;
			break;
		}
	}
	case 4: {
		if (stat[4] >= 10) {
			cout << "파이널 샷 사용 !!" << endl;
			skill_dmg = stat[2] * 5;
			break;
		}
		else {
			cout << "파이널 샷은 10레벨 부터 사용가능합니다!" << endl;
			break;
		}
	}
	default:
		cout << "1~4 사이의 숫자를 입력하세요" << endl;
		break;
	}
	return skill_dmg;
}