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
	Knight(string name) 
		 {
		job = "����";
	}
	int Knight_skill(); //���� ��ų
};
#endif // !Human

