#include <windows.h>
#include "Human.h"
#include "Monster.h"
#include "Action.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Human::Human() {
	Exp = 0;
	Max_Exp = 10;
	Current_MP = 30;
	money =0;
	item_stat[0] = 0;
	item_stat[1] = 0;

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
float Human::Damage_Cal(){

	float Damage;
	srand((unsigned)time(0));
	int ren = rand() % 10 + 1;
	if (ren == 1){
		std::cout << "ġ��Ÿ ! " << endl;
		Damage = (stat[2] + item_stat[0] ) * 1.5;
	}
	else
		Damage = (stat[2] + item_stat[0] ) * 1.1;

	return Damage;
}
double Human::Use_item(double stat[]){
	
	return 0;
}
int Human::Set_money(){
	return money;
}
void Human::State() {
	std::cout << "=====�ɷ�ġ=====" << endl;
	std::cout << "�̸� : " << name << endl;
	std::cout << "���� : " << job << endl;
	std::cout << "���� : " << stat[4] << endl;
	std::cout << "��� : " << money << endl;
	std::cout << "---------------" << endl;
	std::cout << "����ġ : " << Exp << '/' << Max_Exp << endl; // "���� ����ġ / �ִ� ����ġ"
	std::cout << "HP : " << stat[5] << '/' << stat[0] << endl; // "���� HP / �ִ� HP"
	std::cout << "MP : " << Current_MP << '/' << stat[0] << endl; // "���� MP / �ִ� MP"
	std::cout << "���ݷ� : " << stat[2] << endl;
	std::cout << "���� : " << stat[3] << endl;
	cout << "���� ��� : " << equipment << endl;
	cout << "��� ���ݷ� : " << item_stat[0] << endl;
	cout << "��� ���� : " << item_stat[1] << endl;
	std::cout << "=============" << endl;
	system("PAUSE"); //����Ϸ��� �ƹ� Ű�� �����ʽÿ�
	system("cls");
}
int Human::move_map() {
	system("cls");
	while (1) {
		std::cout << "=====������ �������ּ���=====" << endl;
		std::cout << "[ (1)�� (2)�縷 (3)������ ���� (4)������� (5)���ư��� ]" << endl;
		std::cout << "���ڸ� �Է��� �ּ��� : ";
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
			std::cout << "ERROR - ��Ȯ�� ���� �Է��ϼ���" << '\n' << endl;
		}
	} //while ����
}
void Human::Player_Die() {
	std::cout << '\n';
	std::cout << "**************" << endl;
	std::cout << "YOU DIED" << endl;
	std::cout << "**************" << endl;
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
int Human::get_money() {
	return money;
}
void Human::full_MP() {
	Current_MP = stat[1];
}
void Human::set_Current_MP(double a) {
	Current_MP += a;
}