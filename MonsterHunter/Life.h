//�θ�Ŭ�������� �ڽ�Ŭ���� ȣ���ϸ� ����!! (�Ƹ� �θ� �����Ҷ� �ڽ��� ������� �ʾҴµ� ȣ���Ϸ��� �ϴ°� �����ε�?)

#pragma once
#include <string>
using namespace std;
#ifndef __Life__H_
#define __Life__H_

class Life{
protected:
	double stat[6];	//0 : �ִ�HP, 1 : �ִ�MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����HP
	bool Die = false; //true = ����, false = ����
	int money; //��ȭ
	int Exp; //����ġ
public:
	string name; //�̸�
	Life();
	double get_stat(int i); //get ���� (���� �̿� ��)
	void full_HP(); //HP Ǯ ȸ��
	void set_money(int a); //set ��ȭ
	int get_Exp();
	void set_Exp(int a); //set ����ġ
	void input_damage(double attack); //������ ���
	bool get_Die();
};
#endif // !Life