#include "item.h"
#pragma once
#ifndef __Accessory_H__
#define __Accessory_H__
#include <string>
using namespace std;

class Accessory : public item {
public:
	int power; //공격력
	int defense; //방어력

	Accessory() {};
	Accessory(string itemname, int power, int defense, int price); //tiemname : 아이템 이름, power : 공격력, defense : 방어력, price : 가격
};
#endif
