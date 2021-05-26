#include <windows.h> //화면 지우기 사용
#include <cstdlib> // =C의 stdlib.h
#include <ctime> //시간 헤더
#include "Action.h"
#include "Human.h"
#include "Monster.h"
#include "Archer.h"
#include "Knight.h"
#include "Wizard.h"
#include <iostream>
#include "Life.h"
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
	double attack; //데미지
	int choice; //숫자 선택
	bool escape = false; //도망 (true = 도망, false = 실패)
	//stat[6] = 0 : 최대HP, 1 : 최대MP, 2 : 공격력, 3 : 방어력, 4 : 레벨, 5 : 현재HP
	if (map == 1) {
		cout << "=====[숲]=====" << endl;
		cout << M1->name << "이(가) 나타났다!" << endl;
		cout << "=============" << endl;
		while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//플레이어나 몬스터가 죽을때 까지 반복
			cout << "--[" + P1->name + "]의 체력 : " << P1->get_stat(5) << endl;
			cout << "--[" + M1->name + "]의 체력 : " << M1->get_stat(5) << endl;
			cout << '\n';
			cout << P1->name << "의 선택은?" << endl;
			cout << "[ (1)공격 (2)스킬 (3)도망가기 ]" << endl;
			cout << "숫자를 입력해 주세요 : ";
			cin >> choice;
			cout << '\n';
			system("cls");

				switch (choice) {
				case 1: //일반 공격
					cout << P1->name + "의 공격!" << endl;
					attack = P1->get_stat(2);
					M1->input_damage(attack); //공격 데미지 구현

					if (M1->get_stat(5) <= 0) //몬스터 체력이 0 이하가 되면 몬스터 죽임
						M1->Monster_Die();
					break;
				case 2: //스킬
					cout << P1->name + " 턴의 스킬 사용!" << endl;
					attack = player->job_skill(player->get_powerstat());
					M1->input_damage(attack); //공격(스킬) 데미지 구현

					if (M1->get_stat(5) <= 0)
						M1->Monster_Die();
					break;
				case 3:
					srand((unsigned)time(0)); //시간 초기화
					int i = rand() % 5 + 1; //1~5사이의 숫자 (=1/5확률)
					cout << i << endl;
					if (i == 5) //도망 성공
						escape = true;
					else
						cout << "도망 실패!" << endl;
					break;
				}
		} // while문 끝
		if (M1->get_Die() == true)
			cout << "전투 승리!" << endl;
		else if (escape == true)
			cout << "전투에서 도망갔습니다" << endl;
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
/*
stat[6] = 0 : 최대HP, 1 : 최대MP, 2 : 공격력, 3 : 방어력, 4 : 레벨, 5 : 현재HP
map = (1)숲 (2)사막 (3)버려진 도시 (4)엔드월드 (5)돌아가기
*/