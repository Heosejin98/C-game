#include "Life.h"
#pragma once
#ifndef __Human_H__
#define __Human_H__
#include <string>
using namespace std;

class Human : public Life{
	int AP; //�����Ƽ ������
	void Level_Up(); //���� ��
protected:
	int money; //ȭ��
	int Exp; //����ġ
	int Max_Exp; //�ִ� ����ġ
	int Current_MP; //���� MP
	//waeapon inventory_weapon[30]; //�÷��̾� ��� �κ��丮
	//item inventory_item[50]; // �÷��̾� �Һ� �κ��丮

	string Open_Inventory(string inventory); //�κ��丮 ���� �Լ�
	int Use_AP(int AP); //AP ����Լ�
public:
	Human();
	string job;
	float Damage_Cal(int stat[]); //���� ������
	double Use_item(double stat[]); //������ ���
	void Shop(); //���� ����
	void State(); //ĳ���� ���� Ȯ��
	int Set_money();
};
#endif