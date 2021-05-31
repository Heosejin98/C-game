#include "UI.h"

#include <iostream>
using namespace std;

int UI::Shop_main() {

	std::cout << "상점주인 : 어서 와요! 꽤 보고 싶었다고요!" << '\n' << endl;
	std::cout << "[ (1)장신구 상점 (2)물약 상점 (3)나가기  ]" << endl;
	std::cout << "숫자를 입력해 주세요 : ";
	
	int select;
	std::cin >> select;

	return select;
}

int UI::Shop_Accessory(Human* P1) {

	int choice;
	std::cout << "상점주인 : 나는 항상 반지를 닦고 있지!" << '\n' << endl;
	std::cout << "골드 : " << P1->get_money() << '\n' << endl;
	std::cout << "(1) 나무반지 [공격력 : +5 / 방어력 : +5 / 가격 : 30G]" << endl;
	std::cout << "(2) 은반지 [공격력 : +10 / 방어력 : +20/ 가격 : 140G]" << endl;
	std::cout << "(3) 금반지 [공격력 : +25 / 방어력 : +15/ 가격 : 250G]" << endl;
	std::cout << "(4) 절대반지 [공격력 : +200 / 방어력 : +100/ 가격 : 400G]" << endl;
	std::cout << "------------------------------------------" << endl;
	std::cout << "숫자를 입력해 주세요 : ";
	cin >> choice;

	return choice;
}

int UI::Shop_Drug(Human* P1) {
	int choice;
	std::cout << "상점주인 : 물약은 가벼운 부작용과 함께 신체 능력을 올려주지!" << '\n' << endl;
	std::cout << "골드 : " << P1->get_money() << '\n' << endl;
	std::cout << "(1) 빨간물약 [ HP : +10 / 가격 : 15G]" << endl;
	std::cout << "(2) 파란물약 [MP : +10 / 가격 : 10G]" << endl;
	std::cout << "(3) 엘릭서 [HP : +100 / MP : +100 / 가격 : 150G]" << endl;
	std::cout << "------------------------------------------" << endl;
	std::cout << "숫자를 입력해 주세요 : ";
	cin >> choice;

	return choice;
}

int UI::fight_main(Human* P1, Monster* M1) {
	int choice;
	std::cout << "==============" << endl;
	std::cout << "--[" + P1->name + "]의 HP : " << P1->get_stat(5) << " / MP : " << P1->get_Current_MP() << " / 레벨 : " << P1->get_stat(4) << endl;
	std::cout << "--[" + M1->name + "]의 HP : " << M1->get_stat(5) << " / 레벨 : " << M1->get_stat(4) << endl;
	std::cout << "==============" << endl;
	std::cout << '\n';
	std::cout << P1->name << "의 선택은?" << endl;
	std::cout << "[ (1)공격 (2)스킬 (3) 물약 사용 (4)도망가기 ]" << endl;
	std::cout << "숫자를 입력해 주세요 : ";
	cin >> choice;
	std::cout << '\n';
	return choice;
}


