#pragma once
#include "Item.h"
#ifndef _DRUG_H_
#define _DRUG_H_
class Drug : public item{
public:
	int plus_HP; //물약의 HP 회복량
	int plus_MP; //물약의 MP 회복량

	Drug() {};
	Drug(string itemname, int plus_HP, int plus_MP, int price); //itemname : 아이템이름, plus_HP : HP 회복량, plus_MP : MP 회복량, price : 가격
};
#endif
