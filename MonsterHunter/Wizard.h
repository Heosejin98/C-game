#include "Human.h"
#pragma once
#ifndef __Wizard_H__
#define __Wizard_H__
#include <string>
using namespace std;

class Wizard : public Human {
public:
	Wizard() { 
		job = "������"; 
	}
	Wizard(string name) {
		this->name = name; 
		job = "������"; }

	double job_skill(const double stat[]); //������ ��ų
};
#endif // !Wizard
