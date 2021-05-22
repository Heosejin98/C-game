#include "Human.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Human::Human() {
	AP = 5;
	Exp = 0;
	Max_Exp = 10;
	Current_MP = 50;
	money = 9999999;
}
void Human::Level_Up() { //4 : 레벨
	stat[4]++;
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
	cout << "경험치 : " << Exp << '/' << Max_Exp << endl; // "현재 경험치 / 최대 경험치"
	cout << "HP : " << stat[5] << '/' << stat[0] << endl; // "현재 HP / 최대 HP"
	cout << "MP : " << Current_MP << '/' << stat[0] << endl; // "현재 MP / 최대 MP"
	cout << "공격력 : " << stat[2] << endl;
	cout << "방어력 : " << stat[3] << endl;
	cout << "=============" << endl;
}