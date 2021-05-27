#include "Life.h"
#include <string>
#include <iostream>
using namespace std;

Life::Life() {
	stat[0] = 50; // 최대HP
	stat[1] = 50; // 최대MP
	stat[2] = 10; //공격력
	stat[3] = 10; //방어력
	stat[4] = 1; //레벨
	stat[5] = 50; //현재 HP

	name = "인간1";
};
double Life::get_stat(int i) {
	return stat[i];
}
void Life::input_damage(double attack) {
	stat[5] -= attack;
}
bool Life::get_Die() {
	return Die;
}
void Life::set_stat(int i, int b) {
	stat[i] = b;
}
void Life::set_money(int a) {
	money += a;
}
void Life::set_Exp(int a) {
	Exp += a;
}