#include <iostream>
#include "Human.h"
#include "Knight.h"
#include "Archer.h"
#include "Wizard.h"
using namespace std;

int main() {
	string name;
	cout << "캐릭터 명을 입력하세요 : ";
	cin >> name;

	int work;
	Knight Player;
	cout << "\n직업을 선택하세요 (1)전사 (2)궁수 (3)법사 ";
	cin >> work;
	if (work == 1)
		Knight Player(name);
	else if (work == 2)
		Archer Player(name);
	else if(work == 3)
		Wizard Player(name);

	//Human Player(name);
	cout << "이름 : "+Player.name;

	return 0;
}