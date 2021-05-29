#include "Human.h"
#pragma once
#ifndef __Knight_H__
#define __Knight_H__
#include <string>
using namespace std;

class Knight : public Human{
public:
	Knight();
	Knight(string name);

	double job_skill(const double stat[]); //전사 스킬
};
#endif // !Human

