#include "Action.h"
#include <windows.h> //화면 지우기 사용
#include <cstdlib> // =C의 stdlib.h
#include <ctime> //시간 헤더

#include "Life.h"
#include "Human.h"
#include "Archer.h"
#include "Knight.h"
#include "Wizard.h"
#include "Monster.h"

#include "Accessory.h"
#include "item.h"
#include "Drug.h"

#include <iostream>
using namespace std;



void Action::Run() {
	Human* player = NULL;
	string name;
	int skill;
	int job = 0;
	std::cout << "********** [EvilHunter] **********" << endl;
	std::cout << "닉네임을 입력해 주세요 :  ";
	cin >> name;

	system("cls"); //화면 지우기
	std::cout << "=====" + name + "님 환영합니다 !!!=====" << '\n' << endl;
	while (1) {
		std::cout << "=====직업을 선택하세요=====" << endl;
		std::cout << "[ (1) 전사(2) 궁수(3) 마법사 ]" << endl;
		std::cout << "숫자를 입력해 주세요 : ";
		cin >> job;
		if (job < 4) {
			if (job == 1) {
				player = new Knight(name);
				std::cout << "전사 - 선택 완료!" << '\n' << endl;
				Sleep(1000);
				system("cls");
			}
			else if (job == 2) {
				player = new Archer(name);
				std::cout << "궁수 - 선택 완료!" << '\n' << endl;
				Sleep(1000);
				system("cls");
			}
			else if (job == 3) {
				player = new Wizard(name);
				std::cout << "마법사 - 선택 완료!" << '\n' << endl;
				Sleep(1000);
				system("cls");
			}
			break;
		}
		else {
			system("cls");
			std::cout << "ERROR - 정확한 값을 입력하세요" << '\n' << endl;
		}
	}

	Show_main(player);
}
void Action::Show_main(Human* P1) {
	int choice;
	while (1) {
		Human* player = P1;
		std::cout << "=====" + player->name + "님의 메인화면입니다 =====" << '\n' << endl;
		if (player->get_stat(0) != player->get_stat(5) || player->get_Current_MP() != player->get_stat(1)) { //체력 자동 회복
			player->full_HP();
			player->full_MP();
			std::cout << "-HP와 MP가 모두 회복되었습니다-" << '\n' << endl;
		}
		std::cout << "[ (1)캐릭터 상태 확인 (2)사냥터 선택 (3)상점 (4)인벤토리 열람 (5)나가기 ]" << endl;
		std::cout << "숫자를 입력해 주세요 : ";
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
				if (map != 5)
					fight(player, M1, map);
				break;
			}
			case 3: {
				Shop(player);
				break;
			}
			case 4: {
				show_item(player);
				break;
			}
			}
		}
		else if (choice == 5) {
			std::cout << "*****정상적으로 게임이 종료되었습니다*****" << endl;
			delete P1;
			system("PAUSE");
			break;
		}
		else
			std::cout << "ERROR - 정확한 값을 입력하세요" << '\n' << endl;
		} //while 종료
	}

