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
#include "Accessory.h"
#include "item.h"

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
	while (1) {
		cout << '-' + name + "님 직업을 선택하세요-" << endl;
		cout << "[ (1) 전사(2) 궁수(3) 마법사 ]" << endl;
		cout << "숫자를 입력해 주세요 : ";
		cin >> job;
		system("cls");
		if (job < 4) {
			if (job == 1)
				player = new Knight(name);
			else if (job == 2)
				player = new Archer(name);
			else if (job == 3)
				player = new Wizard(name);
			break;
		}
		else
			cout << "ERROR - 정확한 값을 입력하세요" << '\n' << endl;
	}

	Show_main(name);
}

void Action::Show_main(string name) {
	int choice;
	//stat[6] = 0 : 최대HP, 1 : 최대MP, 2 : 공격력, 3 : 방어력, 4 : 레벨, 5 : 현재HP
	while (1) {
		cout << "=====" + name + "님의 메인화면입니다 =====" << endl;
		if (player->get_stat(0) != player->get_stat(5) || player->get_Current_MP() != player->get_stat(1)) { //체력 자동 회복
			player->full_HP();
			player->full_MP();
			cout << "-체력과 마나가 모두 회복되었습니다-" << '\n' << endl;
		}
		cout << "[ (1)캐릭터 상태 확인 (2)사냥터 선택 (3)상점 (4)인벤토리 열람 (5)나가기 ]" << endl;
		cout << "숫자를 입력해 주세요 : ";
		cin >> choice;
		system("cls");
		if (choice < 5) {
			switch (choice) {
			case 1:
				player->State(); //캐릭터 상태 확인
				break;
			case 2: {
				int map = player->move_map();
				Monster* M1 = new Monster(map); //int를 string으로
				fight(player, M1, map);
				break;
			}
			case 3: {
				Shop();
				break;
			}
			}
		}
		else if (choice == 5) {
			cout << "=====정상적으로 게임이 종료되었습니다=====" << endl;
			break;
		}
		else
			cout << "ERROR - 정확한 값을 입력하세요" << '\n' << endl;
	} //while 종료
}

