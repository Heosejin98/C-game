#include "Archer.h"
#include <windows.h>
#include <string>
#include <iostream>
Archer::Archer() {
	job = "궁수";
}
Archer::Archer(string name) {
	this->name = name;
	job = "궁수";
}

double Archer::job_skill(const double stat[]) {
	int skill_num;
	double skill_dmg = 0;
	double Use_MP[] = { 10, 15, 30, 50 }; //사용되는 MP
	while (1) {
		std::cout << "- (1)더블 샷 / LV.1 / MP 10" << endl;
		std::cout << "- (2)고정 사격 / LV.3 / MP 15" << endl;
		std::cout << "- (3)애로우 레인 / LV.5 / MP 30" << endl;
		std::cout << "- (4)파이어 샷 / LV.10 / MP 50" << endl;
		std::cout << "숫자를 입력해 주세요 : ";
		cin >> skill_num;
		std::cout << '\n';
		if (skill_num < 5) {
			switch (skill_num) {
			case 1: {
				if (Current_MP >= Use_MP[0]) { //MP 확인
					std::cout << "[더블 샷] 사용 !" << endl;
					skill_dmg = (stat[2] + item_stat[0]) * 1.5;
					Current_MP -= 10; //MP 감소
				}
				else
					std::cout << "===MP가 부족합니다!===" << '\n' << endl;
				break;
			}
			case 2: {
				if (Current_MP >= Use_MP[1]) {
					if (stat[4] >= 3) {
						std::cout << "[고정 사격]  사용 !" << endl;
						skill_dmg = (stat[2] + item_stat[0]) * 2;
						Current_MP -= 15;
						break;
					}
					else
						std::cout << "[고정 사격]은 3레벨 부터 사용가능합니다!===" << '\n' << endl;
					break;
				}
				else
					std::cout << "===MP가 부족합니다!===" << '\n' << endl;
					break;
				}
			case 3: {
				if (Current_MP >= Use_MP[2]) {
					if (stat[4] >= 5) {
						std::cout << "[애로우 레인] 사용 !" << '\n' << endl;
						skill_dmg = (stat[2] + item_stat[0]) * 3;
						Current_MP -= 30;
						break;
					}
					else 
						std::cout << "===[애로우 레인]은 5레벨 부터 사용가능합니다!===" << '\n' << endl;
						break;
					}
				else
					std::cout << "===MP가 부족합니다!===" << '\n' << endl;
				break;
				}
			case 4: {
				if (Current_MP >= Use_MP[3]) {
					if (stat[4] >= 10) {
						std::cout << "[파이어 샷] 사용 !!" << endl;
						skill_dmg = (stat[2] + item_stat[0]) * 5;
						Current_MP -= 50;
						break;
					}
					else 
						std::cout << "===[파이어 샷]은 10레벨 부터 사용가능합니다!===" << '\n' << endl;
						break;
					}
				else
					std::cout << "===MP가 부족합니다!===" << '\n' << endl;
				break;
			}

			}//swhich 종료
			break;
		}//if 종료
		else
			std::cout << "ERROR - 정확한 값을 입력하세요" << '\n' << endl;
	} //while 종료
	return skill_dmg;
}