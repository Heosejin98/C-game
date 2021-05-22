#include "Human.h"
#pragma once
#ifndef __Wizard_H__
#define __Wizard_H__
#include <string>
using namespace std;

class Wizard : public Human {
public:
	Wizard() { 
		job = "마법사"; 
	}
	Wizard(string name) {
		this->name = name; 
		job = "마법사"; }

	int Wizard_skill(); //전사 스킬
};
#endif // !Wizard
