#include "Life.h"
#include <string>
#include <iostream>
using namespace std;



Life::Life() {
	stat[0] = 50; // �ִ�HP
	stat[1] = 50; // �ִ�MP
	stat[2] = 10; //���ݷ�
	stat[3] = 10; //����
	stat[4] = 1; //����
	stat[5] = 50; //���� HP
	

	name = "�ΰ�1";
};

void Die(){
	cout << "You Die";
	exit(EXIT_SUCCESS);
}