#pragma once
#include "Item.h"
#ifndef _DRUG_H_
#define _DRUG_H_
class Drug : public item{
public:
	int plus_HP;
	int plus_MP;
	Drug() {};
	Drug(string itemname, int plus_HP, int plus_MP, int price) {
		this->itemname = itemname; this->plus_HP = plus_HP; this->plus_MP = plus_MP;
		this->price = price;
	}
};
#endif
