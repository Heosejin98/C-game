#include "item.h"
#pragma once
#ifndef __Accessory_H__
#define __Accessory_H__
#include <string>
using namespace std;

class Accessory : public item {
public:
	int power; //���ݷ�
	int defense; //����

	Accessory() {};
	Accessory(string itemname, int power, int defense, int price); //tiemname : ������ �̸�, power : ���ݷ�, defense : ����, price : ����
};
#endif
