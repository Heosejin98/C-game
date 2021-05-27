#include <windows.h>
#include "Human.h"
#include "Monster.h"
#include "Action.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Human::Human() {
	AP = 5;
	Exp = 0;
	Max_Exp = 2;
	Current_MP = 50;
	money = 0;
}
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
string Human::Open_Inventory(string inventory){
	return 0;
}
int Human::Use_AP(int AP){

	return 0;
}
float Human::Damage_Cal(int stat[]){

	float Damage;
	srand((unsigned)time(0));
	int ren = (rand() % 10);
	if (ren == 1)
		Damage = stat[2] * 1.5;
	else
		Damage = stat[2] * 1.1;

	return Damage;
}
double Human::Use_item(double stat[]){
	
	return 0;
}
void Human::Shop(){

}
int Human::Set_money(){
	return money;
}
void Human::State() {
	cout << "=====능력치=====" << endl;
	cout << "이름 : " << name << endl;
	cout << "직업 : " << job << endl;
	cout << "레벨 : " << stat[4] << endl;
	cout << "재화 : " << money << endl;
	cout << "---------------" << endl;
	cout << "경험치 : " << Exp << '/' << Max_Exp << endl; // "현재 경험치 / 최대 경험치"
	cout << "HP : " << stat[5] << '/' << stat[0] << endl; // "현재 HP / 최대 HP"
	cout << "MP : " << Current_MP << '/' << stat[0] << endl; // "현재 MP / 최대 MP"
	cout << "공격력 : " << stat[2] << endl;
	cout << "방어력 : " << stat[3] << endl;
	cout << "=============" << endl;
	system("PAUSE"); //계속하려면 아무 키나 누르십시오
	system("cls");
}
int Human::move_map() {
	system("cls");
	while (1) {
		cout << "=====지역을 선택해주세요=====" << endl;
		cout << "[ (1)숲 (2)사막 (3)버려진 도시 (4)엔드월드 (5)돌아가기 ]" << endl;
		cout << "숫자를 입력해 주세요 : ";
		int choice;
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			return choice;
			break;
		default:
			cout << "ERROR - 정확한 값을 입력하세요" << '\n' << endl;
		}
	} //while 종료
}
void Human::Player_Die() {
	cout << '\n';
	cout << "**************" << endl;
	cout << "YOU DIED" << endl;
	cout << "**************" << endl;
	Die = true;
	system("PAUSE"); //계속하려면 아무 키나 누르십시오
	exit(EXIT_SUCCESS);
}
double Human::get_Current_MP() {
	return Current_MP;
}
int Human::get_Max_Exp() {
	return Max_Exp;
}
void Human::full_MP() {
	Current_MP = stat[1];
}