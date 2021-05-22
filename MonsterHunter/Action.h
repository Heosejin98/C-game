#pragma once
#include "Human.h"

class Action{
	void Show_main(string name); //메인화면 제어
	void Exit(); //나가기
public:
	Action() {};
	void Run(); //실행 함수
};