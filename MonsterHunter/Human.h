#include "Life.h"
#pragma once
#ifndef __Human_H__
#define __Human_H__
#include <string>
using namespace std;

class Human : public Life{
protected:
	float Max_Exp; //�ִ� ����ġ
	double Current_MP; //���� MP
	
public:
	string job; //���� string
	int item_stat[2]; //��ű� �ɷ�ġ
	int Drugs[3][3]{ {0, 0, 0}, { 0, 0, 0 }, {0, 0, 0} }; //1-��������, 2-�Ķ�����, 3-������
	string equipment = "������"; //�������� ���

	Human() : Max_Exp(10), Current_MP(15) {
		Exp = 0;
		money = 0;
		item_stat[0] = 0;
		item_stat[1] = 0;
		
	}
	
	virtual double job_skill(const double stat[]) = 0; // ������ ��ų ��� ���� �����Լ�

	void State(); //ĳ���� ���� Ȯ��
	void Player_Die(Human* P1); //�÷��̾� ����
	void full_MP(); //MP Ǯ ȸ��
	void Level_Up(); //���� ��
	

	bool operator!();
	int move_map(); //�� �̵�
	float Damage_Cal(); //���� ������

	const double* get_powerstat() const { return stat; }
	double get_stat(int index) { return stat[index]; }
	double get_Current_MP();
	void set_Current_MP(double a);
	int get_Max_Exp();
	
	int get_money();
};
#endif