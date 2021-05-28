#include "Life.h"
#pragma once
#ifndef __Human_H__
#define __Human_H__
#include <string>
using namespace std;

class Human : public Life{
	int AP; //�����Ƽ ������
protected:
	float Max_Exp; //�ִ� ����ġ
	double Current_MP; //���� MP
	
	int Use_AP(int AP); //AP ����Լ�
public:
	Human();
	string job;
	int item_stat[2];
	void Open_Inventory(); //�κ��丮 ���� �Լ�
	virtual double job_skill(const double stat[]) = 0; // ������ ��ų ��� ���� �����Լ�
	const double* get_powerstat() const { return stat; }
	float Damage_Cal(); //���� ������
	double Use_item(double stat[]); //������ ���
	void Shop(); //���� ����
	void State(); //ĳ���� ���� Ȯ��
	int Set_money();
	int move_map();
	int get_money();
	void Player_Die(); //�÷��̾� ����
	void set_Current_MP(double a);
	double get_stat(int index) { return stat[index]; }
	double get_Current_MP();
	void full_MP(); //MP Ǯ ȸ��
	int get_Max_Exp();
	void Level_Up(); //���� ��
	int Drugs[3]{0, 0, 0}; //1-��������, 2-�Ķ�����, 3-������
};
#endif