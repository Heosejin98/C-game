#include "Human.h"
#pragma once
#ifndef __Knight_H__
#define __Knight_H__
#include <string>
using namespace std;

class Knight : public Human{
public:
	Knight() {
		job = "전사";
	}
	Knight(string name) 
		 {
		job = "전사";
	}
	int Knight_skill(); //전사 스킬
};
#endif // !Human

