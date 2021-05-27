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
void Human::Level_Up() { //4 : ����
	//stat[6] = 0 : �ִ�HP, 1 : �ִ�MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����HP
	Max_Exp *= 1.5; //Max Exp ����
	stat[0] *= 1.8; //�ִ� HP 1.8�� ����
	stat[1] *= 1.2; //�ִ� MP 1.2�� ����
	stat[2] *= 1.5; //���ݷ� 1.5�� ����
	stat[3] *= 1.55; //���� 1.55�� ����
	stat[4]++; //���� ����

	stat[5] = stat[0]; //������ HP�� ȸ��
	Current_MP = stat[1]; //������ MP�� ȸ��
	Exp = 0; //���� Exp 0���� �ʱ�ȭ
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
	cout << "��ȭ : " << money << endl;
	cout << "---------------" << endl;
	cout << "����ġ : " << Exp << '/' << Max_Exp << endl; // "���� ����ġ / �ִ� ����ġ"
	cout << "HP : " << stat[5] << '/' << stat[0] << endl; // "���� HP / �ִ� HP"
	cout << "MP : " << Current_MP << '/' << stat[0] << endl; // "���� MP / �ִ� MP"
	cout << "���ݷ� : " << stat[2] << endl;
	cout << "���� : " << stat[3] << endl;
	cout << "=============" << endl;
	system("PAUSE"); //����Ϸ��� �ƹ� Ű�� �����ʽÿ�
	system("cls");
}
int Human::move_map() {
	system("cls");
	while (1) {
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
			cout << "ERROR - ��Ȯ�� ���� �Է��ϼ���" << '\n' << endl;
		}
	} //while ����
}
void Human::Player_Die() {
	cout << '\n';
	cout << "**************" << endl;
	cout << "YOU DIED" << endl;
	cout << "**************" << endl;
	Die = true;
	system("PAUSE"); //����Ϸ��� �ƹ� Ű�� �����ʽÿ�
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