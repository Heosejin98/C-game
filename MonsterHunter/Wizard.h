#include "Human.h"
#pragma once
#ifndef __Wizard_H__
#define __Wizard_H__
#include <string>
using namespace std;

class Wizard : public Human {
public:
	Wizard() {}
	Wizard(string name) {}
	int Wizard_skill(); //���� ��ų
};
#endif // !Wizard
