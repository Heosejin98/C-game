#include "Human.h"
#pragma once
#ifndef __Knight_H__
#define __Knight_H__
#include <string>
using namespace std;

class Knight : public Human{
public:
	Knight() {
		job = "����";
	}
	Knight(string name)  {
		this->name = name;
		job = "����";
	}
	double job_skill(const double stat[]); //���� ��ų
};
#endif // !Human

