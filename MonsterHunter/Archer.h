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
		job = "±Ã¼ö";
	}
	Archer(string name) {
		this->name = name;
		job = "±Ã¼ö";
	}
	
	double job_skill(const double stat[], int skill_num); //Àü»ç ½ºÅ³
};
#endif // !Wizard
