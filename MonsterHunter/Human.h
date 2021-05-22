#include "Life.h"
#pragma once
#ifndef __Human_H__
#define __Human_H__
#include <string>
using namespace std;

class Human : public Life{
	int AP; //어빌리티 포인터
	void Level_Up(); //레벨 업
protected:
	int money; //화폐
	int Exp; //경험치
	int Max_Exp; //최대 경험치
	int Current_MP; //현재 MP
	//waeapon inventory_weapon[30]; //플레이어 장비 인벤토리
	//item inventory_item[50]; // 플레이어 소비 인벤토리

	string Open_Inventory(string inventory); //인벤토리 오픈 함수
	int Use_AP(int AP); //AP 사용함수
public:
	Human();
	string job;
	float Damage_Cal(int stat[]); //공격 데미지
	double Use_item(double stat[]); //아이템 사용
	void Shop(); //상점 열람
	void State(); //캐릭터 상태 확인
	int Set_money();
};
#endif