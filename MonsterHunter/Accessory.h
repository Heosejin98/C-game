#include "item.h"
#pragma once
#ifndef __Accessory_H__sin
#define __Accessory_H__
#include <string>
using namespace std;

class Accessory : public item {
public:
	int	power;
	int defense;
	Accessory() {};
	Accessory(string itemname, int power, int defense, int price) {
		this->itemname = itemname; this->power = power; this->defense = defense;
		this->price = price;
	}
};
#endif
