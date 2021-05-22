#include <windows.h> //화면 지우기 사용
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
	cout << "********** 환영합니다 !!!  **********" << endl;
	cout << "이름을 입력하세요 :  ";
	cin >> name;

	system("cls"); //화면 지우기
	cout << '-' + name + "님 직업을 선택하세요-" << endl;
	cout << "[ (1) 전사(2) 궁수(3) 마법사 ]" << endl;
	cout << "숫자를 입력해 주세요 : ";
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

	cout << "=====" + name + "님의 메인화면입니다 =====" << endl;
	cout << "[ (1)캐릭터 상태 확인 (2)사냥터 선택 (3)상점 (4)인벤토리 열람 (5)나가기 ]" << endl;
	cout << "숫자를 입력해 주세요 : ";
	cin >> choice;
	system("cls");

	switch(choice)
		case 1:
			player->State(); //캐릭터 상태 확인

}