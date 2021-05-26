#include <windows.h> //화면 지우기 사용
#include "Action.h"
#include "Human.h"
#include "Monster.h"
#include "Archer.h"
#include "Knight.h"
#include "Wizard.h"
#include <iostream>
using namespace std;

Human * player;

void Action::Run() {
	string name;
	int skill;
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

	switch (choice) {
	case 1:
		player->State(); //캐릭터 상태 확인
		break;
	case 2:
		int map = player->move_map();
		Monster* M1 = new Monster(map); //int를 string으로
		fight(player, M1, map);
		break;
	}
}

void Action::fight(Human* P1, Monster* M1, int map) {
	int choice;
	if (map == 1) {
		cout << "=====[숲]=====" << endl;
		cout << M1->name << "이(가) 나타났다!" << endl;
		cout << "=============" << endl;
		cout << P1->name << "의 선택은?" << endl;
		cout << "[ (1)공격 (2)스킬 (3)도망가기 ]" << endl;
		cout << "숫자를 입력해 주세요 : ";
		cin >> choice;
		cout << '\n';
		switch (choice) {
		case 1:
			break;
		case 2:
			cout << P1->name + " 턴의 스킬 사용!" << endl;
			double skill_damage = player->job_skill(player->get_powerstat());
			cout << "스킬사용" << skill_damage << endl;
		}
	}
	else if (map == 2) {
		cout << "=====[사막]=====" << endl;
		cout << M1->name << "이(가) 나타났다!" << endl;
		cout << "=============" << endl;
		cout << "당신의 선택은?" << endl;
		cout << "[ (1)공격 (2)스킬 (3)도망가기 ]" << endl;
		cout << "숫자를 입력해 주세요 : ";
		cin >> choice;
	}
	else if (map == 3) {
		cout << "=====[버려진 도시]=====" << endl;
		cout << M1->name << "이(가) 나타났다!" << endl;
		cout << "=============" << endl;
		cout << "당신의 선택은?" << endl;
		cout << "[ (1)공격 (2)스킬 (3)도망가기 ]" << endl;
		cout << "숫자를 입력해 주세요 : ";
		cin >> choice;
	}
	else if (map == 4) {
		cout << "=====[엔드월드]=====" << endl;
		cout << M1->name << "이(가) 나타났다!" << endl;
		cout << "=============" << endl;
		cout << "당신의 선택은?" << endl;
		cout << "[ (1)공격 (2)스킬 (3)도망가기 ]" << endl;
		cout << "숫자를 입력해 주세요 : ";
		cin >> choice;
	}
}