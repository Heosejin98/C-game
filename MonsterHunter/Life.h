#pragma once
#include <string>
using namespace std;
#ifndef __Life__H_
#define __Life__H_

class Life{
protected:
	double stat[9];
	//0 : HP, 1 : MP, 2 : ���ݷ�, 3 : ����, 4 : ����, 5 : ����ġ, 6 : �ִ� ����ġ, 7 : ���� HP, 8 : ���� MP
public:
	string name; //�̸�

	Life();
	void Die(); //����
};
#endif // !Life