void Action::fight(Human* P1, Monster* M1, int map) {

	int choice; //숫자 선택
	bool escape = false; //도망 (true = 도망, false = 실패)
	if (map == 1) {
		std::cout << "=====[숲]=====" << endl;
	}
	else if (map == 2) {
		std::cout << "=====[사막]=====" << endl;
	}
	else if (map == 3) {
		std::cout << "=====[버려진 도시]=====" << endl;
	}
	else if (map == 4) {
		std::cout << "=====[엔드월드]=====" << endl;
	}
	Sleep(500); //0.5초 딜레이
	std::cout << M1->name << "이(가) 나타났다!" << endl;
	std::cout << "==============" << endl;
	while (P1->get_Die() == false && M1->get_Die() == false && escape == false) {	//플레이어나 몬스터가 죽을때 까지 반복
		system("PAUSE");
		system("cls");
		choice = UI::fight_main(P1, M1);
		system("cls");
		switch (choice) {
		case 1: //일반 공격
			attack_fight(P1, M1);
			break;
		case 2: //스킬
			skill_fight(P1, M1);
			break;
		case 3: //물약 사용
			use_Drugs(P1);
			break;
		case 4:
			escape = escape_run(P1, M1, escape);
			break;
		default:
			std::cout << "ERROR - 정확한 값을 입력하세요" << endl;
		}
	} // while문 끝

	if (M1->get_Die() == true)
		std::cout << "전투 승리!" << endl;
	else if (escape == true)
		std::cout << "=====전투에서 도망갔습니다=====" << endl;
	std::cout << '\n';
	system("PAUSE"); //계속하려면 아무 키나 누르십시오
	system("cls");
}
void Action::attack_fight(Human* P1, Monster* M1) { //일반공격 함수
	double Player_attack;
	std::cout << P1->name + "의 공격!" << endl;
	Player_attack = P1->Damage_Cal(); //플레이어 공격
	M1->input_damage(Player_attack); //공격 데미지 구현
	Sleep(800); //0.8초 딜레이
	std::cout << P1->name + "은" << Player_attack << "의 공격을 했다!" << endl;
	std::cout << '\n';

	if (M1->get_stat(5) <= 0) //몬스터 체력이 0 이하가 되면 몬스터 죽임
		M1->Monster_Die(P1, M1);
	else {
		Sleep(800);
		double attack = M1->get_stat(2); //몬스터 공격
		P1->input_damage(attack);
		std::cout << M1->name + "의 공격!" << endl;
		std::cout << P1->name + "은 " << M1->get_stat(2) << "의 데미지를 입었다!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //플레이어 죽음
		Sleep(800); //0.8초 딜레이
		P1->Player_Die(P1);
	}
	Sleep(800); //0.8초 딜레이
	std::cout << '\n';
}
void Action::skill_fight(Human* P1, Monster* M1) { //스킬 함수
	double skill_damage;
	Human* player = P1;
	Sleep(500);
	cout << "현재 레벨 : " << "LV." << player->get_stat(4) << " / MP : " << player->get_Current_MP()  << endl;
	cout << "-----------------------------" << endl;
	skill_damage = player->job_skill(player->get_powerstat());
	M1->input_damage(skill_damage); //공격(스킬) 데미지 구현
	Sleep(800);
	std::cout << P1->name + "은 " << skill_damage << "의 공격을 했다!" << endl;
	
	if (M1->get_stat(5) <= 0) //몬스터 체력이 0 이하가 되면 몬스터 죽임
		M1->Monster_Die(P1, M1);
	else {
		Sleep(500);
		std::cout << '\n';
		double attack = M1->get_stat(2); //몬스터 공격
		P1->input_damage(attack);
		std::cout << M1->name + "의 공격!" << endl;
		Sleep(800);
		std::cout << P1->name + "은 " << attack << "의 데미지를 입었다!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //플레이어 죽음
		Sleep(800);
		P1->Player_Die(P1);
	}
	std::cout << '\n';
}
bool Action::escape_run(Human* P1, Monster* M1, bool escape) {
	srand((unsigned)time(0)); //시간 초기화
	int i = rand() % 5 + 1; //1~5사이의 숫자 (=1/5확률)
	std::cout << "도망을 시도중...!" << endl;
	Sleep(800);
	system("cls");
	if (i == 5) //도망 성공
		escape = true;
	else {
		std::cout << "===도망 실패!===" << endl;
		std::cout << '\n';
		Sleep(800);
		double attack = M1->get_stat(2); //몬스터 공격
		P1->input_damage(attack);
		std::cout << M1->name + "의 공격!" << endl;
		Sleep(800);
		std::cout << P1->name + "은" << attack << "의 데미지를 입었다!" << endl;
	}
	if (P1->get_stat(5) <= 0) { //플레이어 죽음
		Sleep(800);
		P1->Player_Die(P1);
	}
	return escape;
}

