#pragma once
#include "Item.h"
#ifndef _DRUG_H_
#define _DRUG_H_
class Drug : public item{
public:
	int plus_HP; //������ HP ȸ����
	int plus_MP; //������ MP ȸ����

	Drug() {};
	Drug(string itemname, int plus_HP, int plus_MP, int price); //itemname : �������̸�, plus_HP : HP ȸ����, plus_MP : MP ȸ����, price : ����
};
#endif
