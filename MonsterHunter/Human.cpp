#include "Human.h"
#include <cstdlib>
#include <ctime>

Human::Human() {}
Human::Human(string name) {
	this->name = name;
	AP = 5;
	Exp = 0;
	Max_Exp = 10;
	Current_MP = 50;
	money = 9999999;
}
void Human::Level_Up() { //4 : ·¹º§
	stat[4]++;
}
string Human::Open_Inventory(string inventory){
	return 0;
}
int Human::Use_AP(int AP){

	return 0;
}
float Human::Damage_Cal(int stat[]){

	float Damage;
	srand((unsigned)time(0));
	int ren = (rand() % 10);
	if (ren == 1)
		Damage = stat[2] * 1.5;
	else
		Damage = stat[2] * 1.1;

	return Damage;
}
double Human::Use_item(double stat[]){
	
	return 0;
}
void Human::Shop(){

}
int Human::Set_money(){
	return money;
}