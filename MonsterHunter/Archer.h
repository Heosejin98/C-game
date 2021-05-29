#pragma once
#ifndef __Archer_H__
#define __Archer_H__
#include <string>
#include "Human.h"
using namespace std;

class Archer : public Human {
public:
	Archer();
	Archer(string name);
	
	double job_skill(const double stat[]); //±Ã¼ö ½ºÅ³
};
#endif // !Wizard
