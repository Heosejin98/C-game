#include <iostream>
#include "Human.h"
#include "Knight.h"
#include "Archer.h"
#include "Wizard.h"
using namespace std;

int main() {
	string name;
	cout << "ĳ���� ���� �Է��ϼ��� : ";
	cin >> name;

	int work;
	Knight Player;
	cout << "\n������ �����ϼ��� (1)���� (2)�ü� (3)���� ";
	cin >> work;
	if (work == 1)
		Knight Player(name);
	else if (work == 2)
		Archer Player(name);
	else if(work == 3)
		Wizard Player(name);

	//Human Player(name);
	cout << "�̸� : "+Player.name;

	return 0;
}