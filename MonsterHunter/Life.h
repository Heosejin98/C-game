//�θ�Ŭ�������� �ڽ�Ŭ���� ȣ���ϸ� ����!! (�Ƹ� �θ� �����Ҷ� �ڽ��� ������� �ʾҴµ� ȣ���Ϸ��� �ϴ°� �����ε�?)

#pragma once
#include <string>
#ifndef __Life__H_
#define __Life__H_
using namespace std;

class Life{
protected:
	int money; //���
	int Exp; //����ġ
	double stat[6];	//0 : �ִ�HP, 1 : �ִ�MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����HP
	bool Die = false; //true = ����, false = ����
public:
	string name; //�̸�

	Life();
	void input_damage(double attack); //������ ���
	void full_HP(); //HP Ǯ ȸ��

	double get_stat(int i); //get ���� (���� �̿� ��)
	void set_Exp(int a); //set ����ġ
	int get_Exp(); //get ����ġ
	bool get_Die(); //���� ǥ��
	void set_money(int a, bool oper); //set ���
	void set_stat(int i, int b); //i = stat[i], b�� ���� ��
};
#endif