void Action::Shop(Human* P1) { //상점
	Human* player = P1;
	int choice = 0;
	int select = UI::Shop_main();
	system("cls");
	switch (select){
		case 1: // 장신구 상점 들어옴
			choice = UI::Shop_Accessory(player);
			switch (choice){
					case 1: { // 나무반지 구매 후 
						if (player->get_money() >= 30) {
							Accessory* Wood = new Accessory("나무반지", 5, 5, 30);
							buy_Accessory(Wood, player);
							break;
						}
						else
							std::cout << "===골드가 부족합니다!===" << endl;
						system("PAUSE");
						break;
					}
					case 2: { //은반지 구매 후 장착
						if (player->get_money() >= 140) {
							Accessory* Silver = new Accessory("은반지", 10, 20, 140);
							buy_Accessory(Silver, player);
							break;
						}
						else
							std::cout << "===골드가 부족합니다!===" << endl;
						system("PAUSE");
						break;}
					case 3: {
						if (player->get_money() >= 250) {
							Accessory* Gold = new Accessory("금반지", 25, 15, 250);
							buy_Accessory(Gold, player);
							break;
						}
						else
							std::cout << "===골드가 부족합니다!===" << endl;
						system("PAUSE");
						break;}
					case 4: {
						if (player->get_money() >= 400) {
							Accessory* King = new Accessory("절대반지", 200, 100, 400);
							buy_Accessory(King, player);
							break;
						}
						else
							std::cout << "===골드가 부족합니다!===" << endl;
						system("PAUSE");
						break;}
				} //choice = 1 / switch 종료
			break;
		case 2: {
			int choice = UI::Shop_Drug(player);
			int cnt;
			std::cout << "구매 할 갯수를 입력하세요 주세요 : ";
			cin >> cnt;

			switch (choice) {
			case 1:
				if (player->get_money() >= 15) {
					Drug* Red = new Drug("빨간물약", 10, 0, 15);
					buy_Drug(Red, player, cnt);
					break;
				}
				else
					std::cout << "===골드가 부족합니다!===" << endl;
				system("PAUSE");
				break;
			case 2:
				if (player->get_money() >= 10) {
					Drug* Blue = new Drug("파란물약", 0, 10, 10);
					buy_Drug(Blue, player, cnt);
					break;
				}
				else
					std::cout << "===골드가 부족합니다!===" << endl;
				system("PAUSE");
				break;
			case 3:				
				if (player->get_money() >= 150) {
				Drug* Elixir = new Drug("엘릭서", 100, 100, 150);
				buy_Drug(Elixir, player, cnt);
				break;
			}
				  else
				std::cout << "===골드가 부족합니다!===" << endl;
				system("PAUSE");
				break;

			}
			break;
			} //switch (select=2) 종료

		default:
			break;
		} //switch (select) 종료
	//system("PAUSE");
	system("cls");
}
void Action::buy_Accessory(Accessory* a, Human* P1) {
	system("cls");
	Human* player = P1;
	player->set_money(a->price, false); // false 빼기
	player->item_stat[0] = a->power;
	player->item_stat[1] = a->defense;
	player->equipment = a->itemname;
	std::cout << "상점주인 : 아, 반지! 훌륭한 대화수단이지!" << '\n' << endl;
	std::cout << '['+a->itemname+']'+" 구매 성공!" << endl;
	std::cout << "장비 공격력 : " << player->item_stat[0] << endl;
	std::cout << "장비 방어력 : " << player->item_stat[0] << endl;
	system("PAUSE");
}
void Action::buy_Drug(Drug* a, Human* P1, int cnt) {
	system("cls");
	Human* player = P1;
	std::cout << "상점주인 : 코로는 마실수 없으니까 조심해!" << '\n' << endl;
	if (a->itemname == "빨간물약") {
		if(cnt==1)
			add_Drug(0, player, a);
		else
			add_Drug(0, player, a, cnt);
	}
	else if (a->itemname == "파란물약") {
		if (cnt == 1)
			add_Drug(1, player, a);
		else
			add_Drug(1, player, a, cnt);
	}
	else {
		if (cnt == 1)
			add_Drug(2, player, a);
		else
			add_Drug(1, player, a, cnt);
	}
	system("PAUSE");
}	
void  Action::add_Drug(int inven_idx, Human* P1, Drug* a) {
	Human* player = P1;
	player->set_money(a->price, false); // false 빼기
	player->Drugs[inven_idx][0]++; //물약 아이템 추가
	player->Drugs[inven_idx][1] = a->plus_HP;
	player->Drugs[inven_idx][2] = a->plus_MP;
	std::cout << "["<<a->itemname <<"] 구매 성공!" << endl;

	delete a;
}
void  Action::add_Drug(int inven_idx, Human* P1, Drug* a, int cnt) {
	Human* player = P1;
	player->set_money(a->price * cnt, false); // false 빼기
	player->Drugs[inven_idx][0] = cnt; //물약 아이템 추가
	player->Drugs[inven_idx][1] = a->plus_HP;
	player->Drugs[inven_idx][2] = a->plus_MP;
	std::cout << "[" << a->itemname << "] " << cnt <<"개 구매 성공!" << endl;
	delete a;
}

