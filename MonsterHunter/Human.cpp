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
	Max_Exp = 10;
	Current_MP = 50;
	money = 9999999;
}
void Human::Level_Up() { //4 : ����
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
	cout << "=====�ɷ�ġ=====" << endl;
	cout << "�̸� : " << name << endl;
	cout << "���� : " << job << endl;
	cout << "���� : " << stat[4] << endl;
	cout << "����ġ : " << Exp << '/' << Max_Exp << endl; // "���� ����ġ / �ִ� ����ġ"
	cout << "HP : " << stat[5] << '/' << stat[0] << endl; // "���� HP / �ִ� HP"
	cout << "MP : " << Current_MP << '/' << stat[0] << endl; // "���� MP / �ִ� MP"
	cout << "���ݷ� : " << stat[2] << endl;
	cout << "���� : " << stat[3] << endl;
	cout << "=============" << endl;
}
int Human::move_map() {
	system("cls");
	cout << "=====������ �������ּ���=====" << endl;
	cout << "[ (1)�� (2)�縷 (3)������ ���� (4)������� (5)���ư��� ]" << endl;
	cout << "���ڸ� �Է��� �ּ��� : ";
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
		cout << "��Ȯ�� ���� �Է��ϼ���" << endl;
	}
}