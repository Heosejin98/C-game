#pragma once
#include "Human.h"
#include "Monster.h"
#include <string>
#ifndef __UI__H_
#define __UI__H_

class UI
{
public:
	static int Shop_main();
	static int Shop_Accessory(Human* P1);
	static int Shop_Drug(Human* P1);
	static int fight_main(Human* P1, Monster * M1);
};

#endif