void Action::use_Drugs(Human* P1) {
	while (1) {
		int choice;
		std::cout << "(1) 빨간 물약 / "<< P1->Drugs[0][0] << "개" << endl;
		std::cout << "(2) 파란 물약 / " << P1->Drugs[1][0] << "개" << endl;
		std::cout << "(3) 엘릭서 / " << P1->Drugs[2][0] << "개" << endl;
		std::cout << "숫자를 입력해 주세요 : ";
		cin >> choice;
		system("cls");
		if (choice <= 3) {
			if (choice == 1) { //빨간물약
				if (P1->Drugs[0] <= 0)
					std::cout << "===[빨간 물약]이 없습니다!===" << endl;
				else {
					std::cout << "[빨간 물약] 사용!" << endl;
					std::cout << "HP : " << P1->get_stat(5);
					P1->Drugs[0][0] --;
					if (P1->get_stat(5) + 10 > P1->get_stat(1))//현재체력+10 > 현재체력 55 > 50
					{
						P1->full_HP();
					}
					else {
						P1->set_stat(5, 10); //stat[5] += 10
					}
					std::cout << " -> " << P1->get_stat(5) << endl;
				}
			} //if (choice == 1) 종료
			else if (choice == 2) { //파란 물약
				if (P1->Drugs[1][0] <= 0)
					std::cout << "===[파란 물약]이 없습니다!===" << endl;
				else {
					std::cout << "[파란 물약] 사용!" << endl;
					std::cout << "MP : " << P1->get_Current_MP();
					P1->Drugs[1][0] --;
					if (P1->get_Current_MP() + 10 > P1->get_stat(2))//현재체력+10 > 현재 마나 
					{
						P1->full_MP();
					}
					else {
						P1->set_Current_MP(10); //stat[5] += 10
					}

					std::cout << " -> " << P1->get_Current_MP() << endl;
				}
			}
			else if (choice == 3) { //엘릭서
				if (P1->Drugs[2][0] <= 0)
					std::cout << "===[엘릭서]가 없습니다!===" << endl;
				else {
					std::cout << "[엘릭서] 사용!" << endl;
					P1->Drugs[2][0] --;
					std::cout << "HP : " << P1->get_stat(5);
					if (P1->get_stat(5) + 10 > P1->get_stat(1))//현재체력+10 > 현재체력
					{
						P1->full_HP();
					}
					else {
						P1->set_stat(5, 100); //stat[5] += 10
					}
					std::cout << " -> " << P1->get_stat(5);
					std::cout << "/ MP : " << P1->get_Current_MP();
					if (P1->get_Current_MP() + 100 > P1->get_stat(2))//현재체력+10 > 현재마나
					{
						P1->full_MP();
					}
					else {
						P1->set_Current_MP(100); //stat[5] += 10] += 10
					}
					std::cout << " -> " << P1->get_Current_MP() << endl;
				}
			} //if (choice <= 3) 종료
			break;
		}
		else {
			std::cout << "ERROR - 정확한 값을 입력하세요" << '\n' << endl;
		}
	} //while문 종료
}
void Action::show_item(Human* P1) {
	Human* player = P1;
	std::cout << "- 골드 : " << player->get_money() << "G" << endl;
	if(player->Drugs[0][0] >0)
		std::cout << "- 빨간 물약 / " << player->Drugs[0][0] << "개" << endl;
	if (player->Drugs[1][0] > 0)
		std::cout << "- 파란 물약 / " << player->Drugs[1][0] << "개" << endl;
	if (player->Drugs[2][0] > 0)
		std::cout << "- 엘릭서 / " << player->Drugs[2][0] << "개" << endl;
	system("PAUSE");
	system("cls");
}
/*
stat[6] = 0 : 최대HP, 1 : 최대MP, 2 : 공격력, 3 : 방어력, 4 : 레벨, 5 : 현재HP
map = (1)숲 (2)사막 (3)버려진 도시 (4)엔드월드 (5)돌아가기
*/

