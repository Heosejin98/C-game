#include "Monster.h"
#include <iostream>
using namespace std;

Monster::Monster() {}
//double stat[6];
//0 : �ִ�HP, 1 : �ִ�MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����HP / �ִ� ����ġ, 7 : ���� HP, 8 : ���� MP
//stat[0] = 50; // �ִ�HP
//stat[1] = 50; // �ִ�MP
//stat[2] = 10; //���ݷ�
//stat[3] = 10; //����
//stat[4] = 1; //����
//stat[5] = 50; //���� HP

Monster::Monster(int map){
	//(1)�� (2)�縷 (3)������ ���� (4)������� (5)���ư���
	this->map = map;
	drop_money = 0;
	switch (this->map) {
	case 1:
		name = "������";
		stat[0] = 10; //�ִ� HP
		stat[1] = 10; //�ִ� MP
		stat[2] = 2; //���ݷ�
		stat[3] = 2; //����
		stat[4] = 1; //����
		stat[5] = 10; //���� HP
		break;
	case 2:
		name = "��Ʋ��";
		break;
	case 3:
		name = "������ü";
		break;
	case 4:
		name = "����Ÿ�̰�";
		break;
	}
}