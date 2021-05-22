#include "Human.h"
#pragma once
#ifndef __Knight_H__
#define __Knight_H__
#include <string>
using namespace std;

class Knight : public Human{
public:
	Knight() {}
	Knight(string name) {}
	int Knight_skill(); //전사 스킬
};
#endif // !Human

