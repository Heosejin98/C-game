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
	cout << "********** 환영합니다 !!!  **********" << endl;
	cout << "이름을 입력하세요 :  ";
	cin >> name;
	cout << name + "님 직업을 선택하세요 (1) 전사 (2) 궁수 (3) 마법사    ";
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

	cout << name + "님의 메인화면입니다";
	cout << "(1)캐릭터 상태 확인 (2)사냥터 선택 (3)상점 (4)인벤토리 열람 (5)나가기" << endl;
	cout << "숫자를 입력해 주세요 : ";
	cin >> choice;



	
}