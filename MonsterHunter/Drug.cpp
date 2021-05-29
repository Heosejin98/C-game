#include "Drug.h"
Drug::Drug(string itemname, int plus_HP, int plus_MP, int price) {
	this->itemname = itemname;
	this->plus_HP = plus_HP;
	this->plus_MP = plus_MP;
	this->price = price;
}