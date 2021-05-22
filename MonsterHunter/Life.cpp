#include "Life.h"
#include <string>
#include <iostream>
using namespace std;



Life::Life() {
	stat[0] = 50; // 최대HP
	stat[1] = 50; // 최대MP
	stat[2] = 10; //공격력
	stat[3] = 10; //방어력
	stat[4] = 1; //레벨
	stat[5] = 50; //현재 HP
	

	name = "인간1";
};

void Die(){
	cout << "You Die";
	exit(EXIT_SUCCESS);
}