#include "Human.h"
#pragma once
#ifndef __Archer_H__
#define __Archer_H__
#include <string>
using namespace std;

class Archer : public Human {
	
public:
	Archer() {}
	Archer(string name) {}
	int Archer_skill(); //전사 스킬
};
#endif // !Wizard
