//�θ�Ŭ�������� �ڽ�Ŭ���� ȣ���ϸ� ����!! (�Ƹ� �θ� �����Ҷ� �ڽ��� ������� �ʾҴµ� ȣ���Ϸ��� �ϴ°� �����ε�?)

#pragma once
#include <string>
using namespace std;
#ifndef __Life__H_
#define __Life__H_

class Life{
protected:
	double stat[6];
	bool Die = false; //true = ����, false = ����
	//0 : �ִ�HP, 1 : �ִ�MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����HP
public:
	string name; //�̸�
	Life();
	double get_stat(int i); //get ����
	void input_damage(double attack); //������ ���
	bool get_Die();
};
#endif // !Life