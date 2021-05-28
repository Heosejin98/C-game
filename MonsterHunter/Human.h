#include "Life.h"
#pragma once
#ifndef __Human_H__
#define __Human_H__
#include <string>
using namespace std;

class Human : public Life{
	int AP; //어빌리티 포인터
protected:
	float Max_Exp; //최대 경험치
	double Current_MP; //현재 MP
	//waeapon inventory_weapon[30]; //플레이어 장비 인벤토리
	//item inventory_item[50]; // 플레이어 소비 인벤토리

	string Open_Inventory(string inventory); //인벤토리 오픈 함수
	int Use_AP(int AP); //AP 사용함수
public:
	Human();
	string job;
	int item_stat[2];
	virtual double job_skill(const double stat[]) = 0; // 직업별 스킬 사용 순수 가상함수
	const double* get_powerstat() const { return stat; }
	float Damage_Cal(); //공격 데미지
	double Use_item(double stat[]); //아이템 사용
	void Shop(); //상점 열람
	void State(); //캐릭터 상태 확인
	int Set_money();
	int move_map();
	int get_money();
	void Player_Die(); //플레이어 죽음
	void set_Current_MP(double a);
	double get_Current_MP();
	void full_MP(); //MP 풀 회복
	int get_Max_Exp();
	void Level_Up(); //레벨 업
	int Drugs[3]{0, 0, 0}; //1-빨간물약, 2-파란물약, 3-엘릭서
};
#endif