#include "Human.h"
#pragma once
#ifndef __Archer_H__
#define __Archer_H__
#include <string>
using namespace std;

class Archer : public Human {
	//Human player;
public:
	Archer() {
		job = "�ü�";
	}
	Archer(string name) {
		this->name = name;
		job = "�ü�";
	}
	
	double job_skill(const double stat[], int skill_num); //���� ��ų
};
#endif // !Wizard
