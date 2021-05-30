#include "Life.h"
#pragma once
#ifndef __Human_H__
#define __Human_H__
#include <string>
using namespace std;

class Human : public Life{
protected:
	float Max_Exp; //최대 경험치
	double Current_MP; //현재 MP
public:
	string job; //직업 string
	int item_stat[2]; //장신구 능력치
	int Drugs[3]{ 0, 0, 0 }; //1-빨간물약, 2-파란물약, 3-엘릭서
	string equipment = "장비없음"; //착용중인 장비

	Human();

	virtual double job_skill(const double stat[]) = 0; // 직업별 스킬 사용 순수 가상함수

	void State(); //캐릭터 상태 확인
	void Player_Die(); //플레이어 죽음
	void full_MP(); //MP 풀 회복
	void Level_Up(); //레벨 업

	int move_map(); //맵 이동
	float Damage_Cal(); //공격 데미지
	double Use_item(double stat[]); //아이템 사용

	const double* get_powerstat() const { return stat; }
	double get_stat(int index) { return stat[index]; }
	double get_Current_MP();
	void set_Current_MP(double a);
	int get_Max_Exp();
	int Set_money();
	int get_money();
};
#endif