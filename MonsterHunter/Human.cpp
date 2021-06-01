#include <windows.h>
#include "Human.h"
#include "Monster.h"
#include "Action.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;



void Human::Level_Up() { //4 : 레벨
	//stat[6] = 0 : 최대HP, 1 : 최대MP, 2 : 공격력, 3 : 방어력, 4 : 레벨, 5 : 현재HP
	Max_Exp *= 1.5; //Max Exp 증가
	stat[0] *= 1.8; //최대 HP 1.8배 증가
	stat[1] *= 1.2; //최대 MP 1.2배 증가
	stat[2] *= 1.5; //공격력 1.5배 증가
	stat[3] *= 1.55; //방어력 1.55배 증가
	stat[4]++; //레벨 증가

	stat[5] = stat[0]; //증가된 HP로 회복
	Current_MP = stat[1]; //증가된 MP로 회복
	Exp = 0; //현재 Exp 0으로 초기화
}

float Human::Damage_Cal(){

	float Damage;
	srand((unsigned)time(0));
	int ren = rand() % 10 + 1;
	if (ren == 1){
		std::cout << "치명타 ! " << endl;
		Damage = (stat[2] + item_stat[0] ) * 1.5;
	}
	else
		Damage = (stat[2] + item_stat[0] ) * 1.1;

	return Damage;
}


void Human::State() {
	std::cout << "=====능력치=====" << endl;
	std::cout << "이름 : " << name << endl;
	std::cout << "직업 : " << job << endl;
	std::cout << "레벨 : " << stat[4] << endl;
	std::cout << "골드 : " << money << endl;
	std::cout << "---------------" << endl;
	std::cout << "경험치 : " << Exp << '/' << Max_Exp << endl; // "현재 경험치 / 최대 경험치"
	std::cout << "HP : " << stat[5] << '/' << stat[0] << endl; // "현재 HP / 최대 HP"
	std::cout << "MP : " << Current_MP << '/' << stat[1] << endl; // "현재 MP / 최대 MP"
	std::cout << "공격력 : " << stat[2] << endl;
	std::cout << "방어력 : " << stat[3] << endl;
	cout << "착용 장비 : " << equipment << endl;
	cout << "장비 공격력 : " << item_stat[0] << endl;
	cout << "장비 방어력 : " << item_stat[1] << endl;
	std::cout << "=============" << endl;
	system("PAUSE"); //계속하려면 아무 키나 누르십시오
	system("cls");
}
int Human::move_map() {
	system("cls");
	while (1) {
		std::cout << "=====지역을 선택해주세요=====" << endl;
		std::cout << "[ (1)숲 (2)사막 (3)버려진 도시 (4)엔드월드 (5)돌아가기 ]" << endl;
		std::cout << "숫자를 입력해 주세요 : ";
		int choice;
		cin >> choice;
		system("cls");
		if (5 >= choice && choice > 0) {
			return choice;
			break;
		}
		else
		{
			std::cout << "ERROR - 정확한 값을 입력하세요" << '\n' << endl;
		}
			
		}
	} //while 종료
void Human::Player_Die(Human* P1) {
	std::cout << '\n';
	std::cout << "**************" << endl;
	std::cout << "YOU DIED" << endl;
	std::cout << "**************" << endl;
	Die = true;
	delete P1;
	system("PAUSE"); //계속하려면 아무 키나 누르십시오
	exit(EXIT_SUCCESS);
}
double Human::get_Current_MP() {
	return Current_MP;
}
int Human::get_Max_Exp() {
	return Max_Exp;
}
int Human::get_money() {
	return money;
}
void Human::full_MP() {
	Current_MP = stat[1];
}
void Human::set_Current_MP(double a) {
	Current_MP += a;
}
bool Human::operator!() {
	if (stat[5] <= 0) return true;
	else return false;
};