void Action::fight(Human* P1, Monster* M1, int map) {
	double attack=0.0; //데미지
	int choice; //숫자 선택
	bool escape = false; //도망 (true = 도망, false = 실패)
	if (map == 1) {
		cout << "=====[숲]=====" << endl;
		Sleep(500); //0.5초 딜레이
		cout << M1->name << "이(가) 나타났다!" << endl;
		while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//플레이어나 몬스터가 죽을때 까지 반복
			cout << "=============" << endl;
			cout << "--[" + P1->name + "]의 HP : " << P1->get_stat(5) <<" / MP : " << P1->get_Current_MP() << " / 레벨 : " << P1->get_stat(4) << endl;
			cout << "--[" + M1->name + "]의 HP : " << M1->get_stat(5) << " / 레벨 : " << M1->get_stat(4) << endl;
			cout << "=============" << endl;
			cout << '\n';
			cout << P1->name << "의 선택은?" << endl;
			cout << "[ (1)공격 (2)스킬 (3)도망가기 ]" << endl;
			cout << "숫자를 입력해 주세요 : ";
			cin >> choice;
			cout << '\n';
			system("cls");
				switch (choice) {
				case 1: //일반 공격
					attack_fight(P1, M1, attack);
					break;

				case 2: //스킬
					skill_fight(P1, M1, attack);
					break;
				case 3:
					escape = escape_run(P1, M1, attack, escape);
					break;
				default:
					cout << "ERROR - 정확한 값을 입력하세요" << endl;
				}
		} // while문 끝

		if (M1->get_Die() == true)
			cout << "전투 승리!" << endl;
		else if (escape == true)
			cout << "=====전투에서 도망갔습니다=====" << endl;
		cout << '\n';
		system("PAUSE"); //계속하려면 아무 키나 누르십시오
		system("cls");
	}
	else if (map == 2) {
		cout << "=====[사막]=====" << endl;
		Sleep(500); //0.5초 딜레이
		cout << M1->name << "이(가) 나타났다!" << endl;
		while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//플레이어나 몬스터가 죽을때 까지 반복
			cout << "=============" << endl;
			cout << "--[" + P1->name + "]의 HP : " << P1->get_stat(5) << " / MP : " << P1->get_Current_MP() << " / 레벨 : " << P1->get_stat(4) << endl;
			cout << "--[" + M1->name + "]의 HP : " << M1->get_stat(5) << " / 레벨 : " << M1->get_stat(4) << endl;
			cout << "=============" << endl;
			cout << '\n';
			cout << P1->name << "의 선택은?" << endl;
			cout << "[ (1)공격 (2)스킬 (3)도망가기 ]" << endl;
			cout << "숫자를 입력해 주세요 : ";
			cin >> choice;
			cout << '\n';
			system("cls");
			switch (choice) {
			case 1: //일반 공격
				attack_fight(P1, M1, attack);
				break;

			case 2: //스킬
				skill_fight(P1, M1, attack);
				break;
			case 3:
				escape = escape_run(P1, M1, attack, escape);
				break;
			}
		} // while문 끝

		if (M1->get_Die() == true)
			cout << "전투 승리!" << endl;
		else if (escape == true)
			cout << "=====전투에서 도망갔습니다=====" << endl;
		cout << '\n';
		system("PAUSE"); //계속하려면 아무 키나 누르십시오
		system("cls");

	}
	else if (map == 3) {
		cout << "=====[버려진 도시]=====" << endl;
		Sleep(500); //0.5초 딜레이
		cout << M1->name << "이(가) 나타났다!" << endl;
		while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//플레이어나 몬스터가 죽을때 까지 반복
			cout << "=============" << endl;
			cout << "--[" + P1->name + "]의 HP : " << P1->get_stat(5) << " / MP : " << P1->get_Current_MP() << " / 레벨 : " << P1->get_stat(4) << endl;
			cout << "--[" + M1->name + "]의 HP : " << M1->get_stat(5) << " / 레벨 : " << M1->get_stat(4) << endl;
			cout << "=============" << endl;
			cout << '\n';
			cout << P1->name << "의 선택은?" << endl;
			cout << "[ (1)공격 (2)스킬 (3)도망가기 ]" << endl;
			cout << "숫자를 입력해 주세요 : ";
			cin >> choice;
			cout << '\n';
			system("cls");
			switch (choice) {
			case 1: //일반 공격
				attack_fight(P1, M1, attack);
				break;

			case 2: //스킬
				skill_fight(P1, M1, attack);
				break;
			case 3:
				escape = escape_run(P1, M1, attack, escape);
				break;
			}
		} // while문 끝

		if (M1->get_Die() == true)
			cout << "전투 승리!" << endl;
		else if (escape == true)
			cout << "=====전투에서 도망갔습니다=====" << endl;
		cout << '\n';
		system("PAUSE"); //계속하려면 아무 키나 누르십시오
		system("cls");

	}
	else if (map == 4) {
		cout << "=====[엔드월드]=====" << endl;
		Sleep(500); //0.5초 딜레이
		cout << M1->name << "이(가) 나타났다!" << endl;
		while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//플레이어나 몬스터가 죽을때 까지 반복
			cout << "=============" << endl;
			cout << "--[" + P1->name + "]의 HP : " << P1->get_stat(5) << " / MP : " << P1->get_Current_MP() << " / 레벨 : " << P1->get_stat(4) << endl;
			cout << "--[" + M1->name + "]의 HP : " << M1->get_stat(5) << " / 레벨 : " << M1->get_stat(4) << endl;
			cout << "=============" << endl;
			cout << '\n';
			cout << P1->name << "의 선택은?" << endl;
			cout << "[ (1)공격 (2)스킬 (3)도망가기 ]" << endl;
			cout << "숫자를 입력해 주세요 : ";
			cin >> choice;
			cout << '\n';
			system("cls");
			switch (choice) {
			case 1: //일반 공격
				attack_fight(P1, M1, attack);
				break;

			case 2: //스킬
				skill_fight(P1, M1, attack);
				break;
			case 3:
				escape = escape_run(P1, M1, attack, escape);
				break;
			}
		} // while문 끝

		if (M1->get_Die() == true)
			cout << "전투 승리!" << endl;
		else if (escape == true)
			cout << "=====전투에서 도망갔습니다=====" << endl;
		cout << '\n';
		system("PAUSE"); //계속하려면 아무 키나 누르십시오
		system("cls");
	}
}
void Action::attack_fight(Human* P1, Monster* M1, double attack) { //일반공격 함수
	double Player_attack;
	cout << P1->name + "의 공격!" << endl;
	Player_attack = P1->Damage_Cal(); //플레이어 공격
	M1->input_damage(attack); //공격 데미지 구현
	Sleep(800); //0.8초 딜레이
	cout << P1->name + "은" << Player_attack << "의 공격을 했다!" << endl;
	cout << '\n';

	if (M1->get_stat(5) <= 0) //몬스터 체력이 0 이하가 되면 몬스터 죽임
		M1->Monster_Die(P1);
	else {
		Sleep(800);
		attack = M1->get_stat(2); //몬스터 공격
		P1->input_damage(attack);
		cout << M1->name + "의 공격!" << endl;
		cout << P1->name + "은 " << M1->get_stat(2) << "의 데미지를 입었다!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //플레이어 죽음
		Sleep(800); //0.8초 딜레이
		P1->Player_Die();
	}
	Sleep(800); //0.8초 딜레이
	cout << '\n';
}
void Action::skill_fight(Human* P1, Monster* M1, double attack) { //스킬 함수
	double skill_damage;
	Sleep(500);
	skill_damage = player->job_skill(player->get_powerstat());
	M1->input_damage(skill_damage); //공격(스킬) 데미지 구현
	Sleep(800);
	cout << P1->name + "은 " << skill_damage << "의 공격을 했다!" << endl;

	if (M1->get_stat(5) <= 0) //몬스터 체력이 0 이하가 되면 몬스터 죽임
		M1->Monster_Die(P1);
	else {
		Sleep(500);
		cout << '\n';
		attack = M1->get_stat(2); //몬스터 공격
		P1->input_damage(attack);
		cout << M1->name + "의 공격!" << endl;
		Sleep(800);
		cout << P1->name + "은 " << attack << "의 데미지를 입었다!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //플레이어 죽음
		Sleep(800);
		P1->Player_Die();
	}
	cout << '\n';
}
bool Action::escape_run(Human* P1, Monster* M1, double attack, bool escape) {
	srand((unsigned)time(0)); //시간 초기화
	int i = rand() % 2 + 1; //1~5사이의 숫자 (=1/5확률)
	cout << "도망을 시도중...!" << endl;
	Sleep(800);
	system("cls");
	if (i == 2) //도망 성공
		escape = true;
	else {
		cout << "도망 실패!" << endl;
		cout << '\n';
		Sleep(800);
		attack = M1->get_stat(2); //몬스터 공격
		P1->input_damage(attack);
		cout << M1->name + "의 공격!" << endl;
		Sleep(800);
		cout << P1->name + "은" << attack << "의 데미지를 입었다!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //플레이어 죽음
		Sleep(800);
		P1->Player_Die();
	}
	return escape;
}

