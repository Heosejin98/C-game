#include "Human.h"
#pragma once
#ifndef __Archer_H__
#define __Archer_H__
#include <string>
using namespace std;

class Archer : public Human {
	Human player;
public:
	Archer() {
		job = "�ü�";
	}
	Archer(string name) {
		this->name = name;
		job = "�ü�";
	}
	
	int Archer_skill(); //���� ��ų
};
#endif // !Wizard