void Action::Shop() {
	cout << "상점입니다." << endl;
	cout << "(1) 장신구 상점 (2) 물약 상점 (3) 메인화면으로 " << endl;
	int select;
	cin >> select;
	switch (select)
		{
		case 1: // 장신구 상점 들어옴
			int accessory_buy;

			cout << "(1) 나무반지 [공격력 : +10 / 방어력 : +10 / 가격 : 1000G]" << endl;
			cout << "(2) 은반지 [공격력 : +10 / 방어력 : +50 5000G]" << endl;
			cout << "(3) 금반지 [공격력 : +50 / 방어력 : +10 5000G]" << endl;
			cout << "(4) 절대반지 [공격력 : +1024 / 방어력 : +50 100000G]" << endl;
			cout << "구매 하실 장신구를 선택하세요 !";
			cin >> accessory_buy;
			switch (accessory_buy)
			{
			
					case 1: { // 나무반지 구매 후 
						if (player->get_money() >= 1000) {
							Accessory* a = new Accessory("나무반지", 10, 10, 1000);
							player->set_money(a->price, false); // false 빼기
							player->item_stat[0] = a->power;
							player->item_stat[1] = a->defense;
							cout << "구매 성공!" << endl;
							cout << "장비 공격력 : " << player->item_stat[0] << endl;
							cout << "장비 방어력 : " << player->item_stat[0] << endl;
							break;}
						else
							cout << "재화가 부족합니다!" << endl;
						break;
					}
				
			
					case 2: { //은반지 구매 후 장착
						if (player->get_money() <= 5000) {
							player->set_money(5000, false); // false 빼기
							Accessory* a = new Accessory("은반지", 10, 50, 5000);
							player->set_money(a->price, false); // false 빼기
							player->item_stat[0] = a->power;
							player->item_stat[1] = a->defense;
							cout << "구매 성공!" << endl;
							cout << "장비 공격력 : " << player->item_stat[0] << endl;
							cout << "장비 방어력 : " << player->item_stat[0] << endl;
							break;
						}
						else
							cout << "재화가 부족합니다!";
						break;}

					case 3: {
						if (player->get_money() <= 5000) {
							player->set_money(5000, false); // false 빼기
							Accessory* a = new Accessory("은반지", 10, 50, 5000);
							player->set_money(a->price, false); // false 빼기
							player->item_stat[0] = a->power;
							player->item_stat[1] = a->defense;
							cout << "구매 성공!" << endl;
							cout << "장비 공격력 : " << player->item_stat[0] << endl;
							cout << "장비 방어력 : " << player->item_stat[0] << endl;
							break;
						}
						else
							cout << "재화가 부족합니다!";
						break;}

					case 4: {
						if (player->get_money() >= 10000) {
							Accessory* a = new Accessory("절대반지", 1024, 50, 100000);
							player->set_money(a->price, false); // false 빼기
							player->item_stat[0] = a->power;
							player->item_stat[1] = a->defense;
							cout << "구매 성공!" << endl;
							cout << "장비 공격력 : " << player->item_stat[0] << endl;
							cout << "장비 방어력 : " <<player->item_stat[0] << endl;


							break;
						}
						else
							cout << "재화가 부족합니다!";
						break;}
				
				}
				

		case 2:
		default:
		break;

		}
	system("PAUSE"); //계속하려면 아무 키나 누르십시오
	system("cls");
}


	
/*
stat[6] = 0 : 최대HP, 1 : 최대MP, 2 : 공격력, 3 : 방어력, 4 : 레벨, 5 : 현재HP
map = (1)숲 (2)사막 (3)버려진 도시 (4)엔드월드 (5)돌아가기